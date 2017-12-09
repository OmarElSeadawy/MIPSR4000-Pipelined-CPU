#pragma once
#include <iostream>
#include "ControlUnit.h"

class HazardUnit{
public:
	void Forward(Instruction , Instruction , Instruction, Instruction,Instruction, uint8_t &,bool &,bool &,bool &, bool &,bool&,uint8_t &);
	void Stall(Instruction , Instruction,Instruction, uint8_t &);
};


