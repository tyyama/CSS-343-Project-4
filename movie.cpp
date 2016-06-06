//Factory Method
Movie *Movie::store_movie(int movieType){
  if (movieType == F) return new ComedyMovie;
  if (movieType == D) return new DramaMovie;
  if (movieType == C) return new ClassicMovie;
	else return NULL;
}