#include "Imem.h"
using namespace std;

Imem::Imem()
{

}

void Imem::insert(int pc,Instruction inst)
{
	arr[pc] = inst;
}

void Imem::IF()
{
}

void Imem::IS(int pc, Instruction &i)
{
		i = arr[pc];
}