#include "CheckingAccount.h"
#include "Account.h"
#include <iostream>
#include <string>
CheckingAccount::CheckingAccount(std::string name, double balance,double fee) 
    : name{name}, balance{balance},fee{fee} {
}

bool CheckingAccount::withdraw(double amount) {
    if (balance-amount >=0) {
        balance-=amount-fee;
        return true;
    } else
        return false;
}


std::ostream &operator<<(std::ostream &os, const CheckingAccount &account) {
    os << "[CheckingAccount: " << account.name << ": " << account.balance << ": "<< account.fee <<"]";
    return os;
}
