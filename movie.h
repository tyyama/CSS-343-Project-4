//Design Group 7:Billy Agung, Sawyer Knoblich, Elias Muche, Tyler Yamamoto
//5-18-16
//Program 4 Design

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <fstream>
#include <typeinfo>
#include <cmath>

using namespace std;

class Movie{
	public:
		bool operator==(const Movie &) const;
		bool operator!=(const Movie &) const;	
		
		static Movie *store_movie(char, int, string, string, int);
		static Movie *store_movie(char, int, string, string, int, int, string);
		
		int getCurrentStock();
		int getYearReleased();
    
		string getTitle();
		string getDirector();
    
	private:
	
	protected :
		Movie(int stock, string director, string title, int year);
	
		int stock;
		int yearRelease;
		string title;
		string director;
		
		bool sameType(const Movie&) const;
};

#include "classicmovie.h"
#include "comedymovie.h"
#include "dramamovie.h"
#include "movie.cpp"
