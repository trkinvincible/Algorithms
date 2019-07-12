#ifndef GENERATE_TEST_DATA_H
#define GENERATE_TEST_DATA_H

#include "command.h"
#include <fstream>
#include <stdlib.h>
#include <sstream>

class generate_test_data : public Command{

public:
    void execute()
    {

        std::ofstream f1("//home//thangrad//Documents//NUTO//step_2//res//reader_file.txt");
        std::ofstream f2("//home//thangrad//Documents//NUTO//step_2//res//writer_file.txt");

        for(int count =0;count < 10;count++){

            f1 << "/home/thangrad/Documents/NUTO/step_2/res/reader" << count+1 << ".txt" << std::endl;
        }
        for(int count =0;count < 10;count++){

            f2 << "/home/thangrad/Documents/NUTO/step_2/res/writer" << count+1 << ".txt" << std::endl;
        }
        f1.close();
        f2.close();

        std::ofstream f3;
        std::ofstream f4;
        for(int count =0;count < 10;count++){

            std::stringstream filename;
            filename << std::string("/home/thangrad/Documents/NUTO/step_2/res/writer") << count+1 << ".txt";

            f3.open(filename.str());

            for(int count=0; count < 100 ; count++){

                int key = std::rand() % 50 + 1; //between 1 and 50
                int value = std::rand() % 5000 + 1;

                f3 << key << " " << value << std::endl;
            }
            f3.close();
        }
        for(int count =0;count < 10;count++){

            std::stringstream filename;
            filename << "/home/thangrad/Documents/NUTO/step_2/res/reader" << count+1 << ".txt";

            f4.open(filename.str());

            for(int count=0; count < 100 ; count++){

                int key = std::rand() % 50 + 1; //between 1 and 50

                f4 << key << std::endl;
            }
            f4.close();
        }

    }
};

#endif // GENERATE_TEST_DATA_H
