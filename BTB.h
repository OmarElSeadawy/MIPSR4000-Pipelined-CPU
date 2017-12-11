#pragma once
#include <unordered_map>
#include "dialog.h"
#include "ui_dialog.h"
#include <QVarLengthArray>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
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
	uint8_t getpb(int pc);
    void fetch_map(vector<vector<QString>> &);
};
