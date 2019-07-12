#ifndef PRACTICE_H
#define PRACTICE_H
#include "command.h"
#include <string.h>
#include <bitset>
#include <atomic>
#include <utility>
#include <deque>
#include <algorithm>
#include <array>
#include <cctype>
#include <boost/interprocess/file_mapping.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <iostream>

struct points{

    int p1;
    int p2;
};

int g_end_index=0;
void reverse(std::string &str){

    uint start_index = g_end_index;
    uint end_index;

    auto pos = str.find_first_of(' ',g_end_index);
    if(pos != std::string::npos){

        g_end_index = pos + 1;
        end_index = pos-1;
        reverse(str);
    }else{

        end_index = str.length();
    }
    for(int i = start_index;i <= end_index;i++){

        std::cout << str[i];
    }
    std::cout << " ";
}



//void InsertDataAtIndex(std::pair<int,int> data)
//{
//    std::istringstream input;
//    input.str(start_address);

//    std::ostringstream output;
//    output.str(start_address);

//    int line_number = 0;
//    std::string line;
//    for (;;){

//        if(std::getline(input, line)){

//            if(line_number == data.first){

//                auto pos = input.tellg();
//                output.seekp(pos);
//                output << data.second;
//                break;
//            }
//        }else{
//            //eof
//            if(line_number == data.first){

//                output << data.second << std::endl;
//            }else{

//                output << " " << std::endl;
//            }
//        }
//        line_number++;
//    }
//}

template<typename T1>
struct A{

public:
    template<typename T2>
    static void getA(){}
};

class practice: public Command{

    void execute()
    {
        std::cout << "Hello Its configured" << std::endl;

        //reverse(str);


//        for(auto i : test_array){

//            InsertDataAtIndex(i);
//        }

//        std::basic_string<points> line = {{1,2},{3,4}};
//        line += {5,6};


//        struct CacheBuffer{

//            short position;
//            short status;
//            unsigned int data;
//        };
////        std::cout << std::boolalpha << sizeof(CacheBuffer) << '\n';
////        std::cout << std::boolalpha << std::atomic<CacheBuffer>{}.is_lock_free() << '\n';

//        std::array<std::atomic<CacheBuffer>,20> buf_arr;
//        buf_arr[0] = {0,0,0};

//        CacheBuffer d2 = {0,0,0};
//        CacheBuffer d3 = {1,1,1};
//        do {
//        } while (!buf_arr[0].compare_exchange_strong(d2,d3));

//        CacheBuffer test = buf_arr[0].load();
//        std::cout << test.data << std::endl;

//        struct alignas(64) A{

//            int a;
//        };
//        std::cout << sizeof(A) << std::endl;
//        A a1;
//        A a2;
//        std::cout << "Address of: " << std::addressof(a1) << std::endl;
//        std::cout << "Address of: " << std::addressof(a2) << std::endl;

//        std::cout << v[0].load().data << std::endl;
//        std::cout << v[0].load().position << std::endl;
//        std::cout << v[0].load().status << std::endl;

//        auto itr_3 = v.begin()+ 2;
//        auto itr_5 = v.begin()+ 4;
//        std::cout << "value_3" << *itr_3 << std::endl;
//        std::cout << "value_5" << *itr_5 << std::endl;

//        auto buf_ref = v[3];
//        v.erase(v.begin()+3);
//        v.push_front(buf_ref);

//        std::cout << "value_3" << *itr_3 << std::endl;
//        std::cout << "value_5" << *itr_5 << std::endl;

//        std::for_each(v.begin(),v.end(),[](auto i){std::cout << i;});

//        std::cout << "last element" << *(std::prev(v.end())) << std::endl;
    }
};

#endif // PRACTICE_H
