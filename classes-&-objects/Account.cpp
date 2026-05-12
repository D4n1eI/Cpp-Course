#include "Account.h"


void Account::set_balance(double bal){
    balance = bal;
}

double Account::get_balance(){
    return balance;
}


Account::Account(double bal):Account{balance=bal}{
}

Account::~Account(){

}


Account::Account(double bal,double n):Account{bal,n}{
}