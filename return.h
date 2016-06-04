//Design Group 7:Billy Agung, Sawyer Knoblich, Elias Muche, Tyler Yamamoto
//5-18-16
//Program 4 Design

#include <iostream>
#include "transaction.h"
#include "movie.h"
#include "customer.h"
using namespace std;

class Return: public Transaction{
	public:
	Return(int customerId, Movie movie) : Transaction('R',customerId,movie){}
	
	
	private:
	
};