#ifndef INTERPRETER_H
#define INTERPRETER_H
#include "execute.h"

class interpreter
{
public:
    interpreter();
    int code_type(string type);
    int code_operatidon(string opera);
    string eliminate_space(string code);
    string remove_backn(string code);
    void separate_line_code(string code);

    void separete_comand_variable(string code);
    string get_error();



public:
    execute ex;
    string msg;
};

#endif // INTERPRETER_H
