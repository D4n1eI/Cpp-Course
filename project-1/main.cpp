#include "Item.hpp"

#include <iostream>

#include "Player.hpp"

int main(){

    Player player = Player("Johane",0);
    std::cout << "Welcome!";
    std::cout << player;

    bool proceed = true;
    while(proceed){
        std::cout<<"||Inventory Management System||"<<std::endl;
        std::cout<<"||1.Add Item                 ||"<<std::endl;
        std::cout<<"||2.Remove Item              ||"<<std::endl;
        std::cout<<"||3.View Items               ||"<<std::endl;
        std::cout<<"||4.Equip Item               ||"<<std::endl;
        std::cout<<"||5.Show Total Weight        ||"<<std::endl;
        std::cout<<"||6.Quit                     ||"<<std::endl;

        
        int response{};
        std::cout<<"Choice:";
        std::cin>>response;

        switch (response)
        {
        case 1:
            {
                std::cout<<"Item name? "<<std::endl;
                std::string item_name{};
                std::cin>>item_name;

                std::cout<<"Item type? "<<std::endl;
                std::string item_type{};
                std::cin>>item_type;


                std::cout<<"Item value? "<<std::endl;
                int item_value{};
                std::cin>>item_value;

                std::cout<<"Item weight? "<<std::endl;
                double item_weight{};
                std::cin>>item_weight;

                Item * item = new Item(item_name,item_type,item_value,item_weight);
                player.get_inventory().push_back(item);
                break;
            }
          
        case 2:
            {
                std::cout<<"Item name? "<<std::endl;
                std::string item_name{};
                std::cin>>item_name;
                player.drop_item(item_name);
                break;
            }

        case 3:
            {
                for (Item* item:player.get_inventory()){
                    std::cout << *item <<std::endl;
                }
                break;
            }

        case 4:
            {
                std::cout<<"Item name? "<<std::endl;
                std::string item_name{};
                std::cin>>item_name;
                for (Item* it : player.get_inventory()){
                    if (it->get_name()==item_name){
                        player.equip_item(it);
                    }
                }
                break;
            }

        case 5:
            {
                double total = 0;

                for (Item* item : player.get_inventory()){
                    total+=item->get_weight();
                }
                std::cout << "Total weight is " << total << std::endl;
                break;
            }

        case 6:
            std::cout<<"Goodbye!";
            proceed=false;
            for (Item * item : player.get_inventory()){
                delete item;
            }
            break;
        default:
            break;
        }
    }

    return 0;
}