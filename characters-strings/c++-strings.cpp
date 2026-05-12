#include <iostream>
#include <string>


using namespace std;



int main(){
    string s1;
    string s2 {"Frank"};
    string s3 {s2};
    string s4 {"Frank",3};
    string s5 {s3,0,2};
    string s6 (3,'X');



    s1 = "C++ Rocks!";


    string s2 {"Hello"};
    s2 = s1;


    string part1{"C++"};
    string part2{"Is cool "};

    string sentance{};

    sentance = part1 + part2;


    for (char c : s2){
        cout << c << endl;
    }


    cout << s2.substr(0,4);


    s2.find("ra");


    cout << s4.length() << endl;


    s1+="James";



    string s0;

    
}