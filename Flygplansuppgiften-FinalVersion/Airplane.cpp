#include "Airplane.h"

bool Airplane::tick() {
	if (inAir) {
		waitTimeAir += 5;
		fuel--;
		return fuel;
	}
	else {
		waitTimeGround += 5;
		return true;
	}
}

void Airplane::info() {
	std::cout << "Time waited (in air): " << waitTimeAir << std::endl
		<< "Time waited (on ground): " << waitTimeGround << std::endl
		<< "Fuel left: " << fuel << std::endl;
}