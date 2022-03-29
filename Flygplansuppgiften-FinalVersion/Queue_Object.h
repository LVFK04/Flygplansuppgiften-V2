#pragma once
#include"Data.h"
#include "Airplane.h"
class Queue_Object
{
public:
	Queue_Object(Airplane* ptr) : previous(nullptr), next(nullptr), owner(ptr) {}
	~Queue_Object() { delete owner; }

private:
	Queue_Object* previous, * next;
	Data* owner;
public:
	void setOwner(Data* ptr) { owner = ptr; }
	void setNext(Queue_Object* ptr) { next = ptr; }
	void setPrevious(Queue_Object* ptr) { previous = ptr; }

	Data* getOwner() { return owner; }
	Queue_Object* getNext() { return next; }
	Queue_Object* getPrevious() { return previous; }
};

