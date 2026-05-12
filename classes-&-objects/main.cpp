#include <iostream>
#include <vector>
#include <string>
#include "Account.h"

using namespace std;


int main(){
    Account frank_account{209};
    frank_account.set_balance(100);
    cout<<frank_account.get_balance();
    return 0;
}