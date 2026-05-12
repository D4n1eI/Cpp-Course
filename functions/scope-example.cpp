#include <iostream>




using namespace std;

int num{100};



void global_example(){
    cout << num;
}





void static_local_example(){
    static int num{5000};
    cout << num;
    num += 100;
    cout << num;
}
void local_example(int x){
    int num{1000};
    num = x;

    cout << num;


}


int main(){
    int num{100};
    int num2{1000};

    cout << num;
    
    
    {
        int num{10000};
        cout << num;
    }


    cout << num;

    return 0;
}