#pragma once
#include "criatura.h"
class carnivoro : public criatura {
private:
	bool rapidez;
public:
	carnivoro(string,int ,int,coordenada);
	~carnivoro();

	void setRapidez(bool);
	string toString();

};

