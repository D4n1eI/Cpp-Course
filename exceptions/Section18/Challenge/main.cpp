#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"
#include "InsufficientFundsException.h"

using namespace std;

int main() {
    try{
        unique_ptr<Savings_Account> a1 = make_unique<Savings_Account>("ErrorProne",-100,5);
    }
    catch(const IllegalBalanceException &ex){
        std::cout<<ex.what()<<std::endl;
    }
    
    try{
        unique_ptr<Checking_Account> a2 = make_unique<Checking_Account>("ErrorProne2",-100);
    }
    catch(const IllegalBalanceException &ex){
        std::cout<<ex.what()<<std::endl;
    }
    unique_ptr<Checking_Account> a3 = make_unique<Checking_Account>("Shouldn't Work",100);
    a3->print(std::cout);
    std::cout<<std::endl;
    try{
        a3->withdraw(1000);
    }
    catch(const InsufficientFundsException &ex){
        std::cout << ex.what() <<std::endl;
    }
    a3->print(std::cout);
    std::cout<<std::endl;


    std::cout << "Program completed successfully" << std::endl;
    return 0;
}

