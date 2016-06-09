//Design Group 7:Billy Agung, Sawyer Knoblich, Elias Muche, Tyler Yamamoto
//5-18-16
//Program 4 Design

#include <iostream>
using namespace std;

class Inventory{
	public:
		void push(Movie*&,char&);
		void push(ClassicMovie*&,char&);
		void display();
		vector<ComedyMovie*> comedy;
		vector<DramaMovie*> drama;
		vector<ClassicMovie*> classic;
	
	private:
		
		bool sorted(vector<ComedyMovie*>&);
		bool sorted(vector<DramaMovie*>&);
		bool sorted(vector<ClassicMovie*>&);
		void sort();
		

};

#include "inventory.cpp"