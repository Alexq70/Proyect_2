#include "omnivoro.h"

omnivoro::omnivoro(string id,int energia, int edad,coordenada c): criatura(id,"O",energia,edad,c) {}
omnivoro::~omnivoro() {}

string omnivoro::toString() {
	stringstream s;
	s << criatura::toString() << endl;
	return s.str();
}