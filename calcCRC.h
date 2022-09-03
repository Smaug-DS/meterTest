//
// Created by root on 7/15/22.
//


#include <boost/algorithm/string.hpp>
#include <iostream>
#include <vector>
#include <bitset>
#include <sstream>
#ifndef MER1_CALCCRC_H
#define MER1_CALCCRC_H


class calcCRC {

public:

    std::string Hex2Bin(const std::string& s);

    std::string Bin2Hex(const std::string& s);

    std::string Bin2Hex_32(const std::string &s);

    unsigned int Bin2Dec_i(const std::string& s);

    std::string Bin2Dec_s(const std::string& s);

    std::string Dec2Bin_s_32(const std::string &s);

    unsigned int Dec2Bin_i(const std::string& s);

    std::string Dec2Bin_s(const std::string& s);

    std::string UpdCRC(std::string& C, std::string& oldCRC);

    std::vector<std::string> BufSend_out(std::vector<std::string> BufSend);

    std::vector<std::pair<std::string, std::vector<std::string>>> sConvert (std::vector<std::pair<std::string, std::string>>);



};


#endif //MER1_CALCCRC_H
