#include <iostream>
#include <bits/stdc++.h>
#include <string>




using namespace std;





int main(){
    cout << "Enter a string to build the pyramid off of: ";

    string pyramid_string{};

    cin >> pyramid_string;

    int size = pyramid_string.length();

    for (int i = 0 ; i < size ; i++){
        string level{} ;
        
        int space_number = (size - (i+1));
       

        cout << string( space_number, ' ');
        for (int j = 0 ; j <= i; j++){
            level.push_back(pyramid_string[j]);
        }
        for (int k = i; k>0 ;k--){
            level.push_back(pyramid_string[k-1]);
        }
        cout << level;
        cout <<endl;
    }



    return 0;
}