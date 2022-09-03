//
// Created by root on 7/15/22.
//

#include "calcCRC.h"

std::string calcCRC::Hex2Bin(const std::string &s) {
    std::string out;
    for(auto i: s){
        uint8_t n;
        if(i <= '9' and i >= '0')
            n = i - '0';
        else
            n = 10 + i - 'A';
        for(int8_t j = 3; j >= 0; --j)
            out.push_back((n & (1<<j))? '1':'0');
    }

    return out;
}

std::string calcCRC::Bin2Hex(const std::string &s) {
    std::bitset<8> set(s);
    std::stringstream ss;
    ss << std::hex << set.to_ulong();
    return boost::to_upper_copy(ss.str());
}
std::string calcCRC::Bin2Hex_32(const std::string &s) {
    std::bitset<32> set(s);
    std::stringstream ss;
    ss << std::hex << set.to_ulong();
    return boost::to_upper_copy(ss.str());
}

unsigned int calcCRC::Bin2Dec_i(const std::string &s) {
    std::bitset<32> bs(s);
    unsigned n = bs.to_ulong();
    std::stringstream ss;
    ss << std::dec << n;
    unsigned int d;
    ss >> d;
    return d;
}

std::string calcCRC::Bin2Dec_s(const std::string &s) {
    std::bitset<32> bs(s);
    unsigned n = bs.to_ulong();
    std::stringstream ss;
    ss << std::dec << n;
    return ss.str();
}

unsigned int calcCRC::Dec2Bin_i(const std::string &s) {
    int num = stoi(s);
    std::string binary = std::bitset<8>(num).to_string();
    return stoi(binary);
}

std::string calcCRC::Dec2Bin_s(const std::string &s) {
    int num = stoi(s);
    std::string binary = std::bitset<8>(num).to_string();
    std::stringstream ss;
    ss << binary;
    return ss.str();
}

std::string calcCRC::Dec2Bin_s_32(const std::string &s) {
    int num = stoi(s);
    std::string binary = std::bitset<32>(num).to_string();
    std::stringstream ss;
    ss << binary;
    return ss.str();
}

