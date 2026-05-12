#include <iostream>
#include "ExString.h"
#include <cstring>

ExString::ExString():str{nullptr}{
    str = new char[1];
    *str='\0';
}



ExString::ExString(char*s):str{nullptr}{
    if (s==nullptr){
        str = new char[1];
        *str='\0';
    }
    else{
        str = new char[std::strlen(s)+1];
        std::strcpy(str,s);
    }

}


ExString::~ExString(){
    delete [] str;
}


ExString::ExString(ExString &&obj){
    str = obj.str;
    obj.str=nullptr;
}


ExString::ExString(const ExString &source){
    str=new char[std::strlen(source.str)+1];
    std::strcpy(str,source.str);
}



char * ExString::get_str()const{
    return this->str;
}


void ExString::set_str(char* s){
    this->str=s;
}



ExString ExString::operator-()const{
    char *buff = new char[std::strlen(str)+1];
    std::strcpy(buff,str);
    for (size_t i(0);std::strlen(buff);i++){
        buff[i] = std::tolower(buff[i]);
    }
    ExString temp{buff};
    delete[] buff;
    return temp;
}



bool ExString::operator==(const ExString &rhs)const{
    return {std::strcmp(str,rhs.str)==0};
}
