//Design Group 7:Billy Agung, Sawyer Knoblich, Elias Muche, Tyler Yamamoto
//5-18-16
//Program 4 Design

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Movie{
	public:
		bool operator==(const Movie &) const;
		bool operator!=(const Movie &) const;	
	
		int getCurrentStock();
		int getYearReleased();
    
		string getTitle();
		string getDirector();
    
	private:
	
	protected :
		Movie(int stock, int year, string title, string director);
	
		int stock;
		int yearRelease;
		string title;
		string director;
};

#include "movie.cpp"
#include "classicmovie.h"
#include "comedymovie.h"
#include "dramamovie.h"