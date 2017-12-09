#ifndef PC_h
#define PC_h

#include <stdint.h>
#include <stack>
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
};

#endif /* PC_h */