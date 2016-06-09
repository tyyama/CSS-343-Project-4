//Implementation Group:Billy Agung Tjahjady and Tyler Yamamoto
//6-8-16
//Program 4 Implementation

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
	friend ostream& operator<<( ostream &output, const Movie &m);
	public:
		bool operator==(const Movie &rhs) const;
		bool operator!=(const Movie &rhs) const;	
		
		static Movie *store_movie(char, int, string, string, int);
		
		
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
