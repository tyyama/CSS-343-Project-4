//Design Group 7:Billy Agung, Sawyer Knoblich, Elias Muche, Tyler Yamamoto
//5-18-16
//Program 4 Design

#include <iostream>
#include "command.h"
using namespace std;

class Customer{
	public:
	Customer(string first, string last, int id);
    
    vector<CommandNode> customerTransactions; // should this be a vector or something else like a linked list?
	
    int getCustomerID();
	
	private:
	
	struct TransactionNode{//Nodes of a transaction linked list
		Transaction  command;//the transaction
		TransactionNode *next=NULL;//the next transaction
	};
    
    
	string first;
	string last;
	int id;
	TransactionNode *head=NULL;//customer's first transaction in the list
	
	
};