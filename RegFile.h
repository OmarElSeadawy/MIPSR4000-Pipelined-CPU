//
//  RegFile.hpp
//  ArchiProj
//
//  Created by Mostafa Henna on 11/30/17.
//  Copyright © 2017 Mostafa Henna. All rights reserved.
//

#ifndef RegFile_h
#define RegFile_h

#include <stdio.h>
#include <iostream>
#include <string>
#include <stdint.h>
using namespace std;
 //static int because we need this array to be created only once and needs to be common for all RegFile instances

class RegFile
{
	int REGS[32];

public:
	RegFile();
	void RF(int &, int&, unsigned int , unsigned int);
	void WB(bool, bool,bool, unsigned int, int,int, unsigned int);
	int Cheat(int);
    void getRegs(int []);

	/*bool is_structuralhazard(RegFile& R);
	if (this.getclock() == R.getclock() && this.writesignal == true && R.getwritesignal() == false)
	return true;
	return false; */


	/*bool is_datahazard(RegFile& R);
	if (readreg1 != R[offset of readreg1] || readreg2 != R[offset of readreg2])
	return true;
	return false */

	//bool is_controlhazard(Dmem&);
};

#endif /* RegFile_h */
