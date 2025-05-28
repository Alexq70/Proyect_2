#pragma once
#include "criatura.h"
class carnivoro : public criatura {
private:
	bool rapidez;
public:
	carnivoro(string);
	~carnivoro();

	void setRapidez(bool);
	string toString();

	bool operator==(carnivoro& other) {
		return rapidez == other.rapidez && (this->id == other.id && this->tipo == other.tipo);
	}

	friend ostream& operator<<(ostream& os, carnivoro& c) {
		os << c.toString();
		return os;
	}
};

