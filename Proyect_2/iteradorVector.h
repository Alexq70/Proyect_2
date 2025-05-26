#pragma once
#include "iterador.h"
#include<iostream>
#include<vector>
using namespace std;
template<class T>
class iteradorVector:public iterador<T>
{
private:
	vector<T>* v;
	int currentN;
	int firstN;
public:
	iteradorVector(vector<T>* v);
	void first();
	void next();
	bool isDone();
	T* current();
};

template<class T>
inline iteradorVector<T>::iteradorVector(vector<T>* v)
{
	this->v = v;
	this->currentN = 0;
	this->firstN = 0;
}

template<class T>
inline void iteradorVector<T>::first()
{
	this->firstN = 0;
	this->currentN = 0;
}

template<class T>
inline void iteradorVector<T>::next()
{
	this->currentN++;
}

template<class T>
inline bool iteradorVector<T>::isDone()
{
	return (!this->v->at(currentN));
}

template<class T>
inline T* iteradorVector<T>::current()
{
	return &v->at(currentN);
}