std::string calcCRC::UpdCRC(std::string &C, std::string &oldCRC) {
    std::vector<std::string> srCRCHi {"00", "C1", "81", "40", "01", "C0", "80", "41", "01", "C0", "80", "41", "00", "C1", "81", "40", "01", "C0", "80", "41", "00", "C1", "81", "40", "00", "C1", "81", "40", "01", "C0", "80", "41", "01", "C0", "80", "41", "00", "C1", "81", "40","00", "C1", "81", "40", "01", "C0", "80", "41", "00", "C1", "81", "40", "01", "C0", "80", "41", "01", "C0", "80", "41","00", "C1", "81", "40", "01", "C0", "80", "41", "00", "C1", "81", "40", "00", "C1", "81", "40", "01", "C0", "80", "41","00", "C1", "81", "40", "01", "C0", "80", "41", "01", "C0", "80", "41", "00", "C1", "81", "40", "00", "C1", "81", "40","01", "C0", "80", "41", "01", "C0", "80", "41", "00", "C1", "81", "40", "01", "C0", "80", "41", "00", "C1", "81", "40","00", "C1", "81", "40", "01", "C0", "80", "41", "01", "C0", "80", "41", "00", "C1", "81", "40", "00", "C1", "81", "40","01", "C0", "80", "41", "00", "C1", "81", "40", "01", "C0", "80", "41", "01", "C0", "80", "41", "00", "C1", "81", "40","00", "C1", "81", "40", "01", "C0", "80", "41", "01", "C0", "80", "41", "00", "C1", "81", "40", "01", "C0", "80", "41","00", "C1", "81", "40", "00", "C1", "81", "40", "01", "C0", "80", "41", "00", "C1", "81", "40", "01", "C0", "80", "41","01", "C0", "80", "41", "00", "C1", "81", "40", "01", "C0", "80", "41", "00", "C1", "81", "40", "00", "C1", "81", "40","01", "C0", "80", "41", "01", "C0", "80", "41", "00", "C1", "81", "40", "00", "C1", "81", "40", "01", "C0", "80", "41","00", "C1", "81", "40", "01", "C0", "80", "41", "01", "C0", "80", "41", "00", "C1", "81", "40"};
    std::vector<std::string> srCRCLo {"00", "C0", "C1", "01", "C3", "03", "02", "C2", "C6", "06", "07", "C7", "05", "C5", "C4", "04", "CC", "0C", "0D", "CD","0F", "CF", "CE", "0E", "0A", "CA", "CB", "0B", "C9", "09", "08", "C8", "D8", "18", "19", "D9", "1B", "DB", "DA", "1A","1E", "DE", "DF", "1F", "DD", "1D", "1C", "DC", "14", "D4", "D5", "15", "D7", "17", "16", "D6", "D2", "12","13", "D3","11", "D1", "D0", "10", "F0", "30", "31", "F1", "33", "F3", "F2", "32", "36", "F6", "F7", "37", "F5", "35", "34", "F4","3C", "FC", "FD", "3D", "FF", "3F", "3E", "FE", "FA", "3A", "3B", "FB", "39", "F9", "F8", "38", "28", "E8", "E9", "29","EB", "2B", "2A", "EA", "EE", "2E", "2F", "EF", "2D", "ED", "EC", "2C", "E4", "24", "25", "E5", "27", "E7", "E6", "26","22", "E2", "E3", "23", "E1", "21", "20", "E0", "A0", "60", "61", "A1", "63", "A3", "A2", "62", "66", "A6", "A7", "67","A5", "65", "64", "A4", "6C", "AC", "AD", "6D", "AF", "6F", "6E", "AE", "AA", "6A", "6B", "AB", "69", "A9", "A8", "68","78", "B8", "B9", "79", "BB", "7B", "7A", "BA", "BE", "7E", "7F", "BF", "7D", "BD", "BC", "7C", "B4", "74", "75", "B5","77", "B7", "B6", "76", "72", "B2", "B3", "73", "B1", "71", "70", "B0", "50", "90", "91", "51", "93", "53", "52", "92","96", "56", "57", "97", "55", "95", "94", "54", "9C", "5C", "5D", "9D", "5F", "9F", "9E", "5E", "5A", "9A", "9B", "5B","99", "59", "58", "98", "88", "48", "49", "89", "4B", "8B", "8A", "4A", "4E", "8E", "8F", "4F", "8D", "4D", "4C", "8C","44", "84", "85", "45", "87", "47", "46", "86", "82", "42", "43", "83", "41", "81", "80", "40"};

    std::vector<std::string> arrCRC (2);
    std::stringstream ss1;
    std::stringstream ss2;
    ss1 << oldCRC[0] << oldCRC[1];
    ss2 << oldCRC[2] << oldCRC[3];
    arrCRC[0] = Hex2Bin(ss1.str());
    arrCRC[1] = Hex2Bin(ss2.str());

    unsigned int i = Bin2Dec_i(arrCRC[1]) ^ Bin2Dec_i(Hex2Bin(C));

    unsigned int i_arrCRC = Bin2Dec_i(arrCRC[0]) ^ Bin2Dec_i(Hex2Bin(srCRCHi[i]));
    std::stringstream s_arrCRC;
    s_arrCRC << i_arrCRC;
    arrCRC[1] = Bin2Hex(Dec2Bin_s(s_arrCRC.str()));

    if (arrCRC[1] == "0"){
        arrCRC[1] = "0" + arrCRC[1];
    }
    if (arrCRC[1] == "1"){
        arrCRC[1] = "0" + arrCRC[1];
    }
    if (arrCRC[1] == "2"){
        arrCRC[1] = "0" + arrCRC[1];
    }
    if (arrCRC[1] == "3"){
        arrCRC[1] = "0" + arrCRC[1];
    }
    if (arrCRC[1] == "4"){
        arrCRC[1] = "0" + arrCRC[1];
    }
    if (arrCRC[1] == "5"){
        arrCRC[1] = "0" + arrCRC[1];
    }
    if (arrCRC[1] == "6"){
        arrCRC[1] = "0" + arrCRC[1];
    }
    if (arrCRC[1] == "7"){
        arrCRC[1] = "0" + arrCRC[1];
    }
    if (arrCRC[1] == "8"){
        arrCRC[1] = "0" + arrCRC[1];
    }
    if (arrCRC[1] == "9"){
        arrCRC[1] = "0" + arrCRC[1];
    }
    if (arrCRC[1] == "A"){
        arrCRC[1] = "0" + arrCRC[1];
    }
    if (arrCRC[1] == "B"){
        arrCRC[1] = "0" + arrCRC[1];
    }
    if (arrCRC[1] == "C"){
        arrCRC[1] = "0" + arrCRC[1];
    }
    if (arrCRC[1] == "D"){
        arrCRC[1] = "0" + arrCRC[1];
    }
    if (arrCRC[1] == "E"){
        arrCRC[1] = "0" + arrCRC[1];
    }
    if (arrCRC[1] == "F"){
        arrCRC[1] = "0" + arrCRC[1];
    }


    arrCRC[0] = srCRCLo[i];

    if (arrCRC[0] == "0"){
        arrCRC[0] = "0" + arrCRC[0];
    }
    if (arrCRC[0] == "1"){
        arrCRC[0] = "0" + arrCRC[0];
    }
    if (arrCRC[0] == "2"){
        arrCRC[0] = "0" + arrCRC[0];
    }
    if (arrCRC[0] == "3"){
        arrCRC[0] = "0" + arrCRC[0];
    }
    if (arrCRC[0] == "4"){
        arrCRC[0] = "0" + arrCRC[0];
    }
    if (arrCRC[0] == "5"){
        arrCRC[0] = "0" + arrCRC[0];
    }
    if (arrCRC[0] == "6"){
        arrCRC[0] = "0" + arrCRC[0];
    }
    if (arrCRC[0] == "7"){
        arrCRC[0] = "0" + arrCRC[0];
    }
    if (arrCRC[0] == "8"){
        arrCRC[0] = "0" + arrCRC[0];
    }
    if (arrCRC[0] == "9"){
        arrCRC[0] = "0" + arrCRC[0];
    }
    if (arrCRC[0] == "A"){
        arrCRC[0] = "0" + arrCRC[0];
    }
    if (arrCRC[0] == "B"){
        arrCRC[0] = "0" + arrCRC[0];
    }
    if (arrCRC[0] == "C"){
        arrCRC[0] = "0" + arrCRC[0];
    }
    if (arrCRC[0] == "D"){
        arrCRC[0] = "0" + arrCRC[0];
    }
    if (arrCRC[0] == "E"){
        arrCRC[0] = "0" + arrCRC[0];
    }
    if (arrCRC[0] == "F"){
        arrCRC[0] = "0" + arrCRC[0];
    }


    std::stringstream s_UpbCRC;
    s_UpbCRC << arrCRC[0] + arrCRC[1];

    return s_UpbCRC.str();
}

