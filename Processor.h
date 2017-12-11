#pragma once
//include imem,rf,dmem
#include <iostream>
#include "Dmem.hpp"
#include "RegFile.h"
#include "ALU.h"
#include "SignExt.h"
#include <stdint.h>
#include "ControlUnit.h"
#include "Imem.h"
#include "PC.h"
#include "HazardUnit.h"
#include "BTB.h"
#include "dialog.h"
#include "ui_dialog.h"
#include <QVarLengthArray>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
using namespace std;


class Processor{
	Imem imem;
	Dmem datamem;
	RegFile registerfile;
	ALU alu;
	ControlUnit CU;
	PC pc;
	BTB btb;
	int instcount = 0;
	HazardUnit HU;
    vector<vector<QString>> stage;
    
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
    uint8_t pb = 0;
    uint8_t previouspb = 0;
    bool inc; //Used in branching
    uint8_t totalst=0;
    uint8_t branchst = 0;
    int cnt;
    int i=0;
    int ExitCounter = 0;
    bool enwb, entc, ends, endf, enex, enrf, enis,enif;
    bool written;
    int temp;
    
public:
	Processor(){  };
	void loadprogram(string filename);
	void execute(bool , int);
    void getRegs(int []);
    void getMems(int []);
    void setStages(vector<vector<QString>> &);
    void pushRegs(vector<QString>, int);
    void PrintStage();
    int get_cycle(int &);
    void setBTB(vector<vector<QString>> &);
    void getStack(vector<QString> &);
};
