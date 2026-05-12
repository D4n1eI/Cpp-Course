// You do NOT have to write a main() function. The main() function is written by me
// behind the scenes to call your function and test your code.
#include <iostream>
#include <string>

std::string reverse_string(const std::string &str) {
    if (str.empty()) return "";

    std::string reversed = "";
    
    const char* ptr = str.data() + str.size() - 1;

    for (int i = 0; i < str.size(); i++) {
        reversed += *ptr; /
        ptr--;            
    }
    
    return reversed;
}


int main(){
    std::string hello = "Hello";
    std::string reversed = reverse_string(&hello);
    std::cout <<reversed;



    return 0;
}