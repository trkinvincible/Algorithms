#include <iostream>
#include <memory>
#include "command.h"
#include "add_2_no_to_get_val.h"
#include "find_common_elemnt.h"
#include "cond_variable_lock.h"
#include "bfs_binarytree.h"

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
    }
    obj->execute();
    return 0;
}
