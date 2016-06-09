#include <iostream>
#include "moviestore.h"

using namespace std;

int main(){
	MovieStore m;
	ifstream movies("data4movies.txt");
	ifstream customers("data4customers.txt");
	m.readMovies(movies);
	m.readCustomers(customers);
	
	movies.close();
}