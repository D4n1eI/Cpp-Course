#include "MovieCollection.h"


#include <iostream>

#include <vector>


std::vector<Movie>& MovieCollection::get_movies() {
    return this->movies; 
}


void MovieCollection::set_movies(std::vector<Movie> movies){
    this->movies = movies;
}

int MovieCollection::get_number_of_movies()const{
    return this->movies.size();
}




void MovieCollection::display_movies(){
    std::cout << "Displaying movies in the collection:"<<std::endl;
    if (this->movies.empty()) {
        std::cout <<"{}"<<std::endl;
        return;
    }
    for(Movie m : this->movies){
        m.display_movie();
    }
}


void MovieCollection::add_movie(Movie movie){
    std::cout << "Adding movie: "<< movie.get_name(); 
    this->movies.push_back(movie);
}

MovieCollection::MovieCollection():movies(std::vector<Movie>{}){
    std::cout << "Movie collection created: {}"<<std::endl;
}


MovieCollection::~MovieCollection(){
    
}
