//Implementation Group:Billy Agung Tjahjady and Tyler Yamamoto
//6-8-16
//Program 4 Implementation

#include <iostream>
using namespace std;

class ComedyMovie: public Movie{
public:
    ComedyMovie(int stock, string director, string title, int year) : Movie(stock, director, title, year){}
    bool operator==(const ComedyMovie &) const;
	bool operator!=(const ComedyMovie &) const;
    
private:
    
    
    
};

#include "comedymovie.cpp"