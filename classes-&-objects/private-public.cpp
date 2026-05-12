#include <string>
#include <iostream>
class Player{
private:
    int age;
    std::string name{"Player"};
    int xp;


public:
    void say_hi(){
        std::cout<<"Hello";
    }

    bool is_dead();
};



int main(){
    Player frank;
    


    return 0;
}