#include <iostream>


#include <vector>


using namespace std;




void reverse_array(int* arr, int size) {
    //-- Write your code below this line 
    int* first=arr;
    int* last =arr+size-1;
    cout <<first<<endl;
    cout <<last<<endl;
    while(first<last){
        int temp = *first;
        *first = *last;
        *last = temp;
        first++;
        last--;
    }
    //-- Write your code above this line
}


std::string reverse_string(const std::string &str) {
    std::string reversed;
    reversed.reserve(str.size());
    // Write your code below this line 
    char first_char = str[0];
    char last_char = str[str.size()-1];
    char* first = &first_char;
    char* last = &last_char;

    while (last >= first) {
        reversed += *last; 
        last--;          
    }

    // Write your code abocve this line
    return reversed;
}

int main(){
    string my_str{"Hello World!"};
    cout << reverse_string(my_str);
    return 0;
}