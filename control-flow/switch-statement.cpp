#include <iostream>



using namespace std;






int main(){
    char letter_grade{};


    cout << "Enter the letter grade you expect from the exam: ";


    cin >> letter_grade;



    switch (letter_grade){
    case 'a':
    case 'A':  
        cout << "You need a 90 or above... study hard!" <<endl;
        break;
    case 'b':
    case 'B':
        cout << "You need 80 to 80 for a B... go study!" << endl;
        break;

    case 'c':
    case 'C':
        cout << "You need 70-79 for an average grade." <<endl;
        break;

    case 'd':
    case 'D':
        cout << "Hmm, you should strive for a better grade hum? All you need is 60-69." <<endl;
        break;

    case 'f':
    case 'F':
        {
            char confirm{};
            cout << "Are you sure you want an F? ";
            cin >> confirm; 


            if (confirm == 'y' || confirm == 'Y'){
                cout << "Okay, I guess you didn't study."<<endl;
                break;
            } 
            else if (confirm == 'n' || confirm == 'N' ){
                cout << "Good, go study!"<<endl;
                break;
            }
            else{
                cout << "Illegal choice."<<endl;
                break;
            }
        }
        
    default:
        cout << "Sorry! That's not a valid grade.";
        break;
    }


    return 0;
}