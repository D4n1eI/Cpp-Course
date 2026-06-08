// Section 18
// Miles per Gallon - Function - Rethrow
#include <iostream>
#include <vector>



double calculate_mpg(int miles,int gallons){
    if (gallons == 0){
        throw 0;
    }
    if (miles<0 || gallons <0){
        throw std::string{"Negative value errors"};
    }
    return static_cast<double>(miles)/gallons;
}



int main()
{
    int miles{};
    int gallons{};
    double miles_per_gallon{};

    std::cout << "Enter the miles driven: ";
    std::cin >> miles;
    std::cout << "Enter the gallons used: ";
    std::cin >> gallons;

    try{
        miles_per_gallon = calculate_mpg(miles,gallons);
    }
    catch(int &e){
        std::cerr<<"Sorry, can't divide by zero.";
    }
    catch(std::string &e){
        std::cerr<<e<<std::endl;
    }
    catch(...){
        std::cerr<<"Unknown exception"<<std::endl;
    }

    std::cout << "Result is " << miles_per_gallon << std::endl;

    return 0;
}
