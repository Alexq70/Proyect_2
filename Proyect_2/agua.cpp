#include "agua.h"

agua::agua(string id,coordenada p): recurso(id,"A",p) {}
agua::~agua() {}

string agua::toString() {
	stringstream s;
	s << "Recurso de Agua" << endl
		<< "ID: " << id << endl
		<< "Tipo: " << tipo << endl;
	return s.str();
}

ostream& operator<<(ostream& os, agua& a)
{
	os << a.toString();
	return os;
}
