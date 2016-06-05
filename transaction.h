//Design Group 7:Billy Agung, Sawyer Knoblich, Elias Muche, Tyler Yamamoto
//5-18-16
//Program 4 Design

#include <iostream>
#include "movie.h"

using namespace std;

class Transaction{
	public:
    
    
	
	private:
		char transactionType;
		Movie movie;
	
	protected:
		Transaction(char transactionType, Movie movie);
	
	
};

#include "transaction.cpp"
#include "return.h"
#include "borrow.h"