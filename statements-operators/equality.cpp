#include <iostream>


using namespace std;


int main(){
    bool equal_result{false};
    bool not_equal_result{false};


    int num1{},num2{};

    cin >> num1 >> num2;

    equal_result == (num1==num2);

    not_equal_result = (num1!=num2);


    cout << equal_result << endl;

    cout << not_equal_result << endl;


}