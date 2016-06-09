//Design Group 7:Billy Agung, Sawyer Knoblich, Elias Muche, Tyler Yamamoto
//5-18-16
//Program 4 Design

#include <iostream>
using namespace std;

class ComedyMovie: public Movie{
public:
    ComedyMovie(int stock, string director, string title, int year) : Movie(stock, director, title, year){}
    bool operator<(const ComedyMovie &) const;
    
private:
    
    
    
};

#include "comedymovie.cpp"