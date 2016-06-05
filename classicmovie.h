//Design Group 7:Billy Agung, Sawyer Knoblich, Elias Muche, Tyler Yamamoto
//5-18-16
//Program 4 Design

#include <iostream>
using namespace std;

class ClassicMovie: public Movie{
	public:
		ClassicMovie(int stock, int year, string title, string director, int month, string actor);
    
		string getMajorActor();
		int getMonthReleased();
	
	
	private:
		int monthRelease;
		string majorActor;
	
	
	
};

#include "classicmovie.cpp"