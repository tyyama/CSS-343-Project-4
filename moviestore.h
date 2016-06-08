//Implementation Group:Billy Agung Tjahjady and Tyler Yamamoto
//6-8-16
//Program 4 Implementation

#include <iostream>
#include "customer.h"
using namespace std;
const int defaultSize=79;

class MovieStore{
	public:
		
		MovieStore();
		~MovieStore();
		
		//methods that read the text files 
		void readMovies(ifstream &input);					//read movies from data4movies.txt
		// void readCustomers(ifstream &input);
		// void readCommands(ifstream &input);
	
	
		//methods that add objects based on the text files
		// void addMovie(Movie movie);
		// void addCustomer(Customer customer);
    
		// void checkOutMovie(Customer customer);
		// void returnMovie(Customer customer);
		
		// void printInventory();
		// void printHistory(Customer customer);
		
	private:
		stack<Movie*> destMovies;
		
		struct CustomerNode{//to handle collisions, the customer table will store a linked list in each element 
			Customer *cust;//customer 
			CustomerNode *next=NULL;//next customer if a collision occurs
		
		};
	
		struct MovieNode{//to handle collisions, the movie table will store a linked list in each element
			Movie *movie;//movie 
			MovieNode *next=NULL;//next movie if a collision occurs 		
		};
		
		CustomerNode *customerTable[defaultSize];	//table of customers
		MovieNode *movieTable[defaultSize];				//table of movies
		
		static int hashMovie(char,int);			//hash Movie to movieTable
		static int hashCustomer(char,int);	//hash Customer to customerTable
		static int stringToInt(string);			
	
	
	
};

#include "moviestore.cpp"