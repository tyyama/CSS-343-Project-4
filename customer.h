//Design Group 7:Billy Agung, Sawyer Knoblich, Elias Muche, Tyler Yamamoto
//5-18-16
//Program 4 Design

#include <iostream>
#include "transaction.h"
using namespace std;

class Customer{
	public:
		Customer(string first, string last, int id);
    
		vector<Transaction> customerTransactions; 
	
		int customerID();
	
	private:
		string first;
		string last;
		int id;
	
};

#include "customer.cpp"

