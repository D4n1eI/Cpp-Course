#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

void pass_by_value1(int num);
void pass_by_value2(string s);
void pass_by_value3(vector<string> vec);
void print_vector(vector<string> vec);


void pass_by_value1(int num){
    num = 1000;
}


void pass_by_value2(string s){
    s = "Changed";
}


void pass_by_value3(vector<string>vec){
    vec.clear();
}


void print_vector(vector<string> vec){
    for (auto s : vec){
        cout << s << endl;
    }
}

int main(){
    return 0;
}