#include <iostream>
#include <memory>
#include "command.h"
#include "add_2_no_to_get_val.h"
#include "find_common_elemnt.h"
#include "cond_variable_lock.h"
#include "bfs_binarytree.h"
#include "generate_test_data.h"
#include "learn_variadic_templates.h"
#include "try_cplusplus_17.h"
#include "bbm_interview_questions.h"

using namespace std;


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
    }

    obj->execute();
    return 0;
}
