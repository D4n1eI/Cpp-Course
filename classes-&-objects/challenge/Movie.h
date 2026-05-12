#ifndef _MOVIE_H_

#define _MOVIE_H_

#include <string>


class Movie{
    public:
        std::string get_name()const;
        std::string get_rating()const;
        int get_watched()const;
        void set_name(std::string other_name);
        void set_rating(std::string other_rating);
        void increment_watched();
        void display_movie();

        Movie(std::string name,std::string rating);
        Movie(const Movie &source);
        ~Movie();

    private:
        std::string name;
        std::string rating;
        int* watched;
};

#endif