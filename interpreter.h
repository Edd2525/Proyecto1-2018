#ifndef INTERPRETER_H
#define INTERPRETER_H
#include "execute.h"

class interpreter
{
public:
    /**
     * @brief interpreter inicializa y reserva la memoria(temporal)
     */
    interpreter();

    /**
     * @brief code_type  funcion para obtener el codigo del tipo de dato
     * @param type       tipo de dato
     * @return           retorna el codigo
     */
    int code_type(string type);

    /**
     * @brief code_operatidon   funcion para obtener el codigo de la operacion
     * @param opera             operacion deseada
     * @return                  retorna el codigo
     */
    int code_operatidon(string opera);

    string eliminate_space(string code);

    /**
     * @brief remove_backn  funcion para eliminar los \n del codigo
     * @param code          codigo
     * @return              retorna el codigo sin \n que se generan
     */
    string remove_backn(string code);

    /**
     * @brief separate_line_code    funcion que descompone el codigo principal en segmentos, separados por ";"
     * @param code                  codigo
     */
    void separate_line_code(string code);

    /**
     * @brief separete_comand_variable  funcion que descompone los segmentos de codigo segun lo que solicite
     * @param code                      segmento de codigo
     */
    void separete_comand_variable(string code);
    string get_error();



public:
    execute ex;
    string msg;
};

#endif // INTERPRETER_H