std::vector<std::string> calcCRC::BufSend_out(std::vector<std::string> BufSend) {

    std::string InitCRC = "FFFF";

    std::string Crc = UpdCRC(BufSend[0], InitCRC);

    for (int i = 1; i < (BufSend.size() - 2); ++i) {
        Crc = UpdCRC(BufSend[i], Crc);
    }

    std::stringstream ss1;
    std::stringstream ss2;
    ss1 << Crc[0] << Crc[1];
    ss2 << Crc[2] << Crc[3];

    std::string s1 = ss1.str();
    std::string s2 = ss2.str();

    BufSend[BufSend.size() - 1] = s1;
    BufSend[BufSend.size() - 2] = s2;

    return BufSend;

}

std::vector<std::pair<std::string, std::vector<std::string>>> calcCRC::sConvert(std::vector<std::pair<std::string, std::string>> sInput) {
    std::vector<std::pair<std::string, std::vector<std::string>>> vecByte;

    std::vector<std::string> tmp_tar {"05310_na_+0", "05310_nr_+0", "05310_nr_-0","05310_na_+1", "05310_nr_+1", "05310_nr_-1", "05310_na_+2", "05310_nr_+2", "05310_nr_-2","05310_na_+3", "05310_nr_+3", "05310_nr_-3", "05310_na_+4", "05310_nr_+4", "05310_nr_-4", "05310_na_+5", "05310_nr_+5", "05310_nr_-5"};

    for(auto c: sInput) {

        std::vector<std::string> vB;

        if(c.second[c.second.length() - 1] == '0' and c.second[c.second.length() - 2] == 'x'){

            for(int i =0; i < c.second.length() - 2; i += 2) {
                std::stringstream ss;
                ss << c.second[i] << c.second[i + 1];
                vB.push_back(ss.str());
            }
            vecByte.push_back(std::make_pair(c.first, vB));

        }else if(std::count(c.second.begin(), c.second.end(), '.') > 0) {
            std::stringstream ss;
            for(int i =0; i < c.second.length(); ++i) {
                if (c.second[i] == '.') {
                    ss.str("");
                }else{
                    ss << c.second[i];
                }
                //std::string ss1 = ss.str();

                if(c.second[i+1] != '\0' and c.second[i+1] != '.' and c.second[i] != '.'){
                    ss << c.second[i+1];
                    i++;
                }
                if (ss.str() != "") {
                    vB.push_back(Bin2Hex(Dec2Bin_s(ss.str())));
                }

            }
            vecByte.push_back(std::make_pair(c.first, vB));
        }else {
            for (auto tmp : tmp_tar) {
                if (c.first == tmp) {
                    vB.push_back(Bin2Hex_32(Dec2Bin_s_32(c.second)));
                }
            }
            for(int i =0; i < c.second.length(); i += 2) {
                std::stringstream ss;
                ss << c.second[i] << c.second[i + 1];
                vB.push_back(Bin2Hex(Dec2Bin_s(ss.str())));
            }

            vecByte.push_back(std::make_pair(c.first, vB));
        }
    }
    return vecByte;
}

