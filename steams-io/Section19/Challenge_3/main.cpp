// Section 19
// Challenge 3
// Word counter
#include <iostream>
#include <fstream>




int main()
{

    std::cout << "Enter the substring to search for:" << std::endl;
    std::string substr{};
    std::cin >> substr;
    std::ifstream in_file{};
    in_file.open("romeoandjuliet.txt");
    int words = 0;
    int match = 0;
    while (!in_file.eof())
    {
        words++;
        std::string word{};
        in_file >> word;
        if (word.find(substr)!=std::string::npos){
            match++;
        }
    }
    std::cout<<words<<" words were searched..."<<std::endl;
    std::cout<< "The substring "<<substr<< " was found "<<match<<" times.";
    std::cout << std::endl;
    return 0;
}
