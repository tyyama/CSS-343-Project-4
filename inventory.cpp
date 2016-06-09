void Inventory::push(Movie*& movie, char& code){
	if(code=='F') comedy.push_back(static_cast<ComedyMovie*>(movie));
	if(code=='D') drama.push_back(static_cast<DramaMovie*>(movie));
	if(code=='C') classic.push_back(static_cast<ClassicMovie*>(movie));
}

void Inventory::push(ClassicMovie*& movie, char& code){
	if(code=='C') classic.push_back(static_cast<ClassicMovie*>(movie));
}

void Inventory::display(){
	sort();
	for(int i=0;i<comedy.size()-1;i++){
		cout<<(*comedy[i]).getTitle()<<endl;
	}
	for(int i=0;i<drama.size()-1;i++){
		cout<<(*drama[i]).getTitle()<<endl;
	}
	for(int i=0;i<classic.size()-1;i++){
		cout<<(*classic[i]).getTitle()<<endl;
	}
}

void Inventory::sort(){
	while(!sorted(comedy)){
		for(int i=0;i<comedy.size()-1;i++){
			if((*comedy[i+1])<(*comedy[i])) swap(comedy[i+1],comedy[i]);
		}
	}
	
	while(!sorted(drama)){
		for(int i=0;i<drama.size()-1;i++){
			if((*drama[i+1])<(*drama[i])) swap(drama[i+1],drama[i]);
		}
	}
		
	while(!sorted(classic)){
		for(int i=0;i<classic.size()-1;i++){
			if((*classic[i+1])<(*classic[i])) swap(classic[i+1],classic[i]);
		}
	}
		
}

bool Inventory::sorted(vector<ComedyMovie*>& comedy){
	if(comedy.size()==0 || comedy.size()==1) return true;
	for(int i=0;i<comedy.size()-1;i++){
		if((*comedy[i+1])<(*comedy[i])) return false;
	}
	return true;
}

bool Inventory::sorted(vector<DramaMovie*>& drama){
	if(drama.size()==0 || drama.size()==1) return true;
	for(int i=0;i<drama.size()-1;i++){
		if((*drama[i+1])<(*drama[i])) return false;
	}
	return true;
}

bool Inventory::sorted(vector<ClassicMovie*>& classic){
	if(classic.size()==0 || classic.size()==1) return true;
	for(int i=0;i<classic.size()-1;i++){
		if((*classic[i+1])<(*classic[i])) return false;
	}
	return true;
}