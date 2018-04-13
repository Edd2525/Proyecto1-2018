#ifndef DATA_LIST_H
#define DATA_LIST_H
#include "data_nodo.h"

class data_list
{
public:
    data_list();
    ~data_list();
    /**
     * @brief set_memory    Asigan el especio de memoria
     * @param memory        especio de memoria
     */
    void set_memory(void *memory);

    /**
     * @brief get_memory    obtener el especio de memoria del nodo
     * @return              espacio de memoria
     */
    void *get_memory();

    /**
     * @brief initialize_data   inicializa una nueva variable
     * @param id                el nombre de la variable
     * @param data_             el codigo del tipo de variable
     * @param data              un string con lo que se desea guardar en la variable
     * @return                  retorna true si fue guardada correcta mente
     */
    bool initialize_data(string id, int data_, string data);

    /**
     * @brief find_id   busca si existe un id con el mismo nombre
     * @param id        id que desea comprobar su existencia
     * @return          si esta disponible retorna true
     */
    bool find_id(string id);

    /**
     * @brief get_node  obtener el nodo de la variable deseada
     * @param id        id que se desea buscar
     * @return          retorna el nodo deseado
     */
    node *get_node(string id);

    /**
     * @brief get_id    obtener el id del nodo
     * @param nodo      el nodo buscado
     * @return          retorna su id
     */
    string get_id(node *nodo);

    /**
     * @brief get_type  obtener el tipo de dato
     * @param node      el nodo buscado
     * @return          returna su tipo
     */
    string get_type(node *node);

    /**
     * @brief get_memory obtener el especio de memoria
     * @param nodo      el nodo buscado
     * @return          retorna su ubicacion
     */
    void *get_memory(node *nodo);

    /**
     * @brief get_data  obtener el contenido del nodo
     * @param nodo      nodo buscado
     * @return          retorna el contenido de la variable
     */
    string get_data(node *nodo);

    /**
     * @brief show_list imprimir en consola el contenido de la lista
     */
    void show_list();

public:
    void *current, *start;
    node *node_head, *node_tail;
    string list;
};

#endif // DATA_LIST_H
