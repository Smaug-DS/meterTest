//
// Created by smaug on 03.09.22.
//

#include "calcCRC.h"
#include "selectCom.h"
#include "parsJSON.h"
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <boost/chrono.hpp>
#include <thread>
#include <chrono>

#ifndef METERTEST_SERVER_H
#define METERTEST_SERVER_H


class server
{
public:

    typedef boost::shared_ptr<boost::asio::ip::tcp::socket> socket_ptr;

    static void print(std::vector<std::byte>);

    static void print(std::vector<std::string>);

    static void multithread_start(socket_ptr);

    static void start(int);
};


#endif //METERTEST_SERVER_H
