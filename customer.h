//Implementation Group:Billy Agung Tjahjady and Tyler Yamamoto
//6-8-16
//Program 4 Implementation

#include <iostream>
#include "transaction.h"
using namespace std;

class Customer{
	public:
		Customer(string, int);
    
		vector<Transaction> customerTransactions; 
	
		int customerID();
	
	private:
		string name;
		int id;
	
};

#include "customer.cpp"

