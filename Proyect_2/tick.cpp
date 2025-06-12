#include "tick.h"

tick::tick()
{
	this->t = 0;
}

int tick::getTick()
{
	return this->t;
}

void tick::setTick(int t)
{
	this->t = t;
}
