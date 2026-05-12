#include <cstring>
#include <iostream>
#include "Mystring.h"




Mystring::Mystring() : str{nullptr} {
    str = new char[1];
    *str = '\0';
}



Mystring::Mystring(const char*s):str{nullptr}{
    if (s==nullptr){
        str = new char[1];
        *str='\0';

    }else{
        str = new char[std::strlen(s)+1];
        std::strcpy(str,s);
    }
}



Mystring::Mystring(const Mystring &source):str{nullptr}{
    str = new char[std::strlen(source.str)+1];
    std::strcpy(str,source.str);
}


Mystring::~Mystring(){
    delete [] str;
}


void Mystring::display()const{
    std::cout<<str<<" : "<<get_length()<<std::endl;
}


int Mystring::get_length()const{
    return std::strlen(str);
}


const char* Mystring::get_str()const{
    return str;
}



Mystring&Mystring::operator=(const Mystring &rhs){
    std::cout << "Copy assignment" << std::endl;

    if (this==&rhs){
        return *this;
    }

    delete [] str;

    str = new char[std::strlen(rhs.str)+1];

    std::strcpy(this->str,rhs.str);
    return *this;
}



Mystring&Mystring::operator=(Mystring &&rhs){
    std::cout<<"Using move assignment"<<std::endl;
    if (this==&rhs){
        return *this;
    }

    delete [] str;

    str = rhs.str;

    rhs.str = nullptr;
    return *this;
}


bool Mystring::operator==(const Mystring &rhs)const{
    return {std::strcmp(str,rhs.str)==0};
}


Mystring Mystring::operator-()const{
    char *buff = new char[std::strlen(str)+1];
    std::strcpy(buff,str);
    for (size_t i(0);std::strlen(buff);i++){
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp{buff};
    delete[] buff;
    return temp;
}


Mystring Mystring::operator+(const Mystring &rhs)const{
    char * buff = new char[std::strlen(str)+std::strlen(rhs.str)+1];
    std::strcpy(buff,str);
    std::strcat(buff,rhs.str);
    Mystring temp{buff};
    delete [] buff;
    return temp;
}






bool operator==(const Mystring &lhf , const Mystring &rhs){
    std::strcmp(lhf.str,rhs.str)==0;
}


Mystring operator-(const Mystring &obj){
    char*buff = new char [std::strlen(obj.str)+1];
    std::strcpy(buff,obj.str);
    for (size_t i = 0 ; i<std::strlen(buff);i++){
        buff[i]=std::tolower(buff[i]);
    }

    Mystring temp{buff};
    delete[]buff;
    return temp;
}



Mystring operator+(const Mystring &lhs,const Mystring &rhs){
    char* buff = new char[std::strlen(lhs.str)+std::strlen(rhs.str)+1];
    std::strcpy(buff,lhs.str);
    std::strcat(buff,rhs.str);
    Mystring temp{buff};
    delete[]buff;
    return temp;
}



std::ostream &operator<<(std::ostream &os, const Mystring &rhs){
    os << rhs.str;  
    return os;
}


std::istream &operator>>(std::iostream &in,Mystring &rhs){
    char *buff = new char[1000];
    in>>buff;
    rhs = Mystring(buff);
    delete [] buff;
    return in;
}   