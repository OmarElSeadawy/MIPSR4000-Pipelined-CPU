#pragma once
#include <unordered_map>
#include <stdint.h>
using namespace std;

struct TT
{
	uint8_t pb;
	int target;
};
class BTB{
	unordered_map<int, TT> btb;
public:
	BTB();
	bool find(int);
	void insert(int,int);
	void changestate(int, bool,bool&);
	uint8_t BTB::getpb(int pc);
};