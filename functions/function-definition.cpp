#include <iostream>
#include <cmath>
#include <cstdlib>


using namespace std;


const double PI {3.1416};


double calc_area_circle(double radius){
    return PI * pow(radius,2);
}

double calc_volume_cylinder(double radius,double height){
    return calc_area_circle(radius)* height;
}



void area_circle(){
    double radius{};
    cout << "Enter the radius of the circle: ";
    cin >> radius;

    cout << "The area of a circle with radius "<<radius<< " is " <<calc_area_circle(radius)<<endl;
}





void volume_cylinder(){
    double height{};
    double radius{};
    cout<< "Enter the radius and the height of the cylinder: ";
    cin >> radius >> height;

    cout << "The volume of a cylinder with radius "<<radius<<" and height "<<height<< " is "<< calc_volume_cylinder(radius,height)<<endl; 
}





int main(){
    area_circle();
    volume_cylinder();
}