#ifndef VISA_INTERVIEW_H
#define VISA_INTERVIEW_H

#include "command.h"
#include <string>
#include <bitset>
#include <vector>
#include <algorithm>
#include <tuple>

class visa_interview : public Command{

    std::vector<std::string> split(std::string input) {

        std::vector<std::string> ret;
        std::regex r(R"([^\W]+*)");
        for(std::sregex_iterator i = std::sregex_iterator(input.begin(), input.end(), r);
            i != std::sregex_iterator();
            ++i)
        {
            std::smatch m = *i;
            ret.push_back(m.str());
        }

        return ret;
    }

    string longestEvenWord(string sentence) {

        std::vector<std::string> ret = split(sentence);
        int local_long_string_size=0;
        std::string long_string;
        for(auto item : ret){
            if(item.size() > local_long_string_size && (item.size() % 2) == 0){

                local_long_string_size = item.size();
                long_string = item;
            }
        }
        if(long_string.empty())
            return "00";
        else
            return long_string;

    }

    void execute()
    {
        std::vector<int> A1={1,2,3};
        std::vector<int> A2;
        std::copy_if(A1.begin(),A1.end(),std::back_insert_iterator(A2),[](int item){return true;});

        //std::for_each(A2.begin(),A2.end(),[](int item){std::cout << "value:" << item;});

        struct D{

            std::tuple<int,int> operator()(){

                return std::make_tuple(2,3);
            }
        };
        D d;
//        std::bitset<8> b(13);
//        std:cout << b.to_string();
//        int i=0,n=0;
//        int times=0;
//        while(true){

//            if(b.test(i+1)){

//                b.set(i) = 0;
//            }
//            std::srand(std::time(nullptr));
//            n = std::rand();
//            b.set(b.count(),n);

//            if(b == 0)
//                break;

//            i++;
//            i = i % b.size()-1;
//            ++times;
//        }
//        std::cout << times;
        //std::cout << longestEvenWord("You can do it the way you like") << std::endl;
    }
};

#endif // VISA_INTERVIEW_H
