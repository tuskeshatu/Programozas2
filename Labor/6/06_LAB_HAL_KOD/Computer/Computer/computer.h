#pragma once
#include <stdio.h>

class Computer
{
	unsigned nextId;
	unsigned id;
	unsigned clockSpeed;
public:
	Computer();
	Computer(Computer&);
	unsigned getClockSpeed();
	void print();
	void friendlyPrint(Computer&);
};

void friendlyPrint(Computer&);