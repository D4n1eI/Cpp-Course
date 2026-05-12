#include "Item.hpp"


#include <string>

#include <iostream>



std::string Item::get_name()const{
    return this->name;
}

std::string Item::get_type()const{
    return this->type;
}


int Item::get_value()const{
    return this->value;
}


double Item::get_weight()const{
    return this->weight;
}


bool Item::get_equipped_status()const{
    return this->equipped;
}


void Item::set_equipped_status(const bool v){
    this->equipped=v;
}


void Item::equip_item(){
    this->equipped=true;
}


void Item::unequip_item(){
    this->equipped=false;
}




bool Item::operator==(const Item &other){
    return this->name==other.name && this->type==other.type;
}


std::ostream& operator<< (std::ostream& os, const Item& item){
    os << "{Name:"<<item.get_name()<<","<<"Type:"<<item.get_type()<<","<<"Equipped:"<<item.get_equipped_status()<<"}"<<std::endl;
    return os;
}


Item::Item(std::string m_name,std::string m_type,int m_value,double m_weight,bool m_equipped)
:name{m_name},type{m_type},value{m_value},weight{m_weight},equipped{m_equipped}{

}

Item::~Item(){

}

