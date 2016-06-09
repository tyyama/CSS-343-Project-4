//Implementation Group:Billy Agung Tjahjady and Tyler Yamamoto
//6-8-16
//Program 4 Implementation

#include <iostream>
#include "movie.h"

using namespace std;

class Transaction{
	public:
    
    static Transaction *read_commands(string transType); //Factory Method
		char getTransactionType();
		Movie getMovie();
	
	private:
		char transactionType;
		Movie movie;
	
	protected:
		Transaction(char transactionType, Movie movie);
	
	
};

#include "transaction.cpp"
#include "return.h"
#include "borrow.h"