#include <iostream>



using namespace std;

const int small_room_cost{25};
const int large_room_cost{35};
const double tax = 0.06;
const int valid = 30;

int main(){
    cout << "Hello! How many small and large rooms would you like cleaned?";
    int small_rooms{0};
    int large_rooms{0};

    cin >> small_rooms >> large_rooms;


    cout << "Estimated for carpet cleaning service:" << endl;

    cout << "Number of small rooms: " << small_rooms << endl;

    cout << "Number of large rooms: " << large_rooms << endl;

    cout << "Price per small room: $" << small_room_cost << endl;


    cout << "Price per large room: $" << large_room_cost << endl;

    int cost = small_room_cost*small_rooms+large_room_cost*large_rooms;


    cout << "Cost: $" << cost << endl;

    double tax_applied = cost*tax;

    cout << "Tax: $"<<tax_applied << endl;


    cout << "===========================" << endl;

    cout << "Total estimate: $" << tax_applied+cost << endl;


    cout << "This estimate is valid for " << valid << " days"<< endl;




    return 0;
}