// Simple Account 
#ifndef _CHECKING_ACCOUNT_
#define _CHECKING_ACCOUNT_
#include <iostream>
#include <string>
#include "Account.h"

class CheckingAccount : public Account {
    friend std::ostream &operator<<(std::ostream &os, const CheckingAccount &account);
private:   
    static constexpr const char *def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;
protected:
    std::string name;
    double balance;
    double fee;
public:
    CheckingAccount(std::string name = def_name, double balance = def_balance,double fee=1.5);
    // Account(std::string name = "Unamed Account", double balance = 0.0);
    bool withdraw(double amount);
};
#endif