#include<iostream>
#include "Airplane.h"
#include "AirStrip.h"
#include "Data.h"
#include "Queue_Object.h"
using namespace std;

int main() {
	AirStrip a;
	srand(time(nullptr));
	while (true)
		a.tick(); 
}