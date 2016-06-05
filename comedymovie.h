//Design Group 7:Billy Agung, Sawyer Knoblich, Elias Muche, Tyler Yamamoto
//5-18-16
//Program 4 Design

#include <iostream>
using namespace std;

class ComedyMovie: public Movie{
public:
    ComedyMovie(int stock, int year, string title, string director) : Movie(stock,year,title,director){}
    bool operator==(const ComedyMovie &) const;
	bool operator!=(const ComedyMovie &) const;
    
private:
    
    
    
};

#include "comedymovie.cpp"