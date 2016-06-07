//Implementation Group:Billy Agung Tjahjady and Tyler Yamamoto
//6-8-16
//Program 4 Implementation

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

