#include <iostream>



#include <vector>
#include <string>



using namespace std;





int main(){
    int scores[]{100,95,96,68,-1};
    int*scores_ptr{scores};
    while(*scores != -1){
        cout << *scores_ptr << endl;
        scores_ptr++; 
    }
    return 0;
}