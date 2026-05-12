
#include "Movie.h"

#include <vector>
#include <iostream>

class MovieCollection{
    public:
        std::vector<Movie>& get_movies();
        int get_number_of_movies()const;
        void set_movies(std::vector<Movie> movies);
        void add_movie(Movie movie);
        void display_movies();

        friend class Movie;

        MovieCollection();
        ~MovieCollection();


    private:
        std::vector<Movie> movies;
        int number_of_movies;
        
};