#include <iostream>


#include <vector>


using namespace std;




int main(){
    int*int_ptr{nullptr};

    int_ptr = new int;


    cout << int_ptr << endl;

    delete int_ptr;




    cout << "How many doubles do you need? ";
    size_t size{0};

    double *double_ptr{nullptr};

    cin >> size;

    double_ptr = new double[size];

    cout << double_ptr << endl;

    delete [] double_ptr;

    return 0;
}