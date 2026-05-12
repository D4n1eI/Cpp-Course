#include <iostream>


#include <vector>


using namespace std;


void double_data(int*int_ptr){
    *int_ptr*=2;
}



int main(){ 
    int value{10};
    int *val_ptr{&value};

    cout<<value<<endl;

    double_data(&value);
    cout <<value << endl;

    return 0;
}