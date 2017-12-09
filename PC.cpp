//
//  PC.cpp
//  ArchiProj
//
//  Created by Mostafa Henna on 12/2/17.
//  Copyright © 2017 Mostafa Henna. All rights reserved.
//

#include "PC.h"

PC:: PC(): pc(0)
{}

void PC::increment(int rsdata, int jimm, int imm, uint8_t jmp, bool& JP)
{
	switch (jmp)
	{
	case 0: pc++;
		break;

	case 1: pc = rsdata;
		break;

	case 2:
		if ((JP) && (ProcedureStack.size() < 4))
			ProcedureStack.push(pc);
		pc = jimm;
		break;

	case 3: pc = imm;
		break;
	case 4:
		if (!ProcedureStack.empty())
		{
			pc = ProcedureStack.top();
			ProcedureStack.pop();
		}
		break;
	}
}

int PC:: getpc()
{
    return pc;
}

void PC::setpc(int x)
{
	pc = x;
}
