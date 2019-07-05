#ifndef LEARN_ATOMICS_H
#define LEARN_ATOMICS_H

#include "command.h"
#include <vector>
#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <boost/atomic/atomic.hpp>

std::atomic<std::array<int,40>> cnt;
std::array<int,40> test_arr;
std::atomic<int> g=1;
std::mutex m;
void f()
{
    auto a = cnt.load(std::memory_order_relaxed);
    a.fill(g);
    cnt.store(a,std::memory_order_relaxed);
    test_arr.fill(g);
    g++;

    std::lock_guard<std::mutex> lk(m);
    std::cout << "\natomic array:" << std::endl;
    for(auto i : cnt.load())
        std::cout << i << " ";

    std::cout << "\ntest array:" << std::endl;
    for(auto i : test_arr)
        std::cout << i << " ";

     std::cout << std::endl;
}

class learn_atomics : public Command{

    void execute()
    {
        auto start = std::chrono::high_resolution_clock::now();

        std::vector<std::thread> v;
        for (int n = 0; n < 20; ++n) {

            v.emplace_back(f);
        }
        for (auto& t : v) {
            t.join();
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    }
};

#endif // LEARN_ATOMICS_H
