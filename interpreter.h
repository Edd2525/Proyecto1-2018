#ifndef INTERPRETER_H
#define INTERPRETER_H
#include "execute.h"

class interpreter
{
public:
    interpreter();
    void separate(string code);
    int find_function(string segment);



public:
    execute ex;
    string msg;
};

#endif // INTERPRETER_H
