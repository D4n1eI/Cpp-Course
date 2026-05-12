#include <iostream>
#include <string>
#include <vector>
using namespace std;

void pass_by_ref1(int &num){
    num = 1000;
}


void pass_by_ref2(string &str){
    str = "Changed";
}


void pass_by_ref3(vector<string>&v){
    v.clear();
}


void print_vector(const vector<string>&v){
    for (auto c : v){
        cout << c << endl;
    }
}


int main(){
    

    return 0;
}