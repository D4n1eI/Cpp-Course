#include <iostream>
#include <string>



using namespace std;




int main(){
    int score{100};
    int other{10};
    const int*score_ptr{&score};

    // *score_ptr=86; // error
    score_ptr=&other;




    int const*score_ptr{&score};
    // *score_ptr = 2931;
    score_ptr = &other; // error
    

    return 0;
}