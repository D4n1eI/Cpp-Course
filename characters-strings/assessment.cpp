#include <iostream>
#include <string>




using namespace std;




int main(){
    cout << "Pyramid.";
    cout << "Enter a string: ";
    string str{};
    cin >> str;

    int size = str.size();


    for (int i{0};i<size;i++){
        cout<<string(size-i,' ');
        for (int j{0};j<=i;j++){
            cout<<str.at(j);
        }
        for (int k{i-1};k>=0;k--){
            cout<<str.at(k);
        }
           
        cout << endl;
    
    }

    return 0;
}