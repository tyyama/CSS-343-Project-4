//Design Group 7:Billy Agung, Sawyer Knoblich, Elias Muche, Tyler Yamamoto
//5-18-16
//Program 4 Design

#include <iostream>
#include "customer.h"
using namespace std;
const int defaultSize=101;

class MovieStore{
	public:
		//methods that read the text files 
		void readMovies(ifstream &input);
		void readCustomers(ifstream &input);
		void readCommands(ifstream &input);
	
	
		//methods that add objects based on the text files
		void addMovie(Movie movie);
		void addCustomer(Customer customer);
    
		void checkOutMovie(Customer customer); // duplicate of the ones in movie.h, we should decide where these should go
		void returnMovie(Customer customer);
		
		void printInventory();
		void printHistory(Customer customer);
		
	private:
		struct CustomerNode{//to handle collisions, the customer table will store a linked list in each element 
			Customer cust;//customer 
			CustomerNode *next=NULL;//next customer if a collision occurs
		
		};
	
		struct MovieNode{//to handle collisions, the movie table will store a linked list in each element 
			Movie movie;//movie 
			MovieNode *next=NULL;//next movie if a collision occurs 		
		};
	
		int hashMovie(Movie movie);
		int hashCustomer(Customer customer);
		CustomerNode *customerTable[defaultSize];//table of customers
		MovieNode *movieTable[defaultSize];//table of movies 
	
	
	
};

#include "moviestore.cpp"