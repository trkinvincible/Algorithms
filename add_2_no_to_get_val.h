#ifndef ADD_2_NO_TO_GET_VAL_H
#define ADD_2_NO_TO_GET_VAL_H

#include <cstdio>
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include "command.h"

using namespace std;

class add_2_no_to_get_val : public Command{

    void execute()
    {
        int target = 97;
        std::pair<int,int> output;
        std::array<int,31> given_numbers = {2,3,5,7,8,3,1,43,6,8,8,8,4,2,21,54,76,8,9,0,76,6,5,87,9,8,1,2,7,11,15};

        std::vector<int> input_copy(given_numbers.begin(),given_numbers.end());

        std::vector<int>::const_iterator citr = std::upper_bound(input_copy.begin(),input_copy.end(),target);
        if(citr != input_copy.cend()){

            input_copy.resize(citr - input_copy.begin());
        }
        while(true){

            if(input_copy.size() < 2){

                std::cout << "Sum Not found" <<std::endl;
                break;
            }
            int val = input_copy.back();
            int diff = target - val;
            if(std::binary_search(input_copy.begin(),input_copy.end(),diff)){
                output = std::make_pair(diff,val);
                break;
            }else{
                input_copy.pop_back();
            }
        }

        std::cout << "Matching Pairs are: " << output.first << " and " << output.second << std::endl;
    }
};



#endif // ADD_2_NO_TO_GET_VAL_H
