#include "BTB.h"
#include <iostream>
using namespace std;

BTB::BTB()
{

}

uint8_t BTB::getpb(int pc)
{
	return btb[pc].pb;
}

bool BTB::find(int pc)
{
	unordered_map<int, TT>::const_iterator got = btb.find(pc);
	if (got != btb.end())
		return true;
	else
		return false;
}

void BTB::insert(int pc,int imm)
{
	TT temp;
	temp.target = pc+imm;
	temp.pb = 0;
	btb[pc] = temp;
}

void BTB::changestate(int pc, bool actual,bool &mistake)
{
	mistake = false;
	if (btb[pc].pb == 0 && actual)
	{
		btb[pc].pb = 1;
		mistake = true;
	}
	else if (btb[pc].pb == 0 && !actual)
		btb[pc].pb = 0;
	else if (btb[pc].pb == 1 && actual)
	{
		btb[pc].pb = 2;
		mistake = true;
	}
	else if (btb[pc].pb == 1 && !actual)
		btb[pc].pb = 0;
	else if (btb[pc].pb == 2 && actual)
		btb[pc].pb = 3;
	else if (btb[pc].pb == 2 && !actual)
	{
		btb[pc].pb = 1;
		mistake = true;
	}
	else if (btb[pc].pb == 3 && actual)
		btb[pc].pb = 3;
	else if (btb[pc].pb == 3 && !actual)
	{
		btb[pc].pb = 2;
		mistake = true;
	}
}

void BTB::fetch_map(vector<vector<QString>> &branch_buffer)
{
    unordered_map<int, TT>::iterator it;
    //int i = branch_buffer.size();

    //while(i>0)
        for(it = btb.begin(); it != btb.end(); it++)
        {
            vector<QString> v;
            
            v.push_back(QString::number(it->first));
            v.push_back(QString::number(it->second.target));
            v.push_back(QString::number(it->second.pb));
            
            branch_buffer.push_back(v);

        }
}



