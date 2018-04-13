#ifndef DATA_NODO_H
#define DATA_NODO_H
#include "iostream"
#include "strstream"
using namespace std;

//estructura del nodo que almacen a las variables
class node{
public:
    node();
    /**
     * @brief node inicializa una nueva variable con su tipo de dato y su id unico
     * @param id    el nombre de la variable
     * @param data_ el tipo de variable que es(int,char,double...)
     */
    node(string id, int data_);


    /**
     * @brief assign_memory     asigan un espacio de memoria reservado a la variable
     * @param current_memory    la ubicacion actual de la memoria
     * @param data              el tipo de dato de la variable
     */
    void assign_memory(void *current_memory, string data);

    /**
     * @brief get_id    obtener id de la variable
     * @return          retorna el id;
     */
    string get_id();

    /**
     * @brief get_data_type     obtener el tipo de varible del nodo
     * @return                  retorna su tipo
     */
    string get_data_type();

    /**
     * @brief get_data      obtener el contenido del dato
     * @return              retorna el contenido del dato
     */
    string get_data();

    /**
     * @brief get_memory    obtener la memoria del dato
     * @return              retorna la memoria
     */
    void *get_memory();

    /**
     * @brief get_memory_move   obtener el espacio de memoria luego de agregar una variable
     * @return                  retorna el espacio de memoria que sigue
     */
    int get_memory_move();

    /**
     *@brief get_op_data    obtener el valor definido de cada tipo de dato
     * @return              retorna un int es el codigo del tipo de dato
     */
    int get_op_data();

    /**
     * @brief print_node    obtener todos el contenido del nodo con fines de pruebas
     */
    void print_node();

    /**
     * @brief print_node_console    mostrar los datos de la lista en la aplicacion
     * @return                      retorna un string con todos los datos
     */
    string print_node_console();

    ~node();


public:
    string ID;//nombre del nodo
    int data_type;//identificar el tipo del dato
    void *data;//especio de memoria del dato
    node *next;


};
#endif // DATA_NODO_H
