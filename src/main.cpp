#include <iostream>
#include <memory>
#include "../hdr/command.h"
#include "../hdr/add_2_no_to_get_val.h"
#include "../hdr/find_common_elemnt.h"
#include "../hdr/cond_variable_lock.h"
#include "../hdr/bfs_binarytree.h"
#include "../hdr/generate_test_data.h"
#include "../hdr/learn_variadic_templates.h"
#include "../hdr/try_cplusplus_17.h"
#include "../hdr/bbm_interview_questions.h"
#include "../hdr/move_schematics.h"
#include "../hdr/visa_interview.h"
#include "../hdr/jump_trading.h"
#include "../hdr/razer_interview.h"
#include "../hdr/learn_atomics.h"
#include "../hdr/smiths.h"
#include "../hdr/boost_asio.h"
#include "../hdr/practice.h"
#include "../hdr/altonomy.h"
#include "../hdr/qt_network.h"

int main(int argc, char *argv[])
{
    std::unique_ptr<Command> obj;
    int prog = atoi(argv[1]);

    switch(prog){

    case 1:
    {
        obj.reset(new add_2_no_to_get_val());
    }
        break;
    case 2:
    {
        obj.reset(new find_common_elemnt());
    }
        break;

    case 3:
    {
        obj.reset(new cond_variable_lock());
    }
        break;

    case 4:
    {
        obj.reset(new bfs_binarytree());
    }
        break;

    case 5:
    {
        obj.reset(new generate_test_data());
    }
        break;

    case 6:
    {
        obj.reset(new learn_variadic_templates());
    }
        break;
    case 7:
    {
        obj.reset(new try_cplusplus_17());
    }
        break;

    case 8:
    {
        obj.reset(new bbm_interview_questions());
    }
        break;

//    case 9:
//    {
//        obj.reset(new move_schematics());
//    }
//        break;

    case 10:
    {
        obj.reset(new visa_interview());
    }
        break;

    case 11:
    {
        obj.reset(new jump_trading());
    }
        break;
    case 12:
    {
        obj.reset(new razer_interview());
    }
        break;
    case 13:
    {
        obj.reset(new learn_atomics());
    }
        break;

    case 14:
    {
        obj.reset(new smiths());
    }
        break;
    case 16:
    {
        obj.reset(new practice());
    }
        break;
    case 17:
    {
        obj.reset(new boost_asio());
    }
        break;
    case 18:
    {
        obj.reset(new altonomy());
    }
        break;

    case 19:
    {
        obj.reset(new qt_network());
    }
        break;
    }

    obj->execute();
    return 0;
}
