#include "AirStrip.h"
Queue_Object* AirStrip::firstAir = nullptr;
Queue_Object* AirStrip::firstGround = nullptr;
Queue_Object* AirStrip::lastAir = nullptr;
Queue_Object* AirStrip::lastGround = nullptr;
unsigned int AirStrip::numCrashed = 0;
unsigned int AirStrip::qLengthAir = 0;
unsigned int AirStrip::qLenghtGround = 0;

AirStrip::~AirStrip() {
	
	
}

void AirStrip::addFlightAir() {
	srand(time(nullptr));
	Queue_Object* newPlane = new Queue_Object(new Airplane(rand() % 10 + 1, true));
	if (!firstAir)
		firstAir = newPlane;

	else 
		newPlane->setPrevious(lastAir);
	lastAir = newPlane;
	qLengthAir++;
}

void AirStrip::removeFlightAir() {
	if (!firstAir)
		return;
	firstAir->getNext()->setPrevious(nullptr);
	firstAir = firstAir->getNext();
	qLengthAir--;
}

void AirStrip::addFlightGround() {
	srand(time(nullptr));
	Queue_Object* newPlane = new Queue_Object(new Airplane(rand() % 10, false));
	if (!firstGround)
		firstGround = newPlane;

	else
		newPlane->setPrevious(lastGround);
	lastGround = newPlane;
	qLenghtGround++;
}

void AirStrip::tick() {
	srand(time(nullptr));
	Queue_Object* ptr = nullptr;
	if (rand()% 10 == 0)
		addFlightAir();
	if (rand() % 10 == 0)
		addFlightGround();

	if (firstAir) {
		ptr = firstAir;
		while (ptr) {
			if (!ptr->getOwner()->tick()) 
				numCrashed++;
			ptr = ptr->getNext();
		}
	}
	
	if (firstGround) {
		ptr = firstGround;
		while (ptr) {
			ptr->getOwner()->tick();
			ptr = ptr->getNext();
		}
	}

	std::cout << "Total crashed: " << numCrashed << std::endl
		<< "Number of planes in air: " << qLengthAir << std::endl
		<< "Number of planes on ground: " << qLenghtGround << std::endl;
}