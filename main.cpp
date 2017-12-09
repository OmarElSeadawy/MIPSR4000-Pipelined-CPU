#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bitset>
#include "Processor.h"
using namespace std;

int main()
{
	Processor p;
	try{
		p.loadprogram("suh.txt");
		p.execute();
	}
	catch (string s)
	{
		cout << s << endl;
	}

	system("pause");
		return 0;
}