#ifndef EXSTRING_H_

#define EXSTRING_H_


class ExString{

    private:
        char * str;

    public:
        void set_str(char *str );
        char* get_str() const;
        ExString(char*str);
        ExString(const ExString &source);
        ExString();
        ExString(ExString &&obj);
        ~ExString();

        bool ExString::operator==(const ExString &rhs)const;
        ExString ExString::operator-()const;

};

#endif