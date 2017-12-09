#pragma once
#include <unordered_map>
#include <stdint.h>
using namespace std;

class BTB{
	unordered_map<int, uint8_t> btb;
public:
	BTB();
	void insert(int);
	void changestate(int, bool);
};