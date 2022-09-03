//
// Created by root on 7/15/22.
//

#include "selectCom.h"

std::vector<std::string> selectCom::selC(std::vector<std::string> checkBuf, std::vector<std::pair<std::string, std::vector<std::string>>> vecPars) {

    std::vector<std::string> BufSend;
    calcCRC cC;

    std::string str;
    for(auto c: vecPars){
        if (c.first == "085") {
            for (int i = 0; i < c.second.size(); ++i) {
                str = c.second[i];
            }
        }
    }

    if (checkBuf[0] == str and checkBuf[1] == "80"){

        for(auto c: vecPars){
            if (c.first == "085") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }
        BufSend.push_back("00");
        BufSend.push_back("");
        BufSend.push_back("");

    }


    //need access flag for admin or user
    if (checkBuf[0] == str and checkBuf[1] == "1" and checkBuf[2] == "1" and checkBuf[3] == "1" and checkBuf[4] == "1" and checkBuf[5] == "1" and checkBuf[6] == "1" and checkBuf[7] == "1" and checkBuf[8] == "1"){

        for(auto c: vecPars){
            if (c.first == "085") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }
        BufSend.push_back("00");
        BufSend.push_back("");
        BufSend.push_back("");

    }

    if (checkBuf[0] == str and checkBuf[1] == "1" and checkBuf[2] == "2" and checkBuf[3] == "1" and checkBuf[4] == "1" and checkBuf[5] == "1" and checkBuf[6] == "1" and checkBuf[7] == "1" and checkBuf[8] == "1"){

        for(auto c: vecPars){
            if (c.first == "085") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }
        BufSend.push_back("00");
        BufSend.push_back("");
        BufSend.push_back("");

    }

    if (checkBuf[0] == str and checkBuf[1] == "1" and checkBuf[2] == "2" and checkBuf[3] == "2" and checkBuf[4] == "2" and checkBuf[5] == "2" and checkBuf[6] == "2" and checkBuf[7] == "2" and checkBuf[8] == "2"){

        for(auto c: vecPars){
            if (c.first == "085") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }
        BufSend.push_back("00");
        BufSend.push_back("");
        BufSend.push_back("");

    }

    if (checkBuf[0] == str and checkBuf[1] == "3" and checkBuf[2] == "31" and checkBuf[3] == "1"){

        for(auto c: vecPars){
            if (c.first == "085") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }

        BufSend.push_back("00");

        BufSend.push_back("");
        BufSend.push_back("");

    }

    if (checkBuf[0] == str and checkBuf[1] == "5" and checkBuf[2] == "0" and checkBuf[3] == "0"){

        for(auto c: vecPars){
            if (c.first == "085") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }

        BufSend.push_back("00");
        BufSend.push_back("00");

        for(auto c: vecPars){
            if (c.first == "05310_na_+0") {
                for (int i = c.second[0].size() - 1; i >= 0; --i) {
                    std::stringstream ss;
                    if (c.second[0][i-1] != '\0'){ss << c.second[0][i-1] << c.second[0][i]; --i;}
                    else{ss << c.second[0][i];}
                    BufSend.push_back(ss.str());
                }
            }
        }
        BufSend.push_back("FF");
        BufSend.push_back("FF");

        for(auto c: vecPars){
            if (c.first == "05310_na_-0") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }
        BufSend.push_back("00");
        BufSend.push_back("00");

        for(auto c: vecPars){
            if (c.first == "05310_nr_+0") {
                for (int i = c.second[0].size() - 1; i >= 0; --i) {
                    std::stringstream ss;
                    if (c.second[0][i-1] != '\0'){ss << c.second[0][i-1] << c.second[0][i]; --i;}
                    else{ss << c.second[0][i];}
                    BufSend.push_back(ss.str());
                }
            }
        }

        BufSend.push_back("00");
        BufSend.push_back("00");
        BufSend.push_back("00");
        BufSend.push_back("00");

        BufSend.push_back("");
        BufSend.push_back("");

    }

    if (checkBuf[0] == str and checkBuf[1] == "5" and checkBuf[2] == "0" and checkBuf[3] == "1"){

        for(auto c: vecPars){
            if (c.first == "085") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }

        BufSend.push_back("00");
        BufSend.push_back("00");

        for(auto c: vecPars){
            if (c.first == "05310_na_+0") {
                for (int i = c.second[0].size() - 1; i >= 0; --i) {
                    std::stringstream ss;
                    if (c.second[0][i-1] != '\0'){ss << c.second[0][i-1] << c.second[0][i]; --i;}
                    else{ss << c.second[0][i];}
                    BufSend.push_back(ss.str());
                }
            }
        }
        BufSend.push_back("FF");
        BufSend.push_back("FF");

        for(auto c: vecPars){
            if (c.first == "05310_na_-0") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }
        BufSend.push_back("00");
        BufSend.push_back("00");

        for(auto c: vecPars){
            if (c.first == "05310_nr_+0") {
                for (int i = c.second[0].size() - 1; i >= 0; --i) {
                    std::stringstream ss;
                    if (c.second[0][i-1] != '\0'){ss << c.second[0][i-1] << c.second[0][i]; --i;}
                    else{ss << c.second[0][i];}
                    BufSend.push_back(ss.str());
                }
            }
        }

        BufSend.push_back("00");
        BufSend.push_back("00");
        BufSend.push_back("00");
        BufSend.push_back("00");

        BufSend.push_back("");
        BufSend.push_back("");

    }

    if (checkBuf[0] == str and checkBuf[1] == "5" and checkBuf[2] == "0" and checkBuf[3] == "2"){

        for(auto c: vecPars){
            if (c.first == "085") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }

        BufSend.push_back("00");
        BufSend.push_back("00");

        for(auto c: vecPars){
            if (c.first == "05310_na_+0") {
                for (int i = c.second[0].size() - 1; i >= 0; --i) {
                    std::stringstream ss;
                    if (c.second[0][i-1] != '\0'){ss << c.second[0][i-1] << c.second[0][i]; --i;}
                    else{ss << c.second[0][i];}
                    BufSend.push_back(ss.str());
                }
            }
        }
        BufSend.push_back("FF");
        BufSend.push_back("FF");

        for(auto c: vecPars){
            if (c.first == "05310_na_-0") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }
        BufSend.push_back("00");
        BufSend.push_back("00");

        for(auto c: vecPars){
            if (c.first == "05310_nr_+0") {
                for (int i = c.second[0].size() - 1; i >= 0; --i) {
                    std::stringstream ss;
                    if (c.second[0][i-1] != '\0'){ss << c.second[0][i-1] << c.second[0][i]; --i;}
                    else{ss << c.second[0][i];}
                    BufSend.push_back(ss.str());
                }
            }
        }

        BufSend.push_back("00");
        BufSend.push_back("00");
        BufSend.push_back("00");
        BufSend.push_back("00");

        BufSend.push_back("");
        BufSend.push_back("");

    }

    if (checkBuf[0] == str and checkBuf[1] == "5" and checkBuf[2] == "31" and checkBuf[3] == "0"){

        for(auto c: vecPars){
            if (c.first == "085") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }

        BufSend.push_back("00");
        BufSend.push_back("00");

        for(auto c: vecPars){
            if (c.first == "05310_na_+1") {
                for (int i = c.second[0].size() - 1; i >= 0; --i) {
                    std::stringstream ss;
                    if (c.second[0][i-1] != '\0'){ss << c.second[0][i-1] << c.second[0][i]; --i;}
                    else{ss << c.second[0][i];}
                    BufSend.push_back(ss.str());
                }
            }
        }
        BufSend.push_back("FF");
        BufSend.push_back("FF");

        for(auto c: vecPars){
            if (c.first == "05310_na_-1") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }
        BufSend.push_back("00");
        BufSend.push_back("00");

        for(auto c: vecPars){
            if (c.first == "05310_nr_+1") {
                for (int i = c.second[0].size() - 1; i >= 0; --i) {
                    std::stringstream ss;
                    if (c.second[0][i-1] != '\0'){ss << c.second[0][i-1] << c.second[0][i]; --i;}
                    else{ss << c.second[0][i];}
                    BufSend.push_back(ss.str());
                }
            }
        }

        BufSend.push_back("00");
        BufSend.push_back("00");
        BufSend.push_back("00");
        BufSend.push_back("00");

        BufSend.push_back("");
        BufSend.push_back("");

    }

    if (checkBuf[0] == str and checkBuf[1] == "5" and checkBuf[2] == "31" and checkBuf[3] == "1"){

        for(auto c: vecPars){
            if (c.first == "085") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }

        BufSend.push_back("00");
        BufSend.push_back("00");

        for(auto c: vecPars){
            if (c.first == "05310_na_+1") {
                for (int i = c.second[0].size() - 1; i >= 0; --i) {
                    std::stringstream ss;
                    if (c.second[0][i-1] != '\0'){ss << c.second[0][i-1] << c.second[0][i]; --i;}
                    else{ss << c.second[0][i];}
                    BufSend.push_back(ss.str());
                }
            }
        }
        BufSend.push_back("FF");
        BufSend.push_back("FF");

        for(auto c: vecPars){
            if (c.first == "05310_na_-1") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }
        BufSend.push_back("00");
        BufSend.push_back("00");

        for(auto c: vecPars){
            if (c.first == "05310_nr_+1") {
                for (int i = c.second[0].size() - 1; i >= 0; --i) {
                    std::stringstream ss;
                    if (c.second[0][i-1] != '\0'){ss << c.second[0][i-1] << c.second[0][i]; --i;}
                    else{ss << c.second[0][i];}
                    BufSend.push_back(ss.str());
                }
            }
        }

        BufSend.push_back("00");
        BufSend.push_back("00");
        BufSend.push_back("00");
        BufSend.push_back("00");

        BufSend.push_back("");
        BufSend.push_back("");

    }

    if (checkBuf[0] == str and checkBuf[1] == "5" and checkBuf[2] == "31" and checkBuf[3] == "2"){

        for(auto c: vecPars){
            if (c.first == "085") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }

        BufSend.push_back("00");
        BufSend.push_back("00");

        for(auto c: vecPars){
            if (c.first == "05310_na_+2") {
                for (int i = c.second[0].size() - 1; i >= 0; --i) {
                    std::stringstream ss;
                    if (c.second[0][i-1] != '\0'){ss << c.second[0][i-1] << c.second[0][i]; --i;}
                    else{ss << c.second[0][i];}
                    BufSend.push_back(ss.str());
                }
            }
        }
        BufSend.push_back("FF");
        BufSend.push_back("FF");

        for(auto c: vecPars){
            if (c.first == "05310_na_-2") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }
        BufSend.push_back("00");
        BufSend.push_back("00");

        for(auto c: vecPars){
            if (c.first == "05310_nr_+2") {
                for (int i = c.second[0].size() - 1; i >= 0; --i) {
                    std::stringstream ss;
                    if (c.second[0][i-1] != '\0'){ss << c.second[0][i-1] << c.second[0][i]; --i;}
                    else{ss << c.second[0][i];}
                    BufSend.push_back(ss.str());
                }
            }
        }

        BufSend.push_back("00");
        BufSend.push_back("00");
        BufSend.push_back("00");
        BufSend.push_back("00");

        BufSend.push_back("");
        BufSend.push_back("");

    }

    if (checkBuf[0] == str and checkBuf[1] == "5" and checkBuf[2] == "31" and checkBuf[3] == "3"){

        for(auto c: vecPars){
            if (c.first == "085") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }

        BufSend.push_back("00");
        BufSend.push_back("00");

        for(auto c: vecPars){
            if (c.first == "05310_na_+3") {
                for (int i = c.second[0].size() - 1; i >= 0; --i) {
                    std::stringstream ss;
                    if (c.second[0][i-1] != '\0'){ss << c.second[0][i-1] << c.second[0][i]; --i;}
                    else{ss << c.second[0][i];}
                    BufSend.push_back(ss.str());
                }
            }
        }
        BufSend.push_back("FF");
        BufSend.push_back("FF");

        for(auto c: vecPars){
            if (c.first == "05310_na_-3") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }
        BufSend.push_back("00");
        BufSend.push_back("00");

        for(auto c: vecPars){
            if (c.first == "05310_nr_+3") {
                for (int i = c.second[0].size() - 1; i >= 0; --i) {
                    std::stringstream ss;
                    if (c.second[0][i-1] != '\0'){ss << c.second[0][i-1] << c.second[0][i]; --i;}
                    else{ss << c.second[0][i];}
                    BufSend.push_back(ss.str());
                }
            }
        }

        BufSend.push_back("00");
        BufSend.push_back("00");
        BufSend.push_back("00");
        BufSend.push_back("00");

        BufSend.push_back("");
        BufSend.push_back("");

    }

    if (checkBuf[0] == str and checkBuf[1] == "5" and checkBuf[2] == "31" and checkBuf[3] == "4"){

        for(auto c: vecPars){
            if (c.first == "085") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }

        BufSend.push_back("00");
        BufSend.push_back("00");

        for(auto c: vecPars){
            if (c.first == "05310_na_+4") {
                for (int i = c.second[0].size() - 1; i >= 0; --i) {
                    std::stringstream ss;
                    if (c.second[0][i-1] != '\0'){ss << c.second[0][i-1] << c.second[0][i]; --i;}
                    else{ss << c.second[0][i];}
                    BufSend.push_back(ss.str());
                }
            }
        }
        BufSend.push_back("FF");
        BufSend.push_back("FF");

        for(auto c: vecPars){
            if (c.first == "05310_na_-4") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }
        BufSend.push_back("00");
        BufSend.push_back("00");

        for(auto c: vecPars){
            if (c.first == "05310_nr_+4") {
                for (int i = c.second[0].size() - 1; i >= 0; --i) {
                    std::stringstream ss;
                    if (c.second[0][i-1] != '\0'){ss << c.second[0][i-1] << c.second[0][i]; --i;}
                    else{ss << c.second[0][i];}
                    BufSend.push_back(ss.str());
                }
            }
        }

        BufSend.push_back("00");
        BufSend.push_back("00");
        BufSend.push_back("00");
        BufSend.push_back("00");

        BufSend.push_back("");
        BufSend.push_back("");

    }

    if (checkBuf[0] == str and checkBuf[1] == "5" and checkBuf[2] == "31" and checkBuf[3] == "5"){

        for(auto c: vecPars){
            if (c.first == "085") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }

        BufSend.push_back("00");
        BufSend.push_back("00");

        for(auto c: vecPars){
            if (c.first == "05310_na_+5") {
                for (int i = c.second[0].size() - 1; i >= 0; --i) {
                    std::stringstream ss;
                    if (c.second[0][i-1] != '\0'){ss << c.second[0][i-1] << c.second[0][i]; --i;}
                    else{ss << c.second[0][i];}
                    BufSend.push_back(ss.str());
                }
            }
        }
        BufSend.push_back("FF");
        BufSend.push_back("FF");

        for(auto c: vecPars){
            if (c.first == "05310_na_-5") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }
        BufSend.push_back("00");
        BufSend.push_back("00");

        for(auto c: vecPars){
            if (c.first == "05310_nr_+5") {
                for (int i = c.second[0].size() - 1; i >= 0; --i) {
                    std::stringstream ss;
                    if (c.second[0][i-1] != '\0'){ss << c.second[0][i-1] << c.second[0][i]; --i;}
                    else{ss << c.second[0][i];}
                    BufSend.push_back(ss.str());
                }
            }
        }

        BufSend.push_back("00");
        BufSend.push_back("00");
        BufSend.push_back("00");
        BufSend.push_back("00");

        BufSend.push_back("");
        BufSend.push_back("");

    }

    if (checkBuf[0] == str and checkBuf[1] == "6" and checkBuf[2] == "2" and checkBuf[3] == "1D" and checkBuf[4] == "0" and checkBuf[5] == "4"){

        for(auto c: vecPars){
            if (c.first == "085") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }
        for(auto c: vecPars){
            if (c.first == "080_s_n") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }

        BufSend.push_back("");
        BufSend.push_back("");

    }

    if (checkBuf[0] == str and checkBuf[1] == "8" and checkBuf[2] == "0"){

        for(auto c: vecPars){
            if (c.first == "085") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }
        for(auto c: vecPars){
            if (c.first == "080_s_n") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
            if (c.first == "080_d_r") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }

        BufSend.push_back("");
        BufSend.push_back("");

    }

    if (checkBuf[0] == str and checkBuf[1] == "8" and checkBuf[2] == "1" and checkBuf[3] == "0"){

        for(auto c: vecPars){
            if (c.first == "085") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }

        std::vector<std::string> str {"080_s_n", "080_d_r", "083", "0812", "0810_CRC_16"};
        for (int j = 0; j < str.size(); ++j) {
            for(auto c: vecPars){
                if (std::string(c.first) == str[j]) {
                    for (int i = 0; i < c.second.size(); ++i) {
                        BufSend.push_back(c.second[i]);
                    }
                    continue;
                }
            }
        }

        BufSend.push_back("32");
        BufSend.push_back("44");
        BufSend.push_back("0C");
        BufSend.push_back("00");
        BufSend.push_back("00");
        BufSend.push_back("00");
        BufSend.push_back("");
        BufSend.push_back("");

    }

    if (checkBuf[0] == str and checkBuf[1] == "8" and checkBuf[2] == "1" and checkBuf[3] != "0" and checkBuf[3] != "FF"){

        for(auto c: vecPars){
            if (c.first == "085") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }

        for(auto c: vecPars){
            if (c.first == "080_s_n") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
            if (c.first == "080_d_r") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
            if (c.first == "083") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }

        BufSend.push_back("");
        BufSend.push_back("");

    }

    ///// this place work now
    if (checkBuf[0] == str and checkBuf[1] == "8" and checkBuf[2] == "2") {

        for(auto c: vecPars){
            if (c.first == "085") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }

        for (auto c: vecPars) {
            if (c.first == "082") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }
        for (auto c: vecPars) {
            if (c.first == "082") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }
        BufSend.push_back("");
        BufSend.push_back("");
    }

    if (checkBuf[0] == str and checkBuf[1] == "8" and checkBuf[2] == "3"){

        for(auto c: vecPars){
            if (c.first == "085") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }

        for(auto c: vecPars){
            if (c.first == "083") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }

        BufSend.push_back("");
        BufSend.push_back("");

    }

    if (checkBuf[0] == str and checkBuf[1] == "8" and checkBuf[2] == "5"){

        for(auto c: vecPars){
            if (c.first == "085") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }
        BufSend.push_back("00");
        for(auto c: vecPars){
            if (c.first == "085") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }
        BufSend.push_back("");
        BufSend.push_back("");

    }

    if (checkBuf[0] == str and checkBuf[1] == "8" and checkBuf[2] == "12"){

        for(auto c: vecPars){
            if (c.first == "085") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }

        for(auto c: vecPars){
            if (c.first == "0812") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }

        BufSend.push_back("");
        BufSend.push_back("");

    }

    if (checkBuf[0] == str and checkBuf[1] == "8" and checkBuf[2] == "17" and checkBuf[3] != "0"){

        for(auto c: vecPars){
            if (c.first == "085") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }
        BufSend.push_back("00");
        BufSend.push_back("07");

        BufSend.push_back("");
        BufSend.push_back("");
    }

    if (checkBuf[0] == str and checkBuf[1] == "8" and checkBuf[2] == "17" and checkBuf[3] == "0"){

        for(auto c: vecPars){
            if (c.first == "085") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }
        BufSend.push_back("00");
        BufSend.push_back("00");

        for (int j = 0; j < vecPars.size(); ++j) {
            for(auto c: vecPars){
                if (c.first == "tar_timetable") {
                    for (int i = 0; i < c.second.size(); ++i) {
                        BufSend.push_back(c.second[i]);
                    }
                }
            }
        }

        BufSend.push_back("");
        BufSend.push_back("");
    }

    if (checkBuf[0] == str and checkBuf[1] == "8" and checkBuf[2] == "18"){

        for(auto c: vecPars){
            if (c.first == "085") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }



        BufSend.push_back("06");
        BufSend.push_back("00");

        BufSend.push_back("");
        BufSend.push_back("");

    }

    if (checkBuf[0] == str and checkBuf[1] == "8" and checkBuf[2] == "26"){

        for(auto c: vecPars){
            if (c.first == "085") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }

        for(auto c: vecPars){
            if (c.first == "0810_CRC_16") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }

        BufSend.push_back("");
        BufSend.push_back("");

    }



    if (checkBuf[0] == str and checkBuf[1] == "2"){

        for(auto c: vecPars){
            if (c.first == "085") {
                for (int i = 0; i < c.second.size(); ++i) {
                    BufSend.push_back(c.second[i]);
                }
            }
        }
        BufSend.push_back("00");
        BufSend.push_back("");
        BufSend.push_back("");

    }

    else if (BufSend.empty()){
        std::cout << "command not defined\n";
    }

    return BufSend;
}
