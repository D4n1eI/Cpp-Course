#include <iostream>
#include <cmath>
#include <cstdlib>


using namespace std;



int main(){
    cout << "Enter a number: ";
    int number{};
    cin >> number;

    cout << sqrt(number)<<endl;
    cout << cbrt(number)<<endl;
    cout << sin(number)<<endl;
    cout << cos(number)<<endl;
    cout << ceil(number)<<endl;
    cout << floor(number)<<endl;
    cout << round(number)<<endl;
    cout << pow(number,4)<<endl;    

    int random{};
    srand(time(nullptr));
    for (int i = 1 ; i <= 10 ; ++i){
        random = rand()%6+1;
        cout << random << endl;
    }

    return 0;
}