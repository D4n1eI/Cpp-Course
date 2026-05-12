#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring{


    friend bool operator==(const Mystring &lhs,const Mystring &rhs);
    friend Mystring operator-(const Mystring &obj);
    friend Mystring operator+(const Mystring &lhs,const Mystring &rhs);
    friend std::ostream &operator<<(std::ostream &os,const Mystring &rhs);
    friend std::istream &operator>>(std::istream &os,Mystring &rhs);

    private:
        char *str;

    public:
        Mystring();
        Mystring(const char*);
        Mystring(const Mystring &source);
        ~Mystring();
        Mystring&operator=(const Mystring &rhs);
        Mystring&operator=(Mystring&&rhs);
        void display() const;
        int get_length() const;
        const char *get_str()const;

        Mystring operator-() const ;

        Mystring operator+(const Mystring &rhs) const ;


        bool operator==(const Mystring &rhs) const;
};

#endif