void MovieStore::readMovies(ifstream& file){
	char movieCode;
	int inventory;
	string director;
	string title;
	int releaseYear;
	int releaseMonth;
	
	string primaryActor;
	
	string line;
	while(!file.eof()){
		
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
			default :
				movieCode = 'I';
				cout<<"Invalid code"<<endl;
		}
		
		cout<<"Movie Code: "<<movieCode<<endl;
		
		switch(movieCode){
			case 'I':
				break;
			default :
				getline(ss,token,',');
				inventory = stringToInt(token.substr(1,token.length()));
				cout<<"Inventory: "<<inventory<<endl;
		
				getline(ss,director,',');
				director = director.substr(1,director.length());
				cout<<"Director: "<<director<<endl;
		
				getline(ss,title,',');
				title = title.substr(1,title.length());
				cout<<"Title: "<<title<<endl;
		}
		
		
		switch(movieCode){
			case 'I':
				break;
			case 'C':
			{
				getline(ss,token,',');
				istringstream sss(token);
				cout<<"Token: "<<token<<endl;
				
				getline(sss,subtoken,' ');
				getline(sss,subtoken,' ');
				primaryActor = primaryActor + subtoken;
				cout<<"Subtoken 1: "<<subtoken<<endl;
				getline(sss,subtoken,' ');
				primaryActor = primaryActor + " " + subtoken;
				cout<<"Subtoken 2: "<<subtoken<<endl;
				cout<<"Primary Actor: "<<primaryActor<<endl;
				
				getline(sss,subtoken,' ');
				releaseMonth = stringToInt(subtoken);
				cout<<"Release Month: "<<releaseMonth<<endl;
				
				getline(sss,subtoken,' ');
				releaseYear = stringToInt(subtoken);
				cout<<"Release Year: "<<releaseYear<<endl;
				
				break;
			}
			default :
				getline(ss,token,',');
				releaseYear = stringToInt(token.substr(1,token.length()));
				cout<<"Release Year: "<<releaseYear<<endl;
		}
		cout<<endl<<endl;
	}
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