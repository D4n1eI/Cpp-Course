#include <iostream>


using namespace std;







int main(){
    int num{10};
    cout << num << endl;
    cout << sizeof num << endl;
    cout << &num << endl;



    int *p;

    cout << p << endl;
    cout << &p << endl;
    cout << sizeof p << endl;

    p = nullptr;


    cout << p <<endl;



    int score{10};
    double high_temp{100.8};


    int *score_ptr{nullptr};

    score_ptr = &score;

    cout << score << endl;  
    cout << &score << endl; // Should be the same
    cout << score_ptr <<endl; // Should be the same


    



    return 0;
}