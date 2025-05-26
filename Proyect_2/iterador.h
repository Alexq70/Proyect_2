#pragma once
#include <iostream>
using namespace std;
#include "iterador.h"
template<class T>
class iterador
{
public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() = 0;
    virtual T* current() = 0;
};

