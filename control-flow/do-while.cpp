#include <iostream>




using namespace std;



int main(){
    char selection{};

    do{
        cout << "\n--------------------"<<endl;
        cout << "1.Do this"<<endl;
        cout << "2.Do that"<<endl;
        cout << "3.Do something else"<<endl;
        cout << "Q.Quit"<<endl;


        cin >> selection;


        if (selection == '1'){
            cout << "You chose 1. Doing this!";
        }
        else if (selection == '2'){
            cout << "You chose 2. Doing that!";
        } if (selection == '3'){
            cout << "You chose 3. Doing something else!";
        }
        else if (selection == 'Q' || selection == 'q'){
            cout << "Bye!"; 
        }
        else{
            cout << "Unknown option. Try again!";
        }
    }
    while(selection!='q'&&selection!='Q');

    return 0;
}