#ifndef COND_VARIABLE_LOCK_H
#define COND_VARIABLE_LOCK_H

#include "command.h"
#include <condition_variable>
#include <thread>
#include <stack>
#include <mutex>


std::stack<int> g_stack;
std::mutex mu;
std::once_flag flag;
std::condition_variable cond_var;

class producer{
private:
    int input;
public:
    void operator()(){

        std::cout << "Enter producer" << endl;
        while(input < 2000){
            std::unique_lock<std::mutex> locker(mu);
            g_stack.push(input++);
            locker.unlock();
            cond_var.notify_all();
            std::call_once(flag,[]()
                                 {
                                   std::cout << "called only once";
                                 });
        }
    }
};
class consumer{

public:
    void operator()(){

        std::cout << "Enter Consumer" << endl;
        std::unique_lock<std::mutex> locker(mu);

        cond_var.wait(locker);
        while(!g_stack.empty()){

            std::cout << "Top element: " << g_stack.top() << endl;
            g_stack.pop();
        }
    }
};

class cond_variable_lock : public Command
{
public:
    void execute()
    {
        std::thread t1((producer()));
        std::thread t2((consumer()));

        t1.join();
        t2.join();
    }
};

#endif // COND_VARIABLE_LOCK_H
