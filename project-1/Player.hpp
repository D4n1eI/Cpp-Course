#ifndef PLAYER_H_

#define PLAYER_H_


#include <string>

#include <iostream>
#include <vector>
#include "Item.hpp"

class Player{
        friend std::ostream& operator<< (std::ostream& os, const Player& player);

    private:
        std::string name;
        int gold;
        std::vector<Item*> inventory;
        Item* equipped_weapon;

    public:
        std::string get_name()const;
        int get_gold()const;
        std::vector<Item*> &get_inventory();
        Item * get_equipped_weapon()const;
        Player(std::string name, int gold);
        ~Player();
        void equip_item(Item* item);
        void unequip_item();
        void add_item(Item* item);
        void drop_item(const std::string& item_name);
};

#endif