#pragma once
#include "criatura.h"
class omnivoro : public criatura{
public:
	omnivoro(string,int,int);
	~omnivoro();
	string toString();
};
