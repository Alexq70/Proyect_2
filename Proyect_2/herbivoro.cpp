#include "herbivoro.h"

herbivoro::herbivoro(string id,int energia, int edad) : criatura(id,"H",energia,edad) {}
herbivoro::~herbivoro() {}

string herbivoro::toString() {
	stringstream s;
	s << criatura::toString() << endl;
	return s.str();
}