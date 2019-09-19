#ifndef TRY_CPLUSPLUS_17_H
#define TRY_CPLUSPLUS_17_H

#include "command.h"
#include <iostream>
#include <variant>
#include <algorithm>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <boost/algorithm/cxx17/reduce.hpp>
#include <queue>
#include <ostream>
#include <tuple>
#include <regex>
#include <vector>
#include <climits>
#include <string>
#include <functional>
#include <future>

/*
class Entry
{
private:
    std::queue<std::std::string> mPassportList;
public:
    void enter(std::std::string passportNumber)
    {
        mPassportList.push(passportNumber);
    }

    std::std::string leave()
    {
        if(mPassportList.empty())
            throw std::logic_error("Check point is empty");

        std::std::string ppt = mPassportList.front();
        mPassportList.pop();
        return ppt;
    }
};

class Candies
{
public:
    static int countRec(int choc, int wrap)
    {
        if (choc < wrap)
            return 0;

        int newChoc = choc/wrap;

        return newChoc + countRec(newChoc + choc%wrap,
                                  wrap);
    }

    static int countMaxChoco(int money,int wrap)
    {

        int choc = money;

        return choc + countRec(choc, wrap);
    }
    static int countCandies(int startingAmount, int newEvery)
    {
        countMaxChoco(startingAmount, newEvery);
    }
};

class UniqueNumbers
{
public:
    static std::vector<int> findUniqueNumbers(const std::vector<int>& numbers)
    {
        std::vector<int> copy_vec = numbers;

        auto it = std::copy_if (numbers.begin(), numbers.end(),
                                copy_vec.begin(),
                                [&](int i)
                                {
                                    std::vector<int>::iterator it;
                                    it = std::find(copy_vec.begin(),copy_vec.end(),i);
                                    if (it != copy_vec.end()){
                                        copy_vec.push_back(i);
                                        return true;
                                    }else{
                                        return false;
                                    }
                                }
                                );

        return copy_vec;
    }
};
*/

#define FIRST_SMALLEST 0
#define SECOND_SMALLEST 1
#define THIRD_SMALLEST 2


int print(std::string input)
{
    int operations = input.length();
    //base case
    if(input.length()==0)
        return 0;
    int size = input.length();
    if(size==1)
        return 1;

    int start_index=0;
    int end_index =0;
    while(start_index<size){
        char c = input.at(start_index);
        while(end_index<size && c==input.at(end_index)){
            end_index++;
        }
        //if end_index has reached to the end of the std::string means recursive call is required only for the 0 to start_index
        if(end_index>=size) {
            operations =std::min(operations,print(input.substr(0, start_index)) + 1);
        }
        else {
            //else recursive call to rest of the std::string left
            operations = std::min(operations,print(input.substr(0, start_index) + input.substr(end_index, size)) + 1);
        }
        //put the start_index a the current end_index for the next iteration
        start_index=end_index;
    }
    return operations;
}

#include <algorithm>
int solution(std::vector<int> &A) {

    std::sort(A.begin(),A.end());
    std::vector<int> temp;
    std::unique_copy(A.begin(),A.end(),std::back_inserter(temp));
    uint i =0;
    int concecutive_number=1;
    while(true){

        if(i >= temp.size()){

            return concecutive_number;
        }
        if(i < temp.size() && temp.at(i) != concecutive_number){
            break;
        }
        i++;
        concecutive_number++;
    }
    return concecutive_number;
}

void createMaxHeap(std::vector<int> &i,int n,int end_index)
{
    /*
     * checks for one node at a time
    */
    int largest_element_index = end_index;
    int left_child_index = 2*end_index + 1;
    int right_child_index = 2*end_index + 2;

    if(left_child_index < n && i.at(left_child_index) > i.at(largest_element_index))
        largest_element_index = left_child_index;

    if(right_child_index < n && i.at(right_child_index) > i.at(largest_element_index))
        largest_element_index = right_child_index;

    if(largest_element_index != end_index){

        //pivot has been moved
        std::swap(i.at(end_index),i.at(largest_element_index));
        createMaxHeap(i,n,largest_element_index);
    }
}

void heapsort(std::vector<int> &input)
{
    int n = input.size();
    //loop to check every node is satisfying the max heap property
    for(int i = 0;i < n ; i++){

        createMaxHeap(input,n,i);
    }
    for(int i=n-1;i>=0;i--){

        std::swap(input.at(0),input.at(i));
        //ignore last node
        createMaxHeap(input,i,0);
    }
}

struct something{


    std::string have_named_parameters(int a,char b){

        return " ";
    }

    std::string don_have_named_parameters(){

        return " ";
    }
};

class try_cplusplus_17 : public Command{

    void execute()
    {

        std::unique_ptr<int[]> ptr1 = std::make_unique<int[]>(5);
        std::unique_ptr<int[]> ptr2(new int[5]());


        // something s;
        // std::packaged_task<std::string()> task1(std::bind(&something::don_have_named_parameters,s));
        // std::packaged_task<std::string(int,char)> task2(std::bind(&something::have_named_parameters,s,
        //                                                           1,
        //                                                           std::placeholders::_1));

        // std::thread(std::move(task2),1,'2');

//        std::string input = "aabbccaa";
//        std::cout << "Minimum Operations: " << print(input);

//        std::vector<int> v{1, 3, 6, 4, 1, 2};
//        std::cout << solution(v) << std::endl;

        std::vector<int> v{12, 11, 13, 5, 6, 7};
        std::make_heap(v.begin(),v.end());
        for(auto i:v){
            std::cout << i << " ";
        }
        std::cout << std::endl;
        v.pop_back();
        for(auto i:v){
            std::cout << i << " ";
        }
        std::cout << std::endl;
        std::sort_heap(v.begin(),v.end());
        //heapsort(v);
        for(auto i:v){
            std::cout << i << " ";
        }
    }
};
#endif // TRY_CPLUSPLUS_17_H
