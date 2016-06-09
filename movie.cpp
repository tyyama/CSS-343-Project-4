Movie::Movie(int stock, string director, string title, int year) : stock(stock), director(director), title(title), yearRelease(year){}

Movie *Movie::store_movie(char movieType, int stock, string director, string title, int year){
  if (movieType == 'F') return new ComedyMovie(stock, director, title, year);
  if (movieType == 'D') return new DramaMovie(stock, director, title, year);
	else return NULL;

}

string Movie::getTitle(){
	return title;
}

bool Movie::sameType(const Movie& other) const{
	return (typeid(*this)==typeid(other));
}

bool Movie::operator==(const Movie & rhs) const{
	if(!sameType(rhs)){
		return false;
	}else{
		return (yearRelease == rhs.yearRelease && stock == rhs.stock && title == rhs.title && director == rhs.director);
	}
}