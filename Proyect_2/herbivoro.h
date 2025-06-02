#pragma once
#include"criatura.h"
class herbivoro : public criatura{
public:
	herbivoro(string,int,int);
	~herbivoro();
	string toString();
};

