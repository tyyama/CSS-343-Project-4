bool ComedyMovie::operator<(const ComedyMovie & rhs) const{
	if(title<rhs.title) return true;
	if(title>rhs.title) return false;
	
	if(yearRelease<rhs.yearRelease) return true;
	if(yearRelease>rhs.yearRelease) return false;
}