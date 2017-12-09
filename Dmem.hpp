//
//  Dmem.hpp
//  DataMem
//
//  Created by Asser Hangal on 11/30/17.
//  Copyright © 2017 Asser Hangal. All rights reserved.
//

#ifndef Dmem_hpp
#define Dmem_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Dmem
{
	int Memory[32]; //1KB
	int Addr, WriteData,ReadData;

public:
	Dmem();
	void DataFirst(int, int, bool );
	void DataSecond(bool, bool,int&);
	void TagCheck(bool,int &);
};


#endif /* Dmem_hpp */