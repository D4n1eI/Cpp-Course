#include <iostream>





using namespace std;




int main(){

    string alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key{"XYAHZJFHWTENRIGMDLSOanskdjfuryetensksaoasoasouiopixz"};

    cout << "Encrypting alphabet..." << endl;

    string cypher{};

    for (int i = 0 ; i < alphabet.length();i++){
        cypher.push_back(key[i]);
    }


    cout << "Encrypted.... is...." << cypher << endl;



    cout << "Decrypting cypher..." << endl;

    string renewed_alphabet{};

    for (int i = 0 ; i < cypher.length(); i++ ){
        renewed_alphabet.push_back(alphabet[i]);
    }

    cout << "Decrypted.... is...." << renewed_alphabet << endl;




    return 0;
}