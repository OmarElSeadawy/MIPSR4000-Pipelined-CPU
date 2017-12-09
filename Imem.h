#pragma once
#include <iostream>
#include "ControlUnit.h"


class Imem{
	Instruction arr[1024];
public:
	Imem();
	void insert(int,Instruction);
	void IF();
	void IS(int, Instruction &);
};