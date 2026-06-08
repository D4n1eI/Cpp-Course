// Simple Account 
#ifndef _TRUST_ACCOUNT_H
#define _TRUST_ACCOUNT_H
#include <iostream>
#include <string>
#include "Account.h"

class TrustAccount : public Account {
    friend std::ostream &operator<<(std::ostream &os, const TrustAccount &account);
private:   
    static constexpr const char *def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;

protected:
    std::string name;
    double balance;
    double interest_rate;
public:
    TrustAccount(std::string name = def_name, double balance = def_balance,double interest_rate=1);
    // Account(std::string name = "Unamed Account", double balance = 0.0);
    bool deposit(double amount);
    bool withdraw(double amount);
};
#endif