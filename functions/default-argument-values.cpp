#include <iostream>
#include <cmath>
#include <cstdlib>

#include <string>
using namespace std;


double calc_cost(double base_cost, double tax_rate=0.6,double shipping = 3.50);


void greeting(string str,string prefix = "Mr.",string suffix = "");


double calc_cost(double base_cost, double tax_rate,double shipping){
    return base_cost+=(base_cost*tax_rate)+shipping;
}



void greeting(string str,string prefix,string suffix){
    cout << "Hello " << prefix << " " << str << " "<< suffix;
}


int main(){

    int cost{0};
    cost = calc_cost(100.0,0.08,4.25);


    cout << cost << endl;



    cost = calc_cost(100.0,0.08);

    cout << cost << endl;


    cost = calc_cost(100.0);
    cout <<cost<<endl;

    greeting("Glenn Jones","Dr.","M.D");
    return 0;
}