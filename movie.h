//Design Group 7:Billy Agung, Sawyer Knoblich, Elias Muche, Tyler Yamamoto
//5-18-16
//Program 4 Design

#include <iostream>
using namespace std;

class Movie{
	public:
	
	
	bool operator==(const Movie &) const;
	bool operator!=(const Movie &) const;	
	
    int getCurrentStock();
    int getYearReleased();
    
    string getTitle();
    string getDirector();
    
    int checkoutMovie(Customer customer); // my thinking is that we should create the borrow / return transactions inside these
    int returnMovie(Customer customer);  // we need to handle the case where this gets called when the customer has not checked out the movie
                                // maybe have each customer keep a list of currently-checked-out movies?
    
	private:
	
	protected :
	Movie(int stock, int year, string title, string director);
	
	bool returned;//?? Sawyer: I don't think we need this, since we will have multiple stocks of this movie represented as one Movie object
	int stock;
	int yearRelease;
	string title;
	string director;
	
	
	
	
};