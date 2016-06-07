//Implementation Group:Billy Agung Tjahjady and Tyler Yamamoto
//6-8-16
//Program 4 Implementation

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Movie{
	public:
<<<<<<< HEAD
=======
	
		static Movie *store_movie(string movieType); //Factory Method
	
>>>>>>> origin/master
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