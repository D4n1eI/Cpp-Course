#include <iostream>



using namespace std;



int main(){ 

    int score{};

    cout << "Enter your score on the exam(0-100): ";
    cin >> score;

    char letterGrade = {};



    if (score >= 0 && score <=100){
        if (score>90){
            letterGrade = 'A';
        }
        else if (score>80){
            letterGrade = 'B';
        }
        else if (score>70){
            letterGrade = 'C';
        }
        else if (score>60){
            letterGrade = 'D';
        }
        else{
            letterGrade = 'F';
        }

        cout << "Your grade is " << letterGrade << "." <<endl;
        if (letterGrade=='F'){
            cout << "Sorry, you must repeat this class.";
        }
        cout << "Congrats! You passed"; 
    }
    else{
        cout << "Sorry but your grade is invalid: " << score << " is not in range." ;
    }





    cout << endl;


    return 0;
}