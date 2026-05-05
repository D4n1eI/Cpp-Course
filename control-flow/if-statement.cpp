#include <iostream>

using namespace std;





int main(){


    int number {0};

    cin >> number;

    const int min{10};
    const int max{100};

    cout << "Enter a number between " <<min << " and " << max << ": " << endl;

    cin >> number;


    if (number >= min){
        cout << "\n==================If statement 1=======================";
        cout << number << " is greater than " << min << endl;
        int dif {number-min};
        cout << number << " is " << dif << " greater than " << min << endl;
    }

    if (number <= max){
        cout << "\n==================If statement 2=======================";
        cout << number << " is less than " << max << endl;
        int dif {max-number};
        cout << number << " is " << dif << " less than " << max << endl;
    }


    if (number >= min && number <= max){
        cout << "\n==================If statement 3=======================";
        cout << number << " in range. ";
        cout << "This mean statement 1 and 2 must also display" << endl;
    }


    if (number == min || number == max){
        cout << "\n==================If statement 4=======================";
        cout << number << " is right on a boundary. ";
        cout << "All statements must fire";
    }

    return 0;
}