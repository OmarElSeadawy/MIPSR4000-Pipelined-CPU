#ifndef PC_h
#define PC_h

#include <stdint.h>
#include <stack>
#include "dialog.h"
#include "ui_dialog.h"
#include <QVarLengthArray>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
using namespace std;

class PC
{
	stack<int> ProcedureStack;
	int pc;
public:
	PC();
	void increment(int, int, int, uint8_t, bool&, bool);
	int getpc();
	void setpc(int x);
    void getStack(vector<QString> &);
};

#endif /* PC_h */
