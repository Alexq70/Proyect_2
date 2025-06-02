#include "herbivoro.h"

herbivoro::herbivoro(string id) : criatura(id,"H") {}
herbivoro::~herbivoro() {}

string herbivoro::toString() {
	stringstream s;
	s << criatura::toString() << endl;
	return s.str();
}