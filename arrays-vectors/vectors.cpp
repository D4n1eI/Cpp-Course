#include <iostream>
#include <vector>

using namespace std;



int main(){
    vector <char> vowels(5);
    vector <int> test_scores(10);
    vector <double> hi_temperatures {365,80.0};

    vector <int> scores {100,95,90,85,80};

    cout << "First " << scores[0] << endl;


    cout << "First " << scores.at(0) << endl;


    scores.push_back(300);



    cout << scores.data() << endl;


    vector <int> numbers (300,1);

    cout << numbers.size() << endl;
    cout << numbers.at(5) << endl;


    vector <vector<int>> myvector{
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
    };


    cout << myvector.at(0).at(2);
}