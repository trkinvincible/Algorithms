#ifndef SMITHS_H
#define SMITHS_H

#include "command.h"
#include <map>

/*
char* stoupper( char* s )
{
    char* p = s;
    while (*p = toupper( *p )) p++;
    return s;
}

static bool isTwin(char *a1, char *b1)
{
    char *a = strdup(a1);
    char *b = strdup(b1);

    a = stoupper(a);
    b = stoupper(b);
    int al = strlen(a);
    int bl = strlen(b);
    int i,j;
    if(al != bl)
        return 0;

    for(i = 0;i < al;i++){
        for(j = 0;j < bl;j++){
            if(a[i] == b[j])
                b[j] = '-';
        }
    }
    for(i=0;i<bl;i++){

        printf("%c\n",b[i]);
        if(b[i] == '-')
            continue;
        else
            return false;
    }

    return true;
}

int *array2d_dup(int *array, int l, int c)
{
    int i=0,j=0;
    int **ret_arr;
    ret_arr = (int**)malloc(sizeof(int**) * l);
    for(i=0; i< l; i++){

        ret_arr[i] = (int*)malloc(sizeof(int) * c);
    }

    for(i=0;i<l;i++){
        for(j=0;j<c;j++){

            ret_arr[i][j] = array[j];
        }
        array+=c;
    }

    return ret_arr;
}
*/

#include <vector>
#include <sstream>

std::vector<std::string> split(std::string input) {

    std::vector<std::string> ret;
    std::regex r("\\w+");
    std::cout << "tokens: " << std::endl;
    for(std::sregex_iterator i = std::sregex_iterator(input.begin(), input.end(), r);
        i != std::sregex_iterator();
        ++i)
    {
        std::smatch m = *i;
        ret.push_back(m.str());
        std::cout << "#" << ret.size() << " " <<  m.str() << std::endl;
    }
    return ret;
}

std::string arrange(std::string input)
{
    std::stringstream ss;
    std::map<int,std::string> m;
    std::vector<std::string> s = split(input);

    for(std::string &word : s){

        m[word.length()] += (word + std::string(" "));
    }
    for(auto &item : m){

        auto &value = item.second;
        ss << value << " ";
    }
    return ss.str();
}

class smiths: public Command{

    void execute()
    {
        std::cout << arrange("push 4");
    }
};
#endif // SMITHS_H
