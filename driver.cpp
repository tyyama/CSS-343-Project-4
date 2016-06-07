#include <iostream>
#include "moviestore.h"

using namespace std;

int main(){
	MovieStore m;
	ifstream movies("data4movies.txt");
	m.readMovies(movies);
}