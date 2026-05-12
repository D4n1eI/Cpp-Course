#include <iostream>



#include <vector>
#include <string>



using namespace std;





int main(){
    int scores[]{100,95,96};
    cout << scores << endl;
    cout << *scores << endl;



    int* score_ptr {scores};

    cout << score_ptr << endl;

    cout << *score_ptr << endl;


    return 0;
}