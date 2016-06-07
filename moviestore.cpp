MovieStore::MovieStore(){
	for(int i=0;i<defaultSize;i++){
		movieTable[i]=NULL;
		customerTable[i]=NULL;
	}
}

MovieStore::~MovieStore(){
	while(!destMovies.empty()){
		delete destMovies.top();
		destMovies.pop();
	}
	for(int i=0;i<defaultSize;i++){
		delete movieTable[i];
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
			case 0:
				break;
			default :
				movieCode = 'I';
				cerr<<"Invalid code, token was ASCII value "<< token[0]<<endl;
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
				
				break;
			}
			default :
				getline(ss,token,',');
				releaseYear = stringToInt(token.substr(1,token.length()));
				cerr<<"Release Year: "<<releaseYear<<endl;
				
				movieHash = hashMovie(movieCode,releaseYear);
				
				if(movieTable[movieHash] == NULL){
					movieTable[movieHash] = new MovieNode;
					movieTable[movieHash]->movie = Movie::store_movie(movieCode,inventory,director,title,releaseYear);
					destMovies.push(movieTable[movieHash]->movie);
				}else{
					MovieNode* newMovie = new MovieNode; 
					newMovie->movie = Movie::store_movie(movieCode,inventory,director,title,releaseYear);
					newMovie->next = movieTable[movieHash];
					movieTable[movieHash] = newMovie;
					destMovies.push(movieTable[movieHash]->movie);
				}
		}
		cerr<<endl<<endl;
	}
	cerr<<"hey"<<endl;
	cerr<<"hey"<<endl;
}

int MovieStore::hashMovie(char movieCode, int releaseYear){
	return (releaseYear % 10) + (int)movieCode;
}

int MovieStore::hashCustomer(char firstNameChar, int customerID){
	return (customerID % 10) + (int)firstNameChar;
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