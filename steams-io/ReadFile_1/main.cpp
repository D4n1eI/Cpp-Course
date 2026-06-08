// Section 19
// Read File 1
// Test for file open and simple read of 3 data items
#include <iostream>
#include <fstream>

int main() {
    std::ifstream in_file{};
    std::string line{};
    in_file.open("test.txt");
    int num{};
    double total{};
    if (!in_file){
        std::cerr<<"Couldn't open file.";
        return 1;
    }
    else{
        in_file >> line >> num >> total;
        std::cout << line << std::endl
                  << num << std::endl
                  << total << std::endl;
    }

    in_file.close();
}

