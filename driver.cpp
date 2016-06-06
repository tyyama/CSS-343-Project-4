#include <iostream>
#include "moviestore.h"

using namespace std;

int main(){

	ifstream infile1("data4movies.txt"); // or however you are reading the data
	if (!infile1) {
		cout << "File could not be opened." << endl;
		return 1;
	}
	
	//add this to the data parsing function you worked on
	while(true){
		hasingFunction(store_movie); // hashingFunction has to add the case where store_movie returns NULL (not type F, D, or C)
		if (infile1.eof())
			break;
	}
}