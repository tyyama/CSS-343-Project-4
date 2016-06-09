bool DramaMovie::operator<(const DramaMovie & rhs) const{
	if(director<rhs.director) return true;
	if(director>rhs.director) return false;
	
	if(title<rhs.title) return true;
	if(title>rhs.title) return false;
}