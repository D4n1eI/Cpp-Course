#include "Movie.h"
#include <iostream>



std::string Movie::get_name()const{
    return this->name;
}


std::string Movie::get_rating()const{
    return this->rating;
}


void Movie::increment_watched(){
    if (this->watched!=nullptr){
        (*(this->watched))++;
    }   
}

int Movie::get_watched()const{
    return *(this->watched);
}


void Movie::set_name(std::string other_name){
    this->name = other_name;
}

void Movie::set_rating(std::string other_rating){
    this->rating = other_rating;
}



void Movie::display_movie(){
    std::cout<<"Movie("<<this->name<<","<<this->rating<<","<<*this->watched<<")"<<std::endl;
}

Movie::Movie(std::string name,std::string rating): name(name), rating(rating),watched{new int(0)}{
    std::cout << "Movie created Movie("<<this->name<<","<<this->rating<<","<<*this->watched<<")" <<std::endl; 
}


Movie::Movie(const Movie &source) 
    : name{source.name}, rating{source.rating}, watched{new int{*source.watched}} {
    // We create a NEW memory address and copy the VALUE inside
}


Movie::~Movie(){
    delete watched;
}



