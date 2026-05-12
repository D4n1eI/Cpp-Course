#include <iostream>



#include <cctype>
#include <cstring>



using namespace std;



int main(){
    char first_name[20]{};
    char last_name[20]{};
    char full_name[50]{};
    char temp[50]{};
    
    // cout << "Please enter your first name: " << endl;

    // cin >> first_name;


    // cout << "Please enter your last name: " << endl;

    // cin >> last_name;


    // cout << strlen(first_name) << endl;
    // cout << strlen(last_name) << endl;

    // stpcpy(full_name,first_name);
    // strcat(full_name," ");
    // strcat(full_name,last_name);

    // cout << "Your name is " << full_name << endl;




    cout << "Enter your full name: " << endl;

    cin.getline(full_name,50);

    cout << "Your full name is " << full_name;

    return 0;
}