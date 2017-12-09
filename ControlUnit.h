#pragma once
#include <iostream>
#include <stdint.h>
using namespace std;

struct Instruction{
	uint8_t rs, rt, rd;
	int imm, jimm;
	uint32_t pc;
	char type;
	string inst;
};

class ControlUnit{
public:
	ControlUnit();
	void getSignals(char,string,bool&,bool&,bool&,bool&,bool&,uint8_t &,uint8_t &,bool &);
};