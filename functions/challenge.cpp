#include <iostream>
#include <vector>



using namespace std;

void add_to_vector(vector<int> &vec,int n){
    vec.push_back(n);
}


int get_largest(vector<int> vec){
    int size = vec.size();
    if (size==0)return 0;
    int largest = vec.at(0);
    for (auto n : vec){
        if (n>largest) largest=n;
    }
    return largest;
}


int get_smallest(vector<int> vec){
    int size = vec.size();
    if (size==0)return 0;
    int smallest = vec.at(0);
    for (auto n : vec){
        if (n<smallest) smallest=n;
    }
    return smallest;
}


double calculate_mean(vector<int> vec){
    int size = vec.size();
    if (size==0) return 0;
    int sum{};
    for (auto n : vec){
        sum+=n;
    }
    return sum/size;
}

void print_menu(){
    cout << "\n-----------------------------"<<endl;
    cout << "P - Print numbers"<<endl;
    cout << "A - Add number"<<endl;
    cout << "M - Display the mean of the numbers"<<endl;
    cout << "S - Display the smallest number"<<endl;
    cout << "L - Display the largest number"<<endl;
    cout << "Q - Quit"<<endl;
}


void print_vector(vector<int> vec){
    if (vec.size()==0)cout<<"Vector is empty";
    else{
        cout<<"{";
        for (int i {0};i<vec.size();i++){
            if (i!=vec.size()-1){
                cout<<vec.at(i)<<",";
            }
            else{
                cout<<vec.at(i);
            }
        }
        cout<<"}";
    }
}



int main(){
    vector<int> my_vector {};
    char option{};
    bool running{true};
    while (running){
        print_menu();
        cout << "Option? ";
        cin >> option;
        switch (option)
        {
        case 'P' :
            {
                print_vector(my_vector);
                break;
            }
           
        case 'A':
            {
                int number{};
                cout<<"What number do you want to add? ";
                cin >> number;
                cout<<"Adding to vector the number " << number;
                add_to_vector(my_vector,number);
                break;
            }

        case 'M':
            {
                calculate_mean(my_vector)==0?cout<<"Vector is empty. Mean is non-existant.":cout<<"Mean is equal to "<< calculate_mean(my_vector); 
                break;
            }


        case 'L':
            {
                get_largest(my_vector)==0?cout<<"Vector is empty. Largest is non-existant.":cout<<"Largest is "<<get_largest(my_vector);
                break;
            }

        case 'S':
            {
                get_smallest(my_vector)==0?cout<<"Vector is empty. Smallest is non-existant.":cout<<"Smallest is "<<get_smallest(my_vector);
                break;
            }


        case 'Q':
            {
                cout << "Cya!";
                running=false;
            }
        default:
            break;
        }
    }





    return 0;
}