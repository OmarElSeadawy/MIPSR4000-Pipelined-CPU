//
//  PC.hpp
//  ArchiProj
//
//  Created by Mostafa Henna on 12/2/17.
//  Copyright © 2017 Mostafa Henna. All rights reserved.
//

#ifndef PC_h
#define PC_h

#include <stdint.h>
#include <stack>
using namespace std;

class PC
{
	stack<int> ProcedureStack;
	int pc;
public:
	PC();
	void increment(int, int, int, uint8_t, bool&);
	int getpc();
	void setpc(int x);
};

#endif /* PC_h */