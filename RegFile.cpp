
//  RegFile.cpp
//  ArchiProj
//
//  Created by Mostafa Henna on 11/30/17.
//  Copyright © 2017 Mostafa Henna. All rights reserved.
//

#include "RegFile.h"
#include <cmath>
#include <bitset>

RegFile::RegFile() // Constructor initialises readreg1, readreg2, writereg and control signal that chooses rd or rt
{
	for (int i = 0; i < 16; i++)
		REGS[i] = 0;
}


void RegFile::RF(int &rsdata, int&rtdata, unsigned int rsaddr, unsigned int rtaddr)
{
		if (rsaddr != 17)
			rsdata = REGS[rsaddr];
		if (rtaddr!=17)
			rtdata = REGS[rtaddr];
}

void RegFile::WB(bool RegDst, bool RegWrite,bool memwrite, unsigned int rdaddr, int aluresult,int memout, unsigned int rtwriteaddr)
{
	if (rdaddr != 17 || rtwriteaddr != 17)
	{
			int writedata;
			if (memwrite)
			{
				writedata = memout;
			}
			else
				writedata = aluresult;
			if (RegWrite)
			{
				if (RegDst)
				{
					REGS[rdaddr] = writedata;
					cout << REGS[rdaddr] << endl;
				}	
				else
				{
					REGS[rtwriteaddr] = writedata;
						cout << REGS[rtwriteaddr] << endl;
				}
			}
	}
}

int RegFile::Cheat(int x)
{
	return REGS[x];
}