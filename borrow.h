//Design Group 7:Billy Agung, Sawyer Knoblich, Elias Muche, Tyler Yamamoto
//5-18-16
//Program 4 Design

#include <iostream>
#include "transaction.h"
#include "movie.h"
#include "customer.h"
using namespace std;

class Borrow: public Transaction{
	public:
	Borrow(int customerId, Movie movie) : Transaction('B',customerId,movie){}
	
	
	
	private:
	
};