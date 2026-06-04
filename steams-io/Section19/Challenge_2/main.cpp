// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <fstream>
#include <iomanip>

int get_score(std::string key, std::string response)
{
    int score{};

    for (int i = 0; i < key.size(); i++)
    {
        if (key.at(i) == response.at(i))
        {
            score++;
        }
    }

    return score;
}
double calculate_average(int total, int counter){
    return static_cast<double>(total) / counter;
}
int main()
{

    std::ifstream in_file{};
    in_file.open("responses.txt");
    if (!in_file)
    {
        std::cerr << "Error opening file.";
        return 1;
    }
    std::string key{};
    in_file >> key;
    std::cout << std::setw(10) << std::left << "Student";
    std::cout << std::setw(10) << std::right << "Score";
    std::cout << std::endl;
    std::cout << "--------------------";
    std::cout << std::endl;
    int counter = 1;
    int person_counter {};
    int total{};
    while (!in_file.eof())
    {
        counter++;
        if (counter % 2 == 0)
        {
            std::string name{};
            person_counter++;
            in_file >> name;
            std::cout << std::setw(10) << std::left << name;
        }
        else
        {
            std::string response{};
            in_file >> response;
            total+=get_score(key, response);
            std::cout << std::setw(10) << std::right << get_score(key, response);
            std::cout << std::endl;
        }
    }
    std::cout << "--------------------";
    std::cout << std::endl;
    std::cout <<"Average:"<<std::setw(12)<<calculate_average(total,person_counter);
    std::cout<<std::endl;
    in_file.close();
    return 0;
}
