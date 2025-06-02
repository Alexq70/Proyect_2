#include "omnivoro.h"

omnivoro::omnivoro(string id): criatura(id,"O") {}
omnivoro::~omnivoro() {}

string omnivoro::toString() {
	stringstream s;
	s << criatura::toString() << endl;
	return s.str();
}