//
//  Dmem.cpp
//  DataMem
//
//  Created by Asser Hangal on 11/30/17.
//  Copyright © 2017 Asser Hangal. All rights reserved.
//

#include "Dmem.hpp"
#include <string>
#include <math.h>
#include <iostream>

using namespace std;


Dmem::Dmem()
{
	

	for (int i = 0; i<32; i++)
		Memory[i] = 0;

}


void Dmem::DataFirst(int addr, int Data,bool MemWr)
{
		Addr = addr;
		WriteData = Data;
}

void Dmem::DataSecond(bool MemWr,bool MemRd,int &loaddata)
{
		if (MemWr)
		{
			Memory[Addr] = WriteData;
			cout << Memory[Addr] << " stored in " << Addr << endl;
		}

		else
		if (MemRd)
		{
			loaddata = Memory[Addr];
			cout << "load "<< Memory[Addr] <<" from " << Addr << endl;
		}
}

void Dmem::TagCheck(bool MemRd,int & loaddata)
{

}
void Dmem::getMems(int memory[])
{
    for(int i=0; i<32; i++)
        memory[i] = Memory[i];
    
}

