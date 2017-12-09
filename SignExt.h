//
//  SignExt.hpp
//  ArchiProj
//
//  Created by Mostafa Henna on 11/30/17.
//  Copyright © 2017 Mostafa Henna. All rights reserved.
//

#ifndef SignExt_h
#define SignExt_h

#include <stdio.h>
#include <string>
class SignExt
{
    std::string in, out;
    
public:
    SignExt(std::string);
    std::string getextended();
};
#endif /* SignExt_h */
