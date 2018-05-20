#include <iostream>
#include <memory>
#include "command.h"
#include "add_2_no_to_get_val.h"
#include "find_common_elemnt.h"

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
    }
    obj->execute();
    return 0;
}
