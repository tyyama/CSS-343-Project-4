ClassicMovie::ClassicMovie(int stock, string yearRelease, string monthRelease, int year, int month, string actor) : Movie(stock, yearRelease, monthRelease, year), monthRelease(month), majorActor(actor){}

ClassicMovie *ClassicMovie::store_movie(char movieType, int stock, string director, string title, int year, int month, string actor){
  if (movieType == 'C') return new ClassicMovie(stock, director, title, year, month, actor);
	else return NULL;

}

bool ClassicMovie::operator<(const ClassicMovie & rhs) const{
	if(yearRelease<rhs.yearRelease) return true;
	if(yearRelease>rhs.yearRelease) return false;
	
	if(monthRelease<rhs.monthRelease) return true;
	if(monthRelease>rhs.monthRelease) return false;
	
	if(majorActor<rhs.majorActor) return true;
	if(majorActor>rhs.majorActor) return false;
}

string ClassicMovie::getMajorActor(){
	return majorActor;
}