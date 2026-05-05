#include <iostream>
#include <iomanip>


using namespace std;



int main(){ 

    int length{},width{},height{};

    double base_cost{2.50};

    const int tier1_threshold {100};
    const int tier2_threshold {500};


    int max_dimension_length {10};


    double tier1_surcharge{0.10};
    double tier2_surcharge{0.25};


    int package_volume{};


    cout << "Welcome to the package post calculator!" << endl;
    cout << "Enter the length,width and height of the package separated by spaces: ";

    cin >> length >> width >> height;

    if (length>max_dimension_length||width>max_dimension_length||height>max_dimension_length){
        cout << "Sorry! Package rejected. Dimensions exceeded:("<<length<<","<<width<<","<<height<<").";
    }

    else{
        double package_cost = 0;
        package_volume = length*width*height;
        package_cost = base_cost;

        if (package_volume>tier2_threshold){
            package_cost += package_cost * tier2_surcharge;
            cout << "Adding tier 2 surcharge";
        }
        else if(package_volume>tier1_threshold){
            package_cost += package_cost * tier2_surcharge;
            cout << "Adding tier 1 surcharge";
        }

        cout << fixed << setprecision(2) << endl; 
        cout << "The volume of your package is: " << package_volume << endl;
        cout << "Your package will cost you $"<<package_cost<<"."<<endl;
    }   
    cout << endl;


    return 0;
}