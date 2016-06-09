MovieStore::MovieStore(){
	for(int i=0;i<defaultSize;i++){
		cMovieTable[i]=NULL;
		movieTable[i]=NULL;
		customerTable[i]=NULL;
	}
}

MovieStore::~MovieStore(){
	
	while(!destMovies.empty()){
		delete destMovies.top();
		destMovies.pop();
	}
	while(!destCMovies.empty()){
		delete destCMovies.top();
		destCMovies.pop();
	}
	while(!destCustomers.empty()){
		delete destCustomers.top();
		destCustomers.pop();
	}
	for(int i=0;i<defaultSize;i++){
		delete customerTable[i];
		delete movieTable[i];
		delete cMovieTable[i];
	}
}

void MovieStore::readMovies(ifstream& file){
	char movieCode;
	int inventory;
	string director;
	string title;
	int releaseYear;
	int releaseMonth;
	
	int movieHash;
	
	string primaryActor;
	
	string line;
	while(!file.eof()){
		cerr<<"woop"<<endl;
		
		string primaryActor = "";
		
		getline(file,line);
		istringstream ss(line);
		cout<<line<<endl;
		
		string token;
		string subtoken;
		
		getline(ss,token,',');
		switch(token[0]){
			case 'C':
				movieCode = 'C';
				break;
			case 'D':
				movieCode = 'D';
				break;
			case 'F':
				movieCode = 'F';
				break;
			case '\0':
				cout<<"asdasdasdasdasdasd"<<endl;
				movieCode = 'I';
				break;
			default :
				movieCode = 'I';
				cerr<<"Invalid code, token was ASCII value "<< (int)token[0] <<" token was: "<<token<<endl;
		}
		
		if(token[0]==0){
			cerr<<"hey"<<endl;
			break;
		}
		
		cerr<<"Movie Code: "<<movieCode<<endl;
		
		switch(movieCode){
			case 'I':
				break;
			default :
				getline(ss,token,',');
				inventory = stringToInt(token.substr(1,token.length()));
				cerr<<"Inventory: "<<inventory<<endl;
		
				getline(ss,director,',');
				director = director.substr(1,director.length());
				cerr<<"Director: "<<director<<endl;
		
				getline(ss,title,',');
				title = title.substr(1,title.length());
				cerr<<"Title: "<<title<<endl;
		}
		
		
		switch(movieCode){
			case 'I':
				break;
			case 'C':
			{
				getline(ss,token,',');
				istringstream sss(token);
				cerr<<"Token: "<<token<<endl;
				
				getline(sss,subtoken,' ');
				getline(sss,subtoken,' ');
				primaryActor = primaryActor + subtoken;
				cerr<<"Subtoken 1: "<<subtoken<<endl;
				getline(sss,subtoken,' ');
				primaryActor = primaryActor + " " + subtoken;
				cerr<<"Subtoken 2: "<<subtoken<<endl;
				cerr<<"Primary Actor: "<<primaryActor<<endl;
				
				getline(sss,subtoken,' ');
				releaseMonth = stringToInt(subtoken);
				cerr<<"Release Month: "<<releaseMonth<<endl;
				
				getline(sss,subtoken,' ');
				releaseYear = stringToInt(subtoken);
				cerr<<"Release Year: "<<releaseYear<<endl;
				
				movieHash = hashMovie(movieCode,releaseYear,releaseMonth);
				cerr<<movieHash<<endl;
				
				if(cMovieTable[movieHash] == NULL){
					cMovieTable[movieHash] = new cMovieNode;
					cMovieTable[movieHash]->movie = ClassicMovie::store_movie(movieCode,inventory,director,title,releaseYear,releaseMonth,primaryActor);
					destCMovies.push(cMovieTable[movieHash]->movie);
					inv.push(cMovieTable[movieHash]->movie,movieCode);
					cerr<<"adding as front"<<endl;
				}else{
					cMovieNode* newMovie = new cMovieNode; 
					newMovie->movie = ClassicMovie::store_movie(movieCode,inventory,director,title,releaseYear,releaseMonth,primaryActor);
					newMovie->next = cMovieTable[movieHash];
					cerr<<"adding in front"<<endl;
					cMovieTable[movieHash] = newMovie;
					destCMovies.push(cMovieTable[movieHash]->movie);
					inv.push(cMovieTable[movieHash]->movie,movieCode);
				}
				
				break;
			}
			default :
				getline(ss,token,',');
				releaseYear = stringToInt(token.substr(1,token.length()));
				cerr<<"Release Year: "<<releaseYear<<endl;
				
				movieHash = hashMovie(movieCode,releaseYear);
				cerr<<movieHash<<endl;
				
				if(movieTable[movieHash] == NULL){
					movieTable[movieHash] = new MovieNode;
					movieTable[movieHash]->movie = Movie::store_movie(movieCode,inventory,director,title,releaseYear);
					destMovies.push(movieTable[movieHash]->movie);
					inv.push(movieTable[movieHash]->movie,movieCode);
					cerr<<"adding as front"<<endl;
				}else{
					MovieNode* newMovie = new MovieNode; 
					newMovie->movie = Movie::store_movie(movieCode,inventory,director,title,releaseYear);
					newMovie->next = movieTable[movieHash];
					cerr<<"adding in front"<<endl;
					movieTable[movieHash] = newMovie;
					destMovies.push(movieTable[movieHash]->movie);
					inv.push(movieTable[movieHash]->movie,movieCode);
				}
		}
		cerr<<endl<<endl;
		
	}
	inv.display();
}

