#include <iostream>
#include <cmath>
#include <cstdlib>


using namespace std;



void print_array(const int numbers [], size_t size){
    for (size_t i{0};i<size;i++){
        cout << numbers[i] << endl;  
    }
}



void set_array(int numbers[],size_t size, int value){
    for (size_t i{0};i<size;i++){
        numbers[i]=value;
    }
}

int main(){
    int my_scores [] = {100,200,300,400};
    print_array(my_scores,4);
    return 0;
}