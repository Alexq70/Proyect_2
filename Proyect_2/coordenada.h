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
	int getX();
	int getY();
	string toString();
	//-----------------------------
	void setX(int);
	void setY(int);
	//------------------------------
	bool operator==(coordenada& otra) {
		return (this->x == otra.x && this->y == otra.y);
	}

};

