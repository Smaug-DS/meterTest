//
// Created by smaug on 03.09.22.
//

#include "server.h"


std::ostream& operator<< (std::ostream& os, std::byte b)
{
    return os << std::bitset<8>(std::to_integer<int>(b));
}

using namespace std::chrono_literals;
using boost::asio::ip::tcp;

void server::print(std::vector<std::byte> v1)
{
    for(auto c:v1) {
        std::cout << c << '\t';
    }
    std::cout << std::endl;
}

void server::print(std::vector<std::string> v1)
{
    for(auto c:v1) {
        std::cout << c << '\t';
    }
    std::cout << std::endl;
}

// starting socket and send command
void server::multithread_start(server::socket_ptr sckt)
{

    bool milur = false;
    int tmp =0;

    calcCRC clCRC;
    selectCom sC;
    parsJSON pj;


    std::string path = "/home/smaug/projects/mer1/data.json";

    std::cout <<"Client connected! Sending message on port "<< std::this_thread::get_id() <<"!\n";

    std::string hello_message = "Hello, beautiful client!\n";
    boost::system::error_code error;

    std::this_thread::sleep_for(200ms);

    while(sckt->is_open())
    {

        std::vector<std::pair<std::string, std::vector<std::string>>> vecJPars = pj.parserJs(path);

        std::this_thread::sleep_for(100ms);

        std::size_t bytes = sckt->available();

        std::vector<std::byte> vBuffer_in(bytes);


        sckt->read_some(boost::asio::buffer(vBuffer_in.data(), vBuffer_in.size()), error);

        std::vector<std::string> checkBuf (bytes);

        if(milur && tmp != 1)
        {

            bytes = 4;

            checkBuf.emplace_back("00");
            checkBuf.emplace_back("00");
            checkBuf.emplace_back("00");
            checkBuf.emplace_back("00");


            ++tmp;
        }

        int i =0;
        for(auto v: vBuffer_in)
        {
            std::stringstream ss;
            ss << v;
            std::string ts = clCRC.Bin2Hex(ss.str());
            checkBuf[i] = ts;
            i++;
        }

        auto start = std::chrono::steady_clock::now();
        auto end = std::chrono::steady_clock::now();

        if (bytes == 0)
        {
            end = std::chrono::steady_clock::now();
            std::chrono::duration<double> diff = end - start;
            if (diff.count() > 120)
            {
                sckt->close();
                std::cout << "socket closed\n";
            }
            continue;
        }
        else
        {
            std::cout << "Bytes available: " << bytes << std::endl;
            server::print(checkBuf);
            start = std::chrono::steady_clock::now();

        }



        std::vector<std::string> vBuffer_tmp = sC.selC(checkBuf, vecJPars);

        if (vBuffer_tmp.empty()){ continue;}

        std::vector<std::string> vBuffer_out_s = clCRC.BufSend_out(vBuffer_tmp);

        std::vector<std::byte> vBuffer_out;

        for(auto v : vBuffer_out_s)
        {
            unsigned int a =clCRC.Bin2Dec_i(clCRC.Hex2Bin(v));
            vBuffer_out.push_back((std::byte)a);
        }

        std::this_thread::sleep_for(100ms);

        sckt->write_some(boost::asio::buffer(vBuffer_out.data(), vBuffer_out.size()), error);

        if (checkBuf[1] == "2" && checkBuf.size() == 2)
        {
            sckt->close();
        }
    }

}

// start server socket and open tcp connection
void server::start(int port)
{

    try
    {
        boost::asio::io_context io_context;

        std::cout << "Accepting connections on port " << port << "!\n";

        tcp::acceptor a(io_context, tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), port));
        for (;;)
        {
            server::socket_ptr sock(new tcp::socket(io_context));
            a.accept(*sock);
            boost::thread t(boost::bind(server::multithread_start, sock));
        }

    }
    catch(std::exception& e){ std::cerr << e.what() << std::endl;}
}


