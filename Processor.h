#pragma once
//include imem,rf,dmem
#include <iostream>
#include "Dmem.hpp"
#include "RegFile.h"
#include "ALU.h"
#include "SignExt.h"
#include <stdint.h>
#include "ControlUnit.h"
#include "Imem.h"
#include "PC.h"
#include "HazardUnit.h"
#include "BTB.h"
using namespace std;


class Processor{
	Imem imem;
	Dmem datamem;
	RegFile registerfile;
	ALU alu;
	ControlUnit CU;
	PC pc;
	BTB btb;
	int instcount = 0;
	HazardUnit HU;
public:
	Processor(){  };
	void loadprogram(string filename);
	void execute();
};