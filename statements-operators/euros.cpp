#include <iostream>


using namespace std;




int main(){
    const double usd_per_euro {1.19};

    cout << "Welcome to the EUR to USD converter" << endl;
    cout << "Enter the value in euros: ";
    double euros {0.0};
    cin >> euros;

    double dollars {0.0};
    dollars=euros*usd_per_euro;
    cout << "Euros is equivalent to " << dollars << " $" <<endl;
}