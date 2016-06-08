//Implementation Group:Billy Agung Tjahjady and Tyler Yamamoto
//6-8-16
//Program 4 Implementation

#include <iostream>
using namespace std;

class ClassicMovie: public Movie{
	public:
		ClassicMovie(int stock, string director, string title, int year, int month, string actor);
    
		string getMajorActor();
		int getMonthReleased();
	
	
	private:
		int monthRelease;
		string majorActor;
	
	
	
};

#include "classicmovie.cpp"