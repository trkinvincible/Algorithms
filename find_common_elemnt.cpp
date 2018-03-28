#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(int argc, char ** argv)
{
	std::set<int> output;

	std::vector<int> v1 = { 2, 3, 6, 7, 10, 13 };
	std::vector<int> v2 = { 3, 6, 9, 11, 13, 14 };
	std::vector<int> v3 = { 5, 6, 10, 11, 13, 15 };

    typedef std::vector<std::vector<int>> vector_vector;
    vector_vector vv = { v1, v2, v3 };

	std::vector<int>::iterator itr;

    //Pseudo Code
	/*[START]
	5-highest find the upper bound in other two vectors

	6 7 10 13
	6 9 11 13 14
    5 6 10 11 13 15

	if all 3 same its move as common elemnt in seperate container

	6-highest

	6 7 10 13
	6 9 11 13 14
	6 10 11 13 15

	if all 3 same its move as common elemnt in seperate container. re-order vector again

	7 10 13
	9 11 13 14
	10 11 13 15

	10 - highest

	10 13
	11 13 14
	10 11 13 15

	11 - highest

	13
	11 13 14
	11 13 15

	13 - highest

	-
	13 14
    13 15

	[END]*/

	//pre-process the vectors
	while (true)
	{
        if (vv.at(0).at(0) == vv.at(1).at(0) && vv.at(1).at(0) == vv.at(2).at(0)){

            output.insert(vv.at(0).at(0));
            vv.at(0).erase(vv.at(0).begin());
            vv.at(1).erase(vv.at(1).begin());
            vv.at(2).erase(vv.at(2).begin());
        }

        if (vv.at(0).empty() || vv.at(1).empty() || vv.at(2).empty())
            break;

        int max_val = std::max(std::max(vv.at(0).at(0), vv.at(1).at(0)), vv.at(2).at(0));
        for (auto &item : vv){

            itr = std::lower_bound(item.begin(), item.end(), max_val);
            item.erase(item.begin(), itr);
		}
	}

    std::cout << "Common Elements found are: ";

	for (auto i : output){

        std::cout << i << "\t";
	}
    std::cout << endl;

	return 0;
}
