#include <iostream>



#include <vector>



using namespace std;



int main(){


    vector<int> numbers {};
    while(true){
        cout << "P - Print numbers" <<endl;
        cout << "A - Add a number" <<endl;
        cout << "M - Display Mean of Numbers" <<endl;
        cout << "S - Display Smallest Number" <<endl;
        cout << "L - Display Largets Number" <<endl;
        cout << "Q - Quit" <<endl;

        char response{};

        cin >> response;


        switch (response){
            case 'P':
                {

                    cout << "Printing numbers..."<<endl;
                    for (int num:numbers){
                        cout << num << endl;
                    }
                    break;
                }

            case 'A':
                {
                    cout << "Adding number..."<<endl;
                    cout << "What number do you wish to add to the list? "<<endl;
                    int number_to_add{};
                    cin >> number_to_add;
                    numbers.push_back(number_to_add);
                    cout << number_to_add << " was successfully added to the list."<<endl;
                    break;
                }
            
            case 'M':
                {
                    int size = numbers.size();
                    int total{};
                    for (int i{};i<size;i++){
                        total+=numbers[i];
                    }

                    double mean = total/size;

                    cout << mean << " is the mean."<<endl;
                    break;
                }

        
            case 'S':
                {
                    int smallest = numbers[0];
                    for (int num : numbers){
                        if (num<smallest){
                            smallest=num;
                        }
                    }

                    cout << smallest << " is the smallest number."<<endl;
                    break;
                }

        
            case 'L':
                {
                    int largest = numbers[0];
                    for (int num : numbers){
                        if (num>largest){
                            largest=num;
                        }
                    }

                    cout << largest << " is the largest number."<<endl;
                    break;
                }

            
            case 'Q':
                {
                    cout << "Quitting..."<<endl;
                    return 0;
                }

                
            default:
                cout << "Invalid option."<<endl;
                break;
            }
    }
    return 0;
}