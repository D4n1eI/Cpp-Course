#include <iostream>
#include "Movie.h"
#include "MovieCollection.h"



int main(){
    std::cout << "=======Movie Collection======"<<std::endl;
    MovieCollection* collection = new MovieCollection();

    bool proceed = true;
    while(proceed){
        std::cout<<"1. View Movie Collection" <<std::endl;
        std::cout<<"2. Add Movie" <<std::endl;
        std::cout<<"3. Increment Movie Watch" <<std::endl;
        std::cout<<"4. Quit" <<std::endl;

        int response{};

        std::cin >> response;

        switch (response)
        {
        case 1:
        {
            collection->display_movies();
        }
            break;
        case 2:
        {
            std::cout<<"Movie Name: "<<std::endl;
            std::string name{};
            std::cin >> name;
            std::cout<<"Movie Rating: "<<std::endl;
            std::string rating{};
            std::cin >> rating;
            Movie movie = Movie(name,rating);
            collection->add_movie(movie);
            std::cout << "Added movie "<<name<<" to the collection."<<std::endl;
            break;
        }
        case 3:
        {
            std::cout<<"Movie Name: "<<std::endl;
            std::string name{};
            std::cin >> name;
            for (Movie &m : collection->get_movies()){
                if (m.get_name()==name){
                    m.increment_watched();
                    std::cout<<"Incremented watched on movie "<<name<<"."<<std::endl;
                }
            }
            break;
        }
        case 4:
        {
            delete collection;
            std::cout<<"Quitting...";
            proceed=false;
            break;
        }
        default:
            break;
        }
    }
    return 0;
}