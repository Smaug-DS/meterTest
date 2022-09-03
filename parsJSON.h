//
// Created by root on 7/16/22.
//

#ifndef MER1_PARSJSON_H
#define MER1_PARSJSON_H

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <iostream>
#include <fstream>
#include "calcCRC.h"

namespace pt = boost::property_tree;

class parsJSON {
public:
    std::vector<std::pair<std::string, std::vector<std::string>>> parserJs (std::string&);
};


#endif //MER1_PARSJSON_H