#ifndef EXECUTE_H
#define EXECUTE_H
#include "data_list.h"

class execute
{
public:
    execute();
    ~execute();

    /**
     * @brief initialize_data   inicializar una nueva variable
     * @param id                id de la variable
     * @param data_             codigo del tipo de dato
     * @param data              el contenido de la variable
     * @return                  retorna true si fue agregada correctamente
     */
    bool initialize_data(string id, int data_, string data);

    /**
     * @brief set_current   asigna la memoria reservada
     * @param memory        direccion de la memoria reservada
     */
    void set_current(void *memory);

    /**
     * @brief same_data_type    compara que dos variables sean del mismo tipo de dato
     * @param origen            variable a comparar
     * @param compare           variable a comparar
     * @return                  retorna true si tienen el mismo tipo de dato
     */
    bool same_data_type(node *origen, node *compare);

    /**
     * @brief operation     realiza multiples operaciones segun su codigo de la operacion
     * @param op            codico de la operacion
     * @param id1           variable donde se guardan los datos
     * @param id2           variable que se le aplica la operacion
     * @return              retorna true si se realizo correctamente
     */
    bool operation(int op, string id1, string id2);

    /**
     * @brief assignment    operacion de asignacion
     * @param origen        variable donde se guardan los datos
     * @param operation     variable
     * @return              retorna true si se realizo correctamente
     */
    bool assignment(node *origen, node *operation);

    /**
     * @brief sum           operacion de suma
     * @param origen        variable donde se guardan los datos
     * @param operation     variable
     * @return              retorna ture si se realizo correctamente
     */
    bool sum(node *origen, node *operation);

    /**
     * @brief subtraction   operacion de resta
     * @param origen        variable donde se guardan los datos
     * @param operation     variable
     * @return              retorna true si se realizo correctamente
     */
    bool subtraction(node *origen, node *operation);

    /**
     * @brief multiply      operacion de multiplicacion
     * @param origen        variable donde se guardan los datos
     * @param operation     variable
     * @return              retorna true si se realizo correctamente
     */
    bool multiply(node *origen, node *operation);

    /**
     * @brief divide        operacion de divicion
     * @param origen        variable donde se guardan los datos
     * @param operation     variable
     * @return              retorna true si se realizo correctamente
     */
    bool divide(node *origen, node *operation);

    /**
     * @brief get_msg   obtener los mensajes guardados de como va el programa
     * @return          retorna los mensajes
     */
    string get_msg();

    /**
     * @brief get_error obtener los mensajes guardados de los errores
     * @return          retorna los mensajes de errores
     */
    string get_error();

    /**
     * @brief show_list     mostrar el contenido de la lista
     */
    void show_list();

public:
    data_list registry;
    string msg, error;
};

#endif // EXECUTE_H
