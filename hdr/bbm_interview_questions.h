#ifndef BBM_INTERVIEW_QUESTIONS_H
#define BBM_INTERVIEW_QUESTIONS_H

#include "command.h"
#include <variant>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <boost/algorithm/cxx17/reduce.hpp>
#include <queue>
#include <ostream>
#include "boost/algorithm/string.hpp"
#include <tuple>

class bbm_interview_questions : public Command{

    void execute()
    {
        /*###########################################################################*/
//        Display three first letter of a given input string N times, but when the input is less then three, display in reverse.

//        Example:

//        displayMulti("Jakarta", 2) --> JakJak
//        displayMulti("Jakarta", 3) --> JakJakJak
//        displayMulti("BBM", 2) --> BBMBBM
//        displayMulti("Or", 3) --> rOrOrO
        /*###########################################################################*/

        int n=4;
        std::string s("jakartha");
        std::string s2;
        s2.reserve(s.size());
        std::copy_n(s.begin(),3,s2.begin());
        std::ostream os(std::cout.rdbuf());
        //boost::algorithm::trim(s2);
        int len = s2.length();
        switch(len){

        case 3:
        {
            for(int i = 0;i < n;i++){
                os << s2;
            }
        }
            break;
        default:
        {
            std::reverse(s2.begin(),s2.end());
            for(int i = 0;i < n;i++){
                os << s2;
            }
        }
            break;
        }
        os << "\n\n\n\n";
        std::flush(os);

        /*###########################################################################*/
//        Assume you need to write a code for phone book. The input is parsed from comma & semi colon separated text. You are expected to use collection and Object Oriented approach as we are interested to see your skill on that.

//        Input:
//        Charlie,Zoe,08123123123;Andre,Xavier,08111222333;Charlie,Xyz,08123123123;Jean,Summers,08001001001

//        Output:
//        === Output START ===
//        Log:
//        Charlie Zoe – 08123123123 : insert success
//        Andre Xavier – 08111222333 : insert success
//        Charlie Xyz – 08123123123 : duplicate phone number
//        Jean Summers – 08001001001 : insert success

//        Phone book:
//        1. Andre Xavier – 08111222333
//        2. Charlie Zoe – 08123123123
//        3. Jean Summers – 08001001001
//        === Output END ===
        /*###########################################################################*/

        using phonebook_record = std::tuple<std::string,std::string,long long >;
        using phonebook = std::list<phonebook_record>;

        std::string input = "Charlie,Zoe,081231;Andre,Xavier,08111;Charlie,Xyz,08123;Jean,Summers,08001";
        std::vector<std::string> values;
        phonebook pb;
        boost::algorithm::split(values, input, boost::is_any_of(";"));
        int record = 0;
        while(record < values.size()){

            std::string firstname;
            std::string lastname;
            std::string number;
            std::tie(firstname,lastname,number) = {values.at(record),values.at(record+1),values.at(record+2)};
            record+=3;
            pb.emplace_back(std::make_tuple(firstname,lastname,std::stoi(number)));
        }
        int i = 1;
        os << "\n\n\n=== Output START ===" << std::endl;
        os << "Phone book:" << std::endl;
        for(std::list<phonebook_record>::iterator itr=pb.begin();itr != pb.end();itr++,i++){

            os << i << ". ";
            os << std::get<0>(*itr) << " " << std::get<1>(*itr) << " - " << std::get<2>(*itr) << std::endl;
        }
        os << "=== Output END ===" << std::endl;

        std::flush(os);
    }
};

#endif // BBM_INTERVIEW_QUESTIONS_H
