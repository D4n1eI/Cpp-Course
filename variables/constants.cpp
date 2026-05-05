#include <iostream>

using namespace std;


const int room_cost = 30;

const double tax = 0.06;

int main(){
    cout << "Hello and welcome!" << endl;

    cout << "How many rooms would you like cleaned?" << endl;

    int rooms {0};

    cin >> rooms;

    cout << "Estimate for carpet cleaning service:"<<endl;

    cout << "Number of rooms: " <<rooms<<endl;

    cout << "Price per room: " << room_cost<<endl; 


    cout << "Cost: " << room_cost * rooms <<endl;

    cout << "Tax:" << rooms * room_cost * tax <<endl;
    
    cout << "Total:" << (room_cost*rooms)+(room_cost*rooms*tax)<<endl;  


    return 0;

}