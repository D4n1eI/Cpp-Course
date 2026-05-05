#include <iostream>



using namespace std;





int main(){

    cout << "Enter a number: " <<endl;


    int number {0};
    cin >> number;


    int target = 50;



    if (number < target){
        cout << "Its lower than the target!";
    }
    else{
        cout << "Its greater than the target!";
    }

    return 0;
}