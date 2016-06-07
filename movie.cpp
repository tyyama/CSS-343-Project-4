<<<<<<< HEAD
<<<<<<< HEAD
Movie::Movie(int stock, int year, string title, string director) : stock(stock), yearRelease(year), title(title), director(director){
	
=======
//Factory Method
Movie *Movie::store_movie(int movieType){
  if (movieType == F) return new ComedyMovie;
  if (movieType == D) return new DramaMovie;
  if (movieType == C) return new ClassicMovie;
	else return NULL;
>>>>>>> origin/master
=======
//Factory Method
Movie *Movie::store_movie(string movieType){
  if (movieType == "F") return new ComedyMovie;
  if (movieType == "D") return new DramaMovie;
  if (movieType == "C") return new ClassicMovie;
	else return NULL;
>>>>>>> origin/master
}