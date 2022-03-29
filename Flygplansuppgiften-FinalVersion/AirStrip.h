#pragma once
#include <iostream>
#include <random>
#include"Queue_Object.h"
#include"Airplane.h"
#include "Data.h"

class AirStrip
{
public:
	AirStrip() : longestWaitTimeAir(0), averageWaitTimeAir(0), longestWaitTimeGround(0), averageWaitTimeGround(0) {}
	~AirStrip();

private:
	static unsigned int qLengthAir;
	static Queue_Object* firstAir;
	static Queue_Object* lastAir;
	
	static unsigned int qLenghtGround;
	static Queue_Object* firstGround;
	static Queue_Object* lastGround;

	static unsigned int numCrashed;
	unsigned int longestWaitTimeAir;
	unsigned int longestWaitTimeGround;

	double averageWaitTimeAir;
	double averageWaitTimeGround;

public:
	static void addFlightGround();
	static void addFlightAir();
	static void removeFlightAir();
	static void tick();
};

