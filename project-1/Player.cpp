#include "Player.hpp"
#include "Item.hpp"




Player::Player(std::string m_name, int m_gold)
    : name{m_name}, gold{m_gold}
{
    equipped_weapon = new Item("None", "None", 0, 0);
}


Player::~Player() {
    for (Item* iptr : inventory){
        delete iptr;
    }
    inventory.clear();
    delete equipped_weapon;
    equipped_weapon = nullptr;
}



std::string Player::get_name()const{
    return this->name;
}


std::vector<Item*>& Player::get_inventory(){
    return inventory;
}



int Player::get_gold()const{
    return this->gold;
}

Item* Player::get_equipped_weapon()const{
    return this->equipped_weapon;
}

void Player::equip_item(Item *item){
    this->equipped_weapon = item;
    item->set_equipped_status(true);
}

void Player::unequip_item(){
    this->equipped_weapon = nullptr;
}
void Player::add_item(Item* item){
    inventory.push_back(item);
}


void Player::drop_item(const std::string& item_name){
    for (auto it = inventory.begin(); it != inventory.end(); ++it){
        if ((*it)->get_name() == item_name){
            inventory.erase(it);
            return; 
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << "Player: " << player.name << std::endl;

    os << "Inventory: ";

    for (const auto& item : player.inventory) {
        os << item << " ";
    }

    os << std::endl;

    if (player.equipped_weapon)
        os << "Item: " << *player.equipped_weapon << std::endl;
    else
        os << "Item: None" << std::endl;
    return os;
}