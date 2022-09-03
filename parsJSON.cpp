//
// Created by root on 7/16/22.
//

#include "parsJSON.h"


std::vector<std::pair<std::string, std::vector<std::string>>> parsJSON::parserJs(std::string& path) {
        try {

            pt::ptree root;

            pt::read_json(path, root);

            std::vector< std::pair<std::string, std::string> > start_set;


            for (pt::ptree::value_type &st_set : root.get_child("start_set"))
            {

                if (st_set.first == "serial_num") {start_set.push_back(std::make_pair("080_s_n", st_set.second.data()));}
                if (st_set.first == "software_ver") {start_set.push_back(std::make_pair("083", st_set.second.data()));}
                if (st_set.first == "use_meter") {start_set.push_back(std::make_pair("0812", st_set.second.data()));}
                if (st_set.first == "release_date") {start_set.push_back(std::make_pair("080_d_r", st_set.second.data()));}
                if (st_set.first == "CRC16") {start_set.push_back(std::make_pair("0810_CRC_16", st_set.second.data()));}
                if (st_set.first == "kTrans") {start_set.push_back(std::make_pair("082", st_set.second.data()));}
                if (st_set.first == "net_address") {start_set.push_back(std::make_pair("085", st_set.second.data()));}
                if (st_set.first == "tariff") {
                    for(pt::ptree::value_type &tariff : root.get_child("start_set.tariff")){
                        if (tariff.first == "num_tar"){
                            start_set.push_back(std::make_pair("0817_n_t", tariff.second.data()));
                        }
                        if (tariff.first == "mode"){
                            start_set.push_back(std::make_pair("0817_m", tariff.second.data()));
                        }
                        if (tariff.first == "tar_timetable"){
                            start_set.push_back(std::make_pair("0817_t_t", tariff.second.data()));
                        }
                    }
                }
                if (st_set.first == "energy") {
                    for(pt::ptree::value_type &energy : root.get_child("start_set.energy")){
                        if (energy.first == "tar0"){
                            for(pt::ptree::value_type &tar0 : root.get_child("start_set.energy.tar0")){
                                if (tar0.first == "N_A+"){
                                    std::string tmp = tar0.second.data();
                                    std::stringstream ss1;
                                    for (auto c : tmp){
                                        if (c != ',') ss1 << c;
                                        else { continue;}
                                    }
                                    start_set.push_back(std::make_pair("05310_na_+0", ss1.str()));
                                }
                                if (tar0.first == "N_A-"){
                                    start_set.push_back(std::make_pair("05310_na_-0", tar0.second.data()));
                                }
                                if (tar0.first == "N_R+"){
                                    std::string tmp = tar0.second.data();
                                    std::stringstream ss1;
                                    for (auto c : tmp){
                                        if (c != ',') ss1 << c;
                                        else { continue;}
                                    }
                                    start_set.push_back(std::make_pair("05310_nr_+0", ss1.str()));
                                }
                                if (tar0.first == "N_R-"){
                                    std::string tmp = tar0.second.data();
                                    std::stringstream ss1;
                                    for (auto c : tmp){
                                        if (c != ',') ss1 << c;
                                        else { continue;}
                                    }
                                    start_set.push_back(std::make_pair("05310_nr_-0", ss1.str()));
                                }
                            }
                        }
                        if (energy.first == "tar1"){
                            for(pt::ptree::value_type &tar1 : root.get_child("start_set.energy.tar1")){
                                if (tar1.first == "N_A+"){
                                    std::string tmp = tar1.second.data();
                                    std::stringstream ss1;
                                    for (auto c : tmp){
                                        if (c != ',') ss1 << c;
                                        else { continue;}
                                    }
                                    start_set.push_back(std::make_pair("05310_na_+1", ss1.str()));
                                }
                                if (tar1.first == "N_A-"){
                                    start_set.push_back(std::make_pair("05310_na_-1", tar1.second.data()));
                                }
                                if (tar1.first == "N_R+"){
                                    std::string tmp = tar1.second.data();
                                    std::stringstream ss1;
                                    for (auto c : tmp){
                                        if (c != ',') ss1 << c;
                                        else { continue;}
                                    }
                                    start_set.push_back(std::make_pair("05310_nr_+1", ss1.str()));
                                }
                                if (tar1.first == "N_R-"){
                                    std::string tmp = tar1.second.data();
                                    std::stringstream ss1;
                                    for (auto c : tmp){
                                        if (c != ',') ss1 << c;
                                        else { continue;}
                                    }
                                    start_set.push_back(std::make_pair("05310_nr_-1", ss1.str()));
                                }
                            }
                        }
                        if (energy.first == "tar2"){
                            for(pt::ptree::value_type &tar2 : root.get_child("start_set.energy.tar2")){
                                if (tar2.first == "N_A+"){
                                    std::string tmp = tar2.second.data();
                                    std::stringstream ss1;
                                    for (auto c : tmp){
                                        if (c != ',') ss1 << c;
                                        else { continue;}
                                    }
                                    start_set.push_back(std::make_pair("05310_na_+2", ss1.str()));
                                }
                                if (tar2.first == "N_A-"){
                                    start_set.push_back(std::make_pair("05310_na_-2", tar2.second.data()));
                                }
                                if (tar2.first == "N_R+"){
                                    std::string tmp = tar2.second.data();
                                    std::stringstream ss1;
                                    for (auto c : tmp){
                                        if (c != ',') ss1 << c;
                                        else { continue;}
                                    }
                                    start_set.push_back(std::make_pair("05310_nr_+2", ss1.str()));
                                }
                                if (tar2.first == "N_R-"){
                                    std::string tmp = tar2.second.data();
                                    std::stringstream ss1;
                                    for (auto c : tmp){
                                        if (c != ',') ss1 << c;
                                        else { continue;}
                                    }
                                    start_set.push_back(std::make_pair("05310_nr_-2", ss1.str()));
                                }
                            }
                        }
                        if (energy.first == "tar3"){
                            for(pt::ptree::value_type &tar3 : root.get_child("start_set.energy.tar3")){
                                if (tar3.first == "N_A+"){
                                    std::string tmp = tar3.second.data();
                                    std::stringstream ss1;
                                    for (auto c : tmp){
                                        if (c != ',') ss1 << c;
                                        else { continue;}
                                    }
                                    start_set.push_back(std::make_pair("05310_na_+3", ss1.str()));
                                }
                                if (tar3.first == "N_A-"){
                                    start_set.push_back(std::make_pair("05310_na_-3", tar3.second.data()));
                                }
                                if (tar3.first == "N_R+"){
                                    std::string tmp = tar3.second.data();
                                    std::stringstream ss1;
                                    for (auto c : tmp){
                                        if (c != ',') ss1 << c;
                                        else { continue;}
                                    }
                                    start_set.push_back(std::make_pair("05310_nr_+3", ss1.str()));
                                }
                                if (tar3.first == "N_R-"){
                                    std::string tmp = tar3.second.data();
                                    std::stringstream ss1;
                                    for (auto c : tmp){
                                        if (c != ',') ss1 << c;
                                        else { continue;}
                                    }
                                    start_set.push_back(std::make_pair("05310_nr_-3", ss1.str()));
                                }
                            }
                        }
                        if (energy.first == "tar4"){
                            for(pt::ptree::value_type &tar4 : root.get_child("start_set.energy.tar4")){
                                if (tar4.first == "N_A+"){
                                    std::string tmp = tar4.second.data();
                                    std::stringstream ss1;
                                    for (auto c : tmp){
                                        if (c != ',') ss1 << c;
                                        else { continue;}
                                    }
                                    start_set.push_back(std::make_pair("05310_na_+4", ss1.str()));
                                }
                                if (tar4.first == "N_A-"){
                                    start_set.push_back(std::make_pair("05310_na_-4", tar4.second.data()));
                                }
                                if (tar4.first == "N_R+"){
                                    std::string tmp = tar4.second.data();
                                    std::stringstream ss1;
                                    for (auto c : tmp){
                                        if (c != ',') ss1 << c;
                                        else { continue;}
                                    }
                                    start_set.push_back(std::make_pair("05310_nr_+4", ss1.str()));
                                }
                                if (tar4.first == "N_R-"){
                                    std::string tmp = tar4.second.data();
                                    std::stringstream ss1;
                                    for (auto c : tmp){
                                        if (c != ',') ss1 << c;
                                        else { continue;}
                                    }
                                    start_set.push_back(std::make_pair("05310_nr_-4", ss1.str()));
                                }
                            }
                        }
                        if (energy.first == "tar5"){
                            for(pt::ptree::value_type &tar5 : root.get_child("start_set.energy.tar5")){
                                if (tar5.first == "N_A+"){
                                    std::string tmp = tar5.second.data();
                                    std::stringstream ss1;
                                    for (auto c : tmp){
                                        if (c != ',') ss1 << c;
                                        else { continue;}
                                    }
                                    start_set.push_back(std::make_pair("05310_na_+5", ss1.str()));
                                }
                                if (tar5.first == "N_A-"){
                                    start_set.push_back(std::make_pair("05310_na_-5", tar5.second.data()));
                                }
                                if (tar5.first == "N_R+"){
                                    std::string tmp = tar5.second.data();
                                    std::stringstream ss1;
                                    for (auto c : tmp){
                                        if (c != ',') ss1 << c;
                                        else { continue;}
                                    }
                                    start_set.push_back(std::make_pair("05310_nr_+5", ss1.str()));
                                }
                                if (tar5.first == "N_R-"){
                                    std::string tmp = tar5.second.data();
                                    std::stringstream ss1;
                                    for (auto c : tmp){
                                        if (c != ',') ss1 << c;
                                        else { continue;}
                                    }
                                    start_set.push_back(std::make_pair("05310_nr_-5", ss1.str()));
                                }
                            }
                        }
                    }
                }
            }

            calcCRC cl;

            std::vector<std::pair<std::string, std::vector<std::string>>> retVec = cl.sConvert(start_set);

            return retVec;

        } catch (const std::exception & ex) {
        std::cout << ex.what() << std::endl;
        }
}
