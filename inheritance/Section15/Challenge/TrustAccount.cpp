#include "TrustAccount.h"
#include "Account.h"
#include <iostream>
#include <string>
TrustAccount::TrustAccount(std::string name, double balance,double interest_rate) 
    : name{name}, balance{balance},interest_rate{interest_rate} {
}


bool TrustAccount::deposit(double amount) {
    if (amount < 0) 
        return false;
    else {
        if (amount>5000){
            balance += amount + 50;
            return true;
        }
        balance += amount;
        return true;
    }
}


bool TrustAccount::withdraw(double amount) {
    static int count = 0;
    if (count<3){
           if (balance-amount >=0) {
                balance-=amount;
                return true;
        } else
            return false;
    }
    return false;
 
}


std::ostream &operator<<(std::ostream &os, const TrustAccount &account) {
    os << "[TrustAccount: " << account.name << ": " << account.balance << ":" <<account.interest_rate<<"]";
    return os;
}
