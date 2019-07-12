#ifndef RAZER_INTERVIEW_H
#define RAZER_INTERVIEW_H

#include "command.h"


template<typename T>
struct sum{
    static void foo(T op1,T op2){

        std::cout << "nothng";
    }
};

#include <algorithm>
#include <vector>
#include <functional>

int CountPairs(std::vector<int> v,int k)
{
    std::size_t count=0;
    std::sort(v.begin(),v.end(),std::less_equal<int>());
    auto it = std::unique(v.begin(),v.end());
    //v.resize( std::distance(v.begin(),it) );
    std::size_t s = v.size();
    for(int i=0;i<s;i++){
        for(int j=i+1;j < s;j++){

            int diff = abs(v[i]  - v[j]);
            if(diff == k)
                count++;
        }
    }
    return count;
}
class razer_interview : public Command{
    void execute()
    {
        std::cout << CountPairs({1,1,2,2,3,3},1) << std::endl;
        //std::cout << "razer_interview << std::endl";
    }
};

#endif // RAZER_INTERVIEW_H
