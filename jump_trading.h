#ifndef JUMP_TRADING_H
#define JUMP_TRADING_H

#include <command.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <numeric>

using namespace std;

int mymincost(std::vector<int> &input)
{
    //runtime: worst case O(30)

    std::array<std::pair<bool,int>,30> input_seq;

    /*
     * create an srray of 30 items as <is_day_travelled,cost_per_day>
    */
    int index=1;
    for(auto &i : input_seq){

        if(std::binary_search(input.begin(),input.end(),index)){
            i.first = true;i.second = 0;
        }
        index++;
    }
    int min_cost_to_return=0;
    const int filter_size=7;
    auto start = input_seq.begin();
    int number_of_days_to_run=30;

    /*
     * slide the filter of size 7 and of stride 1 over all the 30 days
    */
    while(number_of_days_to_run >= 1){

        int no_of_set_days_in_this_week=0;
        auto start_copy = start;
        /*
         * calculate end such that its less than the 30
        */
        auto e = start+(std::min(filter_size,number_of_days_to_run));
        for(auto s=start;s != e;s++){

            /*
             * start with assume every day have to buy $2 ticket
            */
            if(s->first){
                no_of_set_days_in_this_week++;
                s->second = 2;
            }
        }
        /*
         * if 4 or more days need travel in that week
         * which is (2*4)8 > 7 so buy 7 day ticket so each day is $1 only
        */
        if(no_of_set_days_in_this_week >= 4){

            //assign $1 for each day of the week getting processed
            for(auto s=start;s != e;s++){

                s->second = 1;
            }
            start = start+8;
            number_of_days_to_run -= 7;

            /*
             * keep track of the accumulative cost per day as progressing
             * here add 7 because we will skip for next 7 days as we bought ticket already
            */
            min_cost_to_return += ((start_copy)->second * 7);
        }else{
            start = start+1;
            number_of_days_to_run--;
            /*
             * keep track of the accumulative cost per day as progressing
             * here add 1 because we will not come back to this day again
            */
            min_cost_to_return += ((start_copy)->second);
        }
    }
    /*
     * only for displaying per day cost calculated
    */
    int c=0;
    for(auto i : input_seq){

        if(c++ % 7 == 0) std::cout << "\n";
        std::cout << std::setw(3) << i.second;
    }
    std::cout << "\n";

    if(min_cost_to_return < 24)
        return min_cost_to_return;
    else
        return 24;
}

//if input is [1,2,4,5,7,29,30] then the required output is 11
//if input is [1,7,8,9,10] then the required output is 9
//if input is [1,7,8,9,10,15] then the required output is 11

class jump_trading: public Command{

public:
    void execute()
    {
        std::vector<int> i{1,2,4,5,7,29,30};
        std::cout << "calculated: " << mymincost(i) <<std::endl;
    }
};

#endif // JUMP_TRADING_H
