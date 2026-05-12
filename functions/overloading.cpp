#include <iostream>



#include <string>





using namespace std;


int add_numbers(int,int);
double add_numbers(double,double);




int add_numbers(int a,int b){
    return a+b;
}



double add_numbers(double a,double b){
    return a+b;
}


int main(){



    cout << add_numbers(1,2) << endl;
    cout << add_numbers(1.2,2.1) << endl;


    return 0;
}