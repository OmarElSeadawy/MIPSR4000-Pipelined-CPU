#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bitset>
#include "Processor.h"
#include <stdint.h>
using namespace std;

bool isanaddress(string s)
{
	if (s[0] == '$')
	{
		for (int i = 1; i < s.length(); i++)
		if (!isdigit(s[i]))
			return false;
		return true;
	}
	return false;
}

bool isafield(string s)
{
	if (s[0] == '$')
	{
		for (int i = 1; i < s.length(); i++)
		{
			if (!isdigit(s[i]))
				return false;
		}
		return true;
	}
	else if (s[0] == '-' || isdigit(s[0]))
	{
		for (int i = 1; i < s.length(); i++)
		{
			if (!isdigit(s[i]))
				return false;
		}
		return true;
	}
	return false;
}


void Processor::loadprogram(string filename){

	string MIPSInst;
	string temp;
	string opcode, rs, rt, rd;
	string I_Immediate;
	string ShiftA;
	string funct;
	int rd1, rs1, rt1;
	int iimm;
	string j_imm;
	int jumpim;

	char Type;
	int c;
	int i = 1;
	ifstream SourceCode;
	SourceCode.open(filename);

	string m = "Syntax Error. Unknown instruction at line ";

	do
	{
		getline(SourceCode, temp, ' ');
		m = "Syntax Error. Unknown instruction at line " + to_string(i);
		if (temp == "ADD")
		{
			c = 1;
			Type = 'R';
		}
		else if (temp == "XOR")
		{
			c = 2;
			Type = 'R';
		}
		else if (temp == "JR")
		{
			c = 3;
			Type = 'R';
		}
		else if (temp == "SLT")
		{
			c = 4;
			Type = 'R';
		}
		else if (temp == "J")
		{
			c = 5;
			Type = 'J';
		}
		else if (temp == "ADDI")
		{
			c = 6;
			Type = 'I';
		}
		else if (temp == "LW")
		{
			c = 7;
			Type = 'I';
		}
		else if (temp == "SW")
		{
			c = 8;
			Type = 'I';
		}
		else if (temp == "BLE")
		{
			c = 9;
			Type = 'I';
		}
		else if (temp == "JP")
		{
			c = 10;
			Type = 'W';
		}
		else if (temp == "RP")
		{
			c = 11;
			Type = 'Q';
		}
		/*else if (temp == "\n")
		{
			SourceCode.ignore(256, '\n');
			continue;
		}*/
		else if (temp == "EXIT")
		{	
			Type = 'X';
		}
		else
			Type = 'E';
		switch (Type)
		{
		case 'X':
			SourceCode.ignore(256, '\n');
			rs1 = 17;
			rt1 = 17;
			rd1 = 17;
			iimm = 77777;
			jumpim = 77777;
		break;
		
		case 'Q':
			SourceCode.ignore(256, '\n');
			rs1 = 17;
			rt1 = 17;
			rd1 = 17;
			iimm = 77777;
			jumpim = 77777;
			break;
		case 'R':
			opcode = "000000";
			ShiftA = "00000";
			switch (c)
			{
			case 1: //ADD
				getline(SourceCode, rd, ',');
				getline(SourceCode, rs, ',');
				getline(SourceCode, rt);
				break;

			case 2: //XOR
				getline(SourceCode, rd, ',');
				getline(SourceCode, rs, ',');
				getline(SourceCode, rt);
				break;

			case 3: //JR
				getline(SourceCode, rs);
				rt = "$0";
				rd = "$0";
				break;

			case 4: //SLT
				getline(SourceCode, rd, ',');
				getline(SourceCode, rs, ',');
				getline(SourceCode, rt);
				break;
			}
			if (isanaddress(rd))
				rd.erase(rd.begin(), rd.begin() + 1);
			else
				throw "R-type Instruction in line " + to_string(i) + " must have rd as an address ($number).";
			if (isanaddress(rs))
				rs.erase(rs.begin(), rs.begin() + 1);
			else
				throw "R-type Instruction in line " + to_string(i) + " must have rs as an address ($number).";
			if (isanaddress(rt))
				rt.erase(rt.begin(), rt.begin() + 1);
			else
				throw "R-type Instruction in line " + to_string(i) + " must have rt as an address ($number).";

			if (stoi(rd)<0 || stoi(rd)>15)
				throw "R-type Instruction in line " + to_string(i) + " has an out of range rd.";
			if (stoi(rs)<0 || stoi(rs)>15)
				throw "R-type Instruction in line " + to_string(i) + " has an out of range rs.";
			if (stoi(rt)<0 || stoi(rt)>15)
				throw "R-type Instruction in line " + to_string(i) + " has an out of range rt.";

			rd1 = stoi(rd);
			rs1 = stoi(rs);
			rt1 = stoi(rt);
			iimm = 77777;
			jumpim = 77777;

			if (c == 3)
			{
				rt1 = 17;
				rd1 = 17;
			}


			break;
		case 'I':
			switch (c)
			{
			case 6: //ADDI
				getline(SourceCode, rt, ',');
				getline(SourceCode, rs, ',');
				getline(SourceCode, I_Immediate);
				break;

			case 7: //LW
				getline(SourceCode, rt, ',');
				getline(SourceCode, I_Immediate, '(');
				getline(SourceCode, rs, ')');
				SourceCode.ignore(256, '\n');
				break;

			case 8: //SW
				getline(SourceCode, rt, ',');
				getline(SourceCode, I_Immediate, '(');
				getline(SourceCode, rs, ')');
				SourceCode.ignore(256, '\n');
				break;

			case 9: //BLE
				getline(SourceCode, rt, ',');
				getline(SourceCode, rs, ',');
				getline(SourceCode, I_Immediate);
				break;
			}
			if (isanaddress(rs)) //Syntax Checking
				rs.erase(rs.begin(), rs.begin() + 1);
			else
				throw "I-type Instruction in line " + to_string(i) + " must have rs as an address ($number).";
			if (isanaddress(rt))
				rt.erase(rt.begin(), rt.begin() + 1);
			else
				throw "I-type Instruction in line " + to_string(i) + " must have rt as an address ($number).";
			if (isafield(I_Immediate) && !isanaddress(I_Immediate))
				iimm = stoi(I_Immediate);
			else
				throw "I-type Instruction in line " + to_string(i) + " must have Immediate as a positive or negative number.";

			if (stoi(rs)<0 || stoi(rs)>15)
				throw "I-type Instruction in line " + to_string(i) + " has an out of range rs.";
			if (stoi(rt)<0 || stoi(rt)>15)
				throw "I-type Instruction in line " + to_string(i) + " has an out of range rt.";

			rs1 = stoi(rs);
			rt1 = stoi(rt);
			rd1 = 17;
			iimm = stoi(I_Immediate);
			jumpim = 77777;

			break;


		case 'J':
		case 'W':
			//JUMP J
			//JUMP PROCEDURE W
			getline(SourceCode, j_imm);
			if (!isanaddress(j_imm) && isafield(j_imm))
				jumpim = stoi(j_imm);
			else
				throw "The jump instruction in line " + to_string(i) + " must have a number in its immediate field.";
			rs1 = 17;
			rt1 = 17;
			rd1 = 17;
			iimm = 77777;
			break;


		case 'E':
			throw m;
			break;


		}

			Instruction instr;
			instr.rs = rs1;
			instr.rt = rt1;
			instr.rd = rd1;
			instr.imm = iimm;
			instr.jimm = jumpim;
			instr.inst = temp;
			instr.type = Type;
			instr.pc = i - 1;
			imem.insert(i - 1, instr);
			cout << instr.inst << " " << instr.rd << " " << instr.rs << " " << instr.rt << " " << instr.imm << " " << instr.jimm << endl;

		i++; instcount++;
	} while (!SourceCode.eof());
	SourceCode.close();

}



