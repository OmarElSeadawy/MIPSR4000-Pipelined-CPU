#include "HazardUnit.h"
#include <string>
#include <iostream>
using namespace std;

void HazardUnit::Forward(Instruction i, Instruction i1, Instruction i2, Instruction i3, Instruction i4, uint8_t &instnum, bool &tofield, bool &toalu, bool &tomem, bool &frommem, bool &tofieldrt, uint8_t & instnumrt)
{
	if (i.type == 'R' ||  i.inst == "SW")
	{
		instnum = 0;
		toalu = 1;
		tomem = 0;
		if (i4.type == 'R')
		{
			if (i4.rd == i.rs)
			{
				instnum = 4;
				tofield = 1;
			}
			if (i4.rd == i.rt)
			{
				instnumrt = 4;
				tofieldrt = 1;
				if (i.inst == "SW")
				{
					tomem = 1;
					toalu = 0;
				}
			}
		}
		else if (i4.inst == "LW" || i4.inst == "ADDI")
		{
			if (i4.rt == i.rs)
			{
				instnum = 4;
				tofield = 1;
			}
			if (i4.rt == i.rt)
			{
				instnumrt = 4;
				tofieldrt = 1;
				if (i.inst == "SW")
				{
					tomem = 1;
					toalu = 0;
				}
			}
			if (i4.inst == "LW")
				frommem = 1;
		}
		if (i3.type == 'R')
		{
			if (i3.rd == i.rs)
			{
				instnum = 3;
				tofield = 1;
			}
			if (i3.rd == i.rt)
			{
				instnumrt = 3;
				tofieldrt = 1;
			}
		}
		else if (i3.inst == "LW" || i3.inst == "ADDI")
		{
			if (i3.rt == i.rs)
			{
				instnum = 3;
				tofield = 1;
			}
			if (i3.rt == i.rt)
			{
				instnumrt = 3;
				tofieldrt = 1;
				if (i.inst == "SW")
				{
					tomem = 1;
					toalu = 0;
				}
			}
			if (i3.inst == "LW")
				frommem = 1;
			
		}

		if (i2.type == 'R')
			{
				if (i2.rd == i.rs)
				{
					instnum = 2;
					tofield = 1;
				}
				if (i2.rd == i.rt)
				{
					instnumrt = 2;
					tofieldrt = 1;
					if (i.inst == "SW")
					{
						tomem = 1;
						toalu = 0;
					}
				}
			}
			else if (i2.inst == "LW" || i2.inst == "ADDI")
			{
				if (i2.rt == i.rs)
				{
					instnum = 2;
					tofield = 1;
				}
				if (i2.rt == i.rt)
				{
					instnumrt = 2;
					tofieldrt = 1;
					if (i.inst == "SW")
					{
						tomem = 1;
						toalu = 0;
					}
				}
				if (i2.inst == "LW")
					frommem = 1;
			}

			if (i1.type == 'R')
			{
				if (i1.rd == i.rs)
				{
					instnum = 1;
					tofield = 1;
				}
				if (i1.rd == i.rt)
				{
					instnumrt = 1;
					tofieldrt = 1;
					if (i.inst == "SW")
					{
						tomem = 1;
						toalu = 0;
					}
				}
			}
			else if (i1.inst == "LW" || i1.inst == "ADDI")
			{
				if (i1.rt == i.rs)
				{
					instnum = 1;
					tofield = 1;
				}
				if (i1.rt == i.rt)
				{
					instnumrt = 1;
					tofieldrt = 1;
					if (i.inst == "SW")
					{
						tomem = 1;
						toalu = 0;
					}
				}
				if (i1.inst == "LW")
					frommem = 1;
			}



		
	}



		else if (i.inst == "ADDI" || i.inst == "LW")
		{
			instnum = 0;
			toalu = 1;
			tomem = 0;
			tofield = 0;
			tofieldrt = 0;
			if (i4.type == 'R')
			{
				if (i4.rd == i.rs)
				{
					instnum = 4;
					tofield = 1;
				}
			}
			else if (i4.inst == "LW" || i4.inst == "ADDI")
			{
				if (i4.rt == i.rs)
				{
					instnum = 4;
					tofield = 1;
				}
				if (i4.inst == "LW")
					frommem = 1;
			}

			else if (i3.type == 'R')
			{
				if (i3.rd == i.rs)
				{
					instnum = 3;
					tofield = 1;
				}
			}
			else if (i3.inst == "LW" || i3.inst == "ADDI")
			{
				if (i3.rt == i.rs)
				{
					instnum = 3;
					tofield = 1;
				}
				if (i3.inst == "LW")
					frommem = 1;
			}

			else if (i2.type == 'R')
			{
				if (i2.rd == i.rs)
				{
					instnum = 2;
					tofield = 1;
				}
			}
			else if (i2.inst == "LW" || i2.inst == "ADDI")
			{
				if (i2.rt == i.rs)
				{
					instnum = 2;
					tofield = 1;
				}
				if (i2.inst == "LW")
					frommem = 1;
			}

			if (i1.type == 'R')
			{
				if (i1.rd == i.rs)
				{
					instnum = 1;
					tofield = 1;
				}
			}
			else if (i1.inst == "LW" || i1.inst == "ADDI")
			{
				if (i1.rt == i.rs)
				{
					instnum = 1;
					tofield = 1;
				}
				if (i1.inst == "LW")
					frommem = 1;
			}
		}


		/*else if (i.inst == "SW")
		{
			instnum = 0;
			if (i1.type == 'R')
			{
				if (i1.rd == i.rs)
				{
					instnum = 1;
					tofield = 1;
					toalu = 1;
					tomem = 0;
				}
				if (i1.rd == i.rt)
				{
					instnumrt = 1;
					tofieldrt = 1;
					toalu = 0;
					tomem = 1;
				}
			}
			else if (i1.inst == "LW" || i1.inst == "ADDI")
			{
				if (i1.rt == i.rs)
				{
					instnum = 1;
					tofield = 1;
					toalu = 1;
					tomem = 0;
				}
				if (i1.rt == i.rt)
				{
					instnum = 1;
					tofieldrt = 1;
					toalu = 0;
					tomem = 1;
				}
				if (i1.inst == "LW")
					frommem = 1;
			}

			else if (i2.type == 'R')
			{
				if (i2.rd == i.rs)
				{
					instnum = 2;
					tofield = 1;
					toalu = 1;
					tomem = 0;
				}
				if (i2.rd == i.rt)
				{
					instnum = 2;
					tofieldrt = 1;
					toalu = 0;
					tomem = 1;
				}
			}
			else if (i2.inst == "LW" || i2.inst == "ADDI")
			{
				if (i2.rt == i.rs)
				{
					instnum = 2;
					tofield = 1;
					toalu = 1;
					tomem = 0;
				}
				if (i2.rt == i.rt)
				{
					instnum = 2;
					tofieldrt = 1;
					toalu = 0;
					tomem = 1;
				}
				if (i2.inst == "LW")
					frommem = 1;
			}

			else if (i3.type == 'R')
			{
				if (i3.rd == i.rs)
				{
					instnum = 3;
					tofield = 1;
					toalu = 1;
					tomem = 0;
				}
				if (i3.rd == i.rt)
				{
					instnum = 3;
					tofieldrt = 1;
					toalu = 0;
					tomem = 1;
				}
			}
			else if (i3.inst == "LW" || i3.inst == "ADDI")
			{
				if (i3.rt == i.rs)
				{
					instnum = 3;
					tofield = 1;
					toalu = 1;
					tomem = 0;
				}
				if (i3.rt == i.rt)
				{
					instnum = 3;
					tofieldrt = 1;
					toalu = 0;
					tomem = 1;
				}
				if (i3.inst == "LW")
					frommem = 1;
			}


			else if (i4.type == 'R')
			{
				if (i4.rd == i.rs)
				{
					instnum = 4;
					tofield = 1;
					toalu = 1;
					tomem = 0;
				}
				if (i4.rd == i.rt)
				{
					instnum = 4;
					tofieldrt = 1;
					toalu = 0;
					tomem = 1;
				}
			}
			else if (i4.inst == "LW" || i4.inst == "ADDI")
			{
				if (i4.rt == i.rs)
				{
					instnum = 4;
					tofield = 1;
					toalu = 1;
					tomem = 0;
				}
				if (i4.rt == i.rt)
				{
					instnum = 4;
					tofieldrt = 1;
					toalu = 0;
					tomem = 1;
				}
				if (i4.inst == "LW")
					frommem = 1;
			}
		}*/


	
}
void HazardUnit::Stall(Instruction i, Instruction i1, Instruction i2, uint8_t &stall)
{
	stall = 0;
	if (i1.inst == "LW")
	{
		if (i.type == 'R')
		{
			if (i.rs == i1.rt)
				stall = 2;
			if (i.rt == i1.rt)
				stall = 2;
		}
		else if (i.type == 'I')
		{
			if (i.rs == i1.rt)
				stall = 2;

		}
	}
	else if (i2.inst == "LW")
	{
		if (i.type == 'R')
		{
			if (i.rs == i2.rt)
				stall = 1;
			if (i.rt == i2.rt)
				stall = 1;
		}
		else if (i.type == 'I')
		{
			if (i.rs == i2.rt)
				stall = 1;
		}
	}
}