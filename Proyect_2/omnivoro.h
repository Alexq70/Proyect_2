#pragma once
#include "criatura.h"
class omnivoro : public criatura{
public:
	omnivoro(string,int,int,coordenada);
	~omnivoro();
	string toString();
};
