#ifndef ITEM_H_

#define ITEM_H_


#include <string>


#include <iostream>

class Item{
        friend std::ostream& operator<< (std::ostream& os, const Item& item);

    private:
        std::string name;
        std::string type;
        int value;
        double weight;
        bool equipped;
    public:
        std::string get_name()const;
        std::string get_type()const;
        int get_value()const;
        double get_weight()const;
        bool get_equipped_status()const;
        void set_equipped_status(const bool v);
        void equip_item();
        void unequip_item();
        bool operator== (const Item &other);
        Item(std::string name,std::string type,int value,double weight,bool equipped=false);
        ~Item();
       

};

#endif