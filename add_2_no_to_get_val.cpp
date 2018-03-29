#include <cstdio>
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char ** argv)
{
    int target = 15;
    std::pair<int,int> output;
    std::array<int,5> given_numbers = {1,2,7,11,15};

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

    return 0;
}
