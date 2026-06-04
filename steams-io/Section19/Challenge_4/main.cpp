// Section 19
// Challenge 4
// Copy Romeo and Juliet with line numbers
#include <iostream>
#include <fstream>


int main() {
    std::ifstream in_file{};
    in_file.open("romeoandjuliet");
    if (!in_file){
        std::cerr<<"Error opening file.";
        return 1;
    }


    std::ofstream out_file{};
    out_file.open("romeoandjulietwithlines.txt");


    int lines{1};
    std::string line{};
    while (!in_file.eof()){
        out_file << lines <<" ";
        lines++;
        std::getline(in_file,line);
        out_file << line << std::endl;
    }
    std::cout<<"Copied with line numbers.";
    return 0;
}

