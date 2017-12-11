//
//  ALU.cpp
//  ArchiProj
//
//  Created by Mostafa Henna on 11/30/17.
//  Copyright © 2017 Mostafa Henna. All rights reserved.
//

#include "ALU.h"
#include <cmath>
#include <bitset>
using namespace std;

ALU::ALU()
{
}

void ALU::EX(bool &zflag, bool ALUSrc, int ALUOp,int in1, int imm,int in2,int &result)
{
		if (ALUOp == 0 && ALUSrc) //add readdata1 and sign_ext_imm
			result = in1 + imm; //converts in1 and imm to strings and adds them then converts them back to binary string of digits and stores it in result

		else if (ALUOp == 0 && !ALUSrc)//add readdata1 and readdata2
			result = in1 + in2;

		else if (ALUOp == 1 && ALUSrc)//readdata1 - sign_ext_imm
			result = in1 - imm;

		else if (ALUOp == 1 && !ALUSrc)//readdata1 < readdata2
			result = (in1 < in2);

		else if (ALUOp == 2 && !ALUSrc)//Branch Less than or Equal
			result = (in1 <= in2);

		else if (ALUOp == 3 && !ALUSrc)
			result = in1 ^in2;

		else throw invalid_argument("Invalid ALU operation code");
}
