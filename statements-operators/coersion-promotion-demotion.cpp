#include <iostream>


using namespace std;




int main(){

    int num1 {};
    int num2 {};
    int num3 {};


    cout << "Enter three numbers: " << endl;

    cin >> num1 >> num2 >> num3;

    int sum = num1+num2+num3;

    double average = static_cast<double>(sum)/3;


    cout << "Numbers: " <<  num1 << num2 << num3 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;



    return 0;
}