void MovieStore::readCustomers(ifstream& file){
	int customerID;
	
	
	string line;
	while(!file.eof()){
		string customerName;
		string token;
		getline(file,line);
		istringstream ss(line);
		
		getline(ss,token,' ');
		customerID = stringToInt(token);
		if(token[0]=='\0') break;
		
		getline(ss,token,' ');
		customerName = customerName + token;
		
		getline(ss,token,' ');
		customerName = customerName + " " + token;
		
		int customerHash = hashCustomer(customerID);
		cerr<<customerHash<<endl;
		
		if(customerTable[customerHash] == NULL){
			customerTable[customerHash] = new CustomerNode;
			customerTable[customerHash]->cust = new Customer(customerName,customerID);
			destCustomers.push(customerTable[customerHash]->cust);
			cerr<<"adding as front"<<endl;
		}else{
			CustomerNode* newCustomer = new CustomerNode; 
			newCustomer->cust = new Customer(customerName,customerID);
			newCustomer->next = customerTable[customerHash];
			cerr<<"adding in front"<<endl;
			customerTable[customerHash] = newCustomer;
			destCustomers.push(customerTable[customerHash]->cust);
		}
	}
}

void MovieStore::readCommands(ifstream& file){
	
}

int MovieStore::hashMovie(char movieCode, int releaseYear){
	return (releaseYear % 10) + (int)movieCode - 1;
}

int MovieStore::hashMovie(char movieCode, int releaseYear, int releaseMonth){
	return (releaseYear % 10) + (int)movieCode - releaseMonth;
}

int MovieStore::hashCustomer(int customerID){
	return (customerID % 10) + (customerID/pow(10,floor(log10(customerID)))) - 1;
}

int MovieStore::stringToInt(string input){
	int ret = 0;																						//Return value
	int size = input.size();
	int asciiVal = input[input.size()-1];																//Initialize to last character to check for new line
	if(asciiVal == 13) size--;																			//Compensate for new line character

	for(int i=0;i<size;i++){
		asciiVal = input[size-i-1];																		//Update value
		if(asciiVal>47 && asciiVal<58){
			ret+=((asciiVal-48)*pow(10,i));																//Multiply ASCII value by 10 to the decimal place
		}
	}
	return ret;
}