#include <iostream>




#include <vector>
#include <string>


using namespace std;


int main(){
    int*int_ptr{nullptr};
    int_ptr = new int;

    cout << int_ptr << endl;
    cout << *int_ptr<<endl;

    *int_ptr = 100;

    cout << *int_ptr << endl;

    delete int_ptr;




    int *array_ptr{nullptr};
    int size{};

    cout << "How big do you want the array? ";
    cin>>size;
    array_ptr = new int[size];




    delete [] array_ptr;

    return 0;


}