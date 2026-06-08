// Section 19
// Write File
#include <iostream>
#include <fstream>
#include <string>

int main()  {
    std::ofstream out_file{"test.txt",std::ios::app};
    if (!out_file){
        std::cerr<<"Error";
        return 1;
    }
    std::string line{};
    std::cout<<"Enter something to write to the file:";
    std::getline(std::cin,line);
    out_file<<line;
    out_file.close();
    return 0;
}

