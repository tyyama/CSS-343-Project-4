Movie::Movie(int stock, int year, string title, string director) : stock(stock), yearRelease(year), title(title), director(director){}
	

//Factory Method
Movie *Movie::store_movie(char movieType){
  if (movieType == 'F') return new ComedyMovie;
  if (movieType == 'D') return new DramaMovie;
  if (movieType == 'C') return new ClassicMovie;
	else return NULL;

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