#include "omnivoro.h"

omnivoro::omnivoro(string id,int energia, int edad): criatura(id,"O",energia,edad) {}
omnivoro::~omnivoro() {}

string omnivoro::toString() {
	stringstream s;
	s << criatura::toString() << endl;
	return s.str();
}