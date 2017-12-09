#include "ControlUnit.h"
#include <stdint.h>
using namespace std;

ControlUnit::ControlUnit()
{

}

void ControlUnit::getSignals(char type,string inst, bool & RegWrite, bool & RegDst, bool & MemWr, bool & MemRd, bool & ALUSrc, uint8_t & ALUOp,uint8_t & jmp,bool & jp)
{
	jp = 0;
	MemWr = 0;
	switch (type)
	{
	case 'R':
		RegWrite = 1;
		RegDst = 1;
		ALUSrc = 0;
		MemWr = 0;
		MemRd = 0;
		jmp = 0;
		if (inst == "ADD")
			ALUOp = 0;
		else if (inst == "XOR")
			ALUOp = 2;
		else if (inst == "SLT")
			ALUOp = 1;
		else if (inst == "JR")
			jmp = 1;
		break;
	case 'I':
		ALUOp = 0;
		ALUSrc = 1;
		if (inst == "LW")
		{
			RegDst = 0;
			MemRd = 1;
			RegWrite = 1;
		}
		else if (inst == "SW")
		{
			MemWr = 1;
			RegWrite = 0;
		}
		else if (inst == "BLE")
		{
			jmp = 3;
			ALUOp = 2;
		}
		else if (inst == "ADDI")
		{
			RegDst = 0;
			RegWrite = 1;
		}

		break;
	case 'J':
		jmp = 2;
		break;
	case 'W':
		jmp = 2;
		jp = 1;
		break;
	case 'Q':
		jmp = 4;
		break;

			

	}
}