#include "BTB.h"
using namespace std;

BTB::BTB()
{

}

void BTB::insert(int pc)
{
	btb[pc] = 0;
}

void BTB::changestate(int pc, bool actual)
{
	if (btb[pc] == 0 && actual)
		btb[pc] = 1;
	else if (btb[pc] == 0 && !actual)
		btb[pc] = 0;
	else if (btb[pc] == 1 && actual)
		btb[pc] = 2;
	else if (btb[pc] == 1 && !actual)
		btb[pc] = 0;
	else if (btb[pc] == 2 && actual)
		btb[pc] = 3;
	else if (btb[pc] == 2 && !actual)
		btb[pc] = 1;
	else if (btb[pc] == 3 && actual)
		btb[pc] = 3;
	else if (btb[pc] == 3 && !actual)
		btb[pc] = 2;
}