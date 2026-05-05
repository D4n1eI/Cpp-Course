#include <iostream>

#include <vector>


#include <iomanip>


using namespace std;





int main(){
    
    // int scores[] {10,20,30};


    // for (auto score : scores){
    //     cout <<score<<endl;
    // }



    // vector <double> temperatures {87.9,77.9,90.9,72.5};


    // double avg{};

    // double total{0};


    // for (auto temp : temperatures){
    //     total+=temp;
    // }

    // if (temperatures.size()!=0){
    //     avg = total/temperatures.size();
    // }

    // cout << fixed << setprecision(1);
    // cout << "Average is " << avg;



    // for (auto val : {1,2,3,4,5}){
    //     cout << val << endl;
    // }



    // for (auto c : "Fr ank"){
    //     if (c!=' '){
    //         cout << c;
    //     }   
    // }


    for (auto c:"This is a test"){
        (c == ' ')?cout <<"\t":cout<<c;
    }
    
    return 0;
}