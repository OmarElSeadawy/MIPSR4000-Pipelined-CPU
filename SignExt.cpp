//
//  SignExt.cpp
//  ArchiProj
//
//  Created by Mostafa Henna on 11/30/17.
//  Copyright © 2017 Mostafa Henna. All rights reserved.
//

#include "SignExt.h"
using namespace std;

SignExt:: SignExt(string a): in(a) {}

string SignExt:: getextended()
{
    if (in[0] == 0)
        out = "0000000000000000" + in;
    
    else out = "1111111111111111" + in;
    
    return out;
}
