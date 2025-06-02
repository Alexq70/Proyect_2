#pragma once
#include <iostream>
#include <sstream>	
using namespace std;
class coordenada {
private:
	int x;
	int y;
public:
	coordenada(int,int);
	~coordenada();
	//---------------------------
	string toString();
	//-----------------------------
	bool operator==(coordenada& otra) {
		return (this->x == otra.x && this->y == otra.y);
	}

};

