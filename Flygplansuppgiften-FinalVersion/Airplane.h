#pragma once
#include "Data.h"
#include <iostream>
class Airplane : public Data{
public:
	void info();
	Airplane(unsigned int f, bool iA) : fuel(f), inAir(iA), waitTimeAir(0), waitTimeGround(0) {}
	~Airplane(){}

private:
	unsigned int fuel;
	unsigned int waitTimeAir;
	unsigned int waitTimeGround;
	bool inAir;

public:
	unsigned int getWaitTimeGround() { return waitTimeGround; }
	unsigned int getWaitTimeAir() { return waitTimeAir; }
	unsigned int getFuel() { return fuel; }
	bool isInAir() { return inAir; }

	void setFuel(unsigned int x) { fuel = x; }
	void setWaitTimeAir(unsigned int x) { waitTimeAir = x; }
	void setWaitTimeGround(unsigned int x) { waitTimeGround = x; }

	bool tick();
};

