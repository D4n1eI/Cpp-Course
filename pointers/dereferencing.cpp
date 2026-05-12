#include <iostream>
#include <string>



using namespace std;




int main(){
    int int_num{20};

    int *int_prt{&int_num};
    

    cout << *int_prt << endl;


    *int_prt = 200;

    cout << *int_prt << endl;

    return 0;
}