void Processor::execute()
{
	Instruction instarray[100];
	uint8_t rss[100] = { 0 }, rts[100] = { 0 }, rds[100] = { 0 }, aluops[100] = { 0 }, jmps[100] = { 0 }, instnums[100] = { 0 }
	, stalls[100] = { 0 }, instnumsrts[100] = { 0 };
	bool regwrites[100] = { 0 }, regdsts[100] = { 0 }, alusrcs[100] = { 0 }, memwrs[100] = { 0 }, memrds[100] = { 0 }, toalus[100] = { 0 }, 
		tomems[100] = { 0 }, tofields[100] = { 0 }, fromems[100] = { 0 }, tofieldrts[100] = { 0 };
	int aluresults[100] = { 0 }, rsdatas[100] = { 0 }, rtdatas[100] = { 0 }, memouts[100] = { 0 }, imms[100] = { 0 }, jimms[100] = { 0 };
	bool jps[100] = { 0 };
	bool zflag;
	bool mistake = false;
	uint8_t st=0;
	bool inc; //Used in branching
	uint8_t totalst=0;
	int cnt;
	int cycles = 1;
	int ExitCounter = 0;
	bool enwb, entc, ends, endf, enex, enrf, enis,enif;
	bool written;
	while (cycles <=(8+(instcount-1)+totalst))
	{
	
			if (cycles < 8)
				enwb = 0;
			else
				enwb = 1;
			if (cycles < 7)
				entc = 0;
			else
				entc = 1;
			if (cycles < 6)
				ends = 0;
			else
				ends = 1;
			if (cycles < 5)
				endf = 0;
			else
				endf = 1;
			if (cycles < 4)
				enex = 0;
			else
				enex = 1;
			if (cycles < 3)
				enrf = 0;
			else
				enrf = 1;
			if (cycles < 2)
				enis = 0;
			else
				enis = 1;
			if (cycles < 1)
				enif = 0;
			else
				enif = 1;

			if (cycles > instcount + totalst)
				enif = 0;
			if (cycles > instcount + 1 + totalst)
				enis = 0;
			if (cycles > instcount + 2 + totalst)
				enrf = 0;
			if (cycles > instcount + 3 + totalst)
				enex = 0;
			if (cycles > instcount + 4 + totalst)
				endf = 0;
			if (cycles > instcount + 5 + totalst)
				ends = 0;
			if (cycles > instcount + 6 + totalst)
				entc = 0;
			if (cycles > instcount + 7 + totalst)
				enwb = 0;

			if (ExitCounter > 6)
				enif = enis = 0;
			else if (ExitCounter > 5)
				enif = enis = enrf = 0;
			else if (ExitCounter > 4)
				enif = enis = enrf = enex = 0;
			else if (ExitCounter > 3)
				enif = enis = enrf = enex = endf = 0;
			else if (ExitCounter > 2)
				enif = enis = enrf = enex = endf = ends = 0;
			else if (ExitCounter > 1)
				enif = enis = enrf = enex = endf = ends = entc = 0;
			else if (ExitCounter > 0)
				enif = enis = enrf = enex = endf = ends = entc = enwb = 0;

			if (cycles == 10)
				int x = 1;
		
			cout << "CYCLE "<< cycles << ": ";

			if (enwb)
			{
				/*if (cnt > 0)
				{
					totalst -= 2;
					if (cnt==1)
						cnt--;
					registerfile.WB(regdsts[cycles - 6 - totalst], regwrites[cycles - 6 - totalst],
						memwrs[cycles - 6 - totalst], instarray[cycles - 6 - totalst].rd, aluresults[cycles - 4],
						memouts[cycles - 2], instarray[cycles - 6 - totalst].rt);
					totalst += 2;
				}
				else if (cnt == 0 || cnt == -1)
				{
					cnt--;
				}
				else*/
				if (cnt == 1)
				{
					registerfile.WB(regdsts[cycles - 6 - totalst], regwrites[cycles - 6 - totalst],
						memwrs[cycles - 6 - totalst], instarray[cycles - 6 - totalst].rd, aluresults[cycles - 4],
						memouts[cycles - 2], instarray[cycles - 6 - totalst].rt);
					cnt--;
				}
				else if ((cnt == 3) || (cnt == 2))
				{

				}
				else
					registerfile.WB(regdsts[cycles - 6], regwrites[cycles - 6],
					memwrs[cycles - 6], instarray[cycles - 6].rd, aluresults[cycles - 4],
					memouts[cycles - 2], instarray[cycles - 6].rt);
			}

			if (entc)
			{
				/*if (cnt > 1)
				{
					totalst -= 2;
					if (cnt==2)
						cnt--;
					datamem.TagCheck(memrds[cycles - 5 - totalst], memouts[cycles]);
					totalst += 2;
				}
				else if (cnt == 0 ||  cnt == -1 )
				{
				}*/
				if (cnt == 2)
				{
					datamem.TagCheck(memrds[cycles - 5 - totalst], memouts[cycles]);
					cnt--;
				}
				else if ((cnt == 4) || (cnt == 3))
				{

				}
				else
					datamem.TagCheck(memrds[cycles - 5], memouts[cycles]);
			}
			
			if (ends)
			{
				/*if (cnt == 3)
				{
					totalst -= 2;
					cnt--;
					datamem.DataSecond(memwrs[cycles - 4 - totalst], memrds[cycles - 4 - totalst], memouts[cycles]);
					totalst += 2;
				}
				else if (cnt == 1 || cnt==0)
				{

				}*/
				if (cnt == 3)
				{
					datamem.DataSecond(memwrs[cycles - 4 - totalst], memrds[cycles - 4 - totalst], memouts[cycles]);
					cnt--;
				}
				else if ((cnt == 5) || (cnt == 4))
				{

				}
				else
					datamem.DataSecond(memwrs[cycles - 4], memrds[cycles - 4], memouts[cycles]);
			}
			
			if (endf)
			{


				if (cnt == 4)
				{
					if (instnumsrts[cycles - 3 - totalst] != 0)
					{
						if (tomems[cycles - 3 - totalst] != 0)
						{
							if (tofieldrts[cycles - 3 - totalst] == 1)
								rtdatas[cycles - 2] = aluresults[cycles - 2];
						}
					}

					datamem.DataFirst(aluresults[cycles - 1], rtdatas[cycles - 2], memwrs[cycles - 3 - totalst]);
					cnt--;
				}
				else
				{
					if (instnumsrts[cycles - 3] != 0)
					{
						if (tomems[cycles - 3] != 0)
						{
							if (tofieldrts[cycles - 3] == 1)
								rtdatas[cycles - 2] = aluresults[cycles - 2];
						}
					}

					datamem.DataFirst(aluresults[cycles - 1], rtdatas[cycles - 2], memwrs[cycles - 3]);
				}
			}
			if (cycles == 8)
				int x = 1;
			if (enex)
			{
				if (cnt == 5)
				{
					if (instnums[cycles - 2 - totalst] != 0)
					{
						if (toalus[cycles - 2 - totalst])
						{
							if (!fromems[cycles - 2 - totalst])
							{
								if (tofields[cycles - 2 - totalst] == 1)
									rsdatas[cycles - 1] = aluresults[cycles - instnums[cycles - 2]];
							}
							else
							{
								rsdatas[cycles - 1] = memouts[cycles - 1];
							}
						}
					}
					if (instnumsrts[cycles - 2 - totalst] != 0)
					{
						if (toalus[cycles - 2 - totalst])
						{
							if (!fromems[cycles - 2 - totalst])
							{
								if (tofieldrts[cycles - 2 - totalst] == 1)
									rtdatas[cycles - 1] = aluresults[cycles - instnumsrts[cycles - 2]];
							}
							else
							{
								if (tofieldrts[cycles - 2 - totalst] == 1)
									rtdatas[cycles - 1] = memouts[cycles - 1];
							}
						}
					}

					alu.EX(zflag, alusrcs[cycles - 2 - totalst], aluops[cycles - 2 - totalst], rsdatas[cycles - 1], instarray[cycles - 2 - totalst].imm, rtdatas[cycles - 1], aluresults[cycles]);
					if (aluops[cycles - 2 - totalst] == 2)
					{

						btb.changestate(pc.getpc(), aluresults,mistake);
						if (mistake)
						{

						}
					}
					cnt--;
				}
				else
				{
					if (instnums[cycles - 2] != 0)
					{
						if (toalus[cycles - 2])
						{
							if (!fromems[cycles - 2])
							{
								if (tofields[cycles - 2] == 1)
									rsdatas[cycles - 1] = aluresults[cycles - instnums[cycles - 2]];
							}
							else
							{
								rsdatas[cycles - 1] = memouts[cycles - 1];
							}
						}
					}
					if (instnumsrts[cycles - 2] != 0)
					{
						if (toalus[cycles - 2])
						{
							if (!fromems[cycles - 2])
							{
								if (tofieldrts[cycles - 2] == 1)
									rtdatas[cycles - 1] = aluresults[cycles - instnumsrts[cycles - 2]];
							}
							else
							{
								if (tofieldrts[cycles - 2 - totalst] == 1)
									rtdatas[cycles - 1] = memouts[cycles - 1];
							}
						}
					}

					alu.EX(zflag, alusrcs[cycles - 2], aluops[cycles - 2], rsdatas[cycles - 1], instarray[cycles - 2].imm, rtdatas[cycles - 1], aluresults[cycles]);
					if (aluops[cycles - 2] == 2)
					{
						btb.changestate(pc.getpc(), aluresults,mistake);
						if (mistake)
						{

						}
					}
				}
				
			}
			if (st > 0)
			{
				
				st--;
				cycles++;
				if (st == 0)
				{
					cnt = 6;
					totalst += 2;
				}
				continue;
			}

			if (enrf)
			{
				if (cnt == 6)
				{
					registerfile.RF(rsdatas[cycles], rtdatas[cycles], instarray[cycles - 1 - totalst].rs, instarray[cycles - 1 - totalst].rt);
					cnt--;
				}
				else
					registerfile.RF(rsdatas[cycles], rtdatas[cycles], instarray[cycles - 1].rs, instarray[cycles - 1].rt);
			}



			if (enis)
			{
				imem.IS(pc.getpc(), instarray[cycles]);
				if (instarray[cycles].inst == "EXIT")
					ExitCounter = 7;
			}
			
			//cout << instarray[pc.getpc()].type << " " << instarray[pc.getpc()].inst << endl;
			if (enif)
				imem.IF();
			if (enis)
			{
				CU.getSignals(instarray[cycles].type, instarray[cycles].inst, regwrites[cycles], regdsts[cycles], memwrs[cycles],
					memrds[cycles], alusrcs[cycles], aluops[cycles], jmps[cycles], jps[cycles]);
				Instruction i,i1,i2,i3;
				i.rs = 17;
				i.rt = 17;
				i.rd = 17;
				i.imm = 77777;
				i.jimm = 77777;
				i.type = 'X';
				i.inst = "X";

				i1.rs = 17;
				i1.rt = 17;
				i1.rd = 17;
				i1.imm = 77777;
				i1.jimm = 77777;
				i1.type = 'X';
				i1.inst = "X";
				
				i2.rs = 17;
				i2.rt = 17;
				i2.rd = 17;
				i2.imm = 77777;
				i2.jimm = 77777;
				i2.type = 'X';
				i2.inst = "X";

				i3.rs = 17;
				i3.rt = 17;
				i3.rd = 17;
				i3.imm = 77777;
				i3.jimm = 77777;
				i3.type = 'X';
				i3.inst = "X";
				if (cycles == 8)
					int x = 1;
				if (cycles > 2)
				{
					if (cycles == 3)
						HU.Forward(instarray[cycles],instarray[cycles-1] , i, i1, i2,instnums[cycles],tofields[cycles],toalus[cycles],tomems[cycles],
						fromems[cycles],tofieldrts[cycles],instnumsrts[cycles]);
					if (cycles==4)
						HU.Forward(instarray[cycles], instarray[cycles - 1], instarray[cycles-2], i1, i2, instnums[cycles], tofields[cycles], 
						toalus[cycles], tomems[cycles], fromems[cycles], tofieldrts[cycles], instnumsrts[cycles]);
					if (cycles==5)
						HU.Forward(instarray[cycles], instarray[cycles - 1], instarray[cycles-2], instarray[cycles-3], i2, instnums[cycles], 
						tofields[cycles], toalus[cycles], tomems[cycles], fromems[cycles], tofieldrts[cycles], 
						instnumsrts[cycles]);
					else if (cycles>5)
						HU.Forward(instarray[cycles], instarray[cycles - 1-totalst], instarray[cycles - 2 - totalst], instarray[cycles - 3-totalst], 
						instarray[cycles-4-totalst], instnums[cycles], tofields[cycles], toalus[cycles], tomems[cycles], fromems[cycles],tofieldrts[cycles]
						, instnumsrts[cycles]);

					if (cycles == 3)
						HU.Stall(instarray[cycles], instarray[cycles - 1], i, stalls[cycles]);
					else
						HU.Stall(instarray[cycles], instarray[cycles - 1],
						instarray[cycles - 2], stalls[cycles]);
				}

			}
			st = stalls[cycles];
			if (enis)
			{
				if (!btb.find(pc.getpc()))
					btb.insert(pc.getpc(), instarray[cycles].imm);
				else
				{
					if ((btb.getpb(pc.getpc()) == 0) || (btb.getpb(pc.getpc()) == 1))
						inc = true;
					else
						inc = false;
				}
				pc.increment(registerfile.Cheat(instarray[cycles].rs), instarray[cycles].jimm, instarray[cycles].imm, jmps[cycles], jps[cycles], inc);
			}
			cycles++;
			if(ExitCounter > 0)
				ExitCounter--;

	}

}

