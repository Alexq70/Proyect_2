#include "carnivoro.h"

carnivoro::carnivoro(string id): criatura(id,"C"), rapidez(0) {}
carnivoro::~carnivoro() {}

void carnivoro::setRapidez(bool r) { this->rapidez = r; }

string carnivoro::toString() {
	stringstream s;
	s << criatura::toString()
	  << "Rapidez: " << (this->rapidez ? "Alta" : "Normal") << endl; //la parte del decorador
	return s.str();
} //