//
// Created by fredi on 21/11/23.
//

#ifndef HASHTABLE_MYHASHTABLE_H
#define HASHTABLE_MYHASHTABLE_H

#include "string"
#include "list"


class MyHashTable{
public:  //Recuerden que esto sólo lo hacemos para poder revisar las actividades pero debería ser público
    std::list<std::pair<std::string , int>> * tabla; //Arreglo dinamico que contiene linkedlists ([0] = key, [1])

    int size;         //Cantidad de valores que hay almacenados en la tabla
    int sizeA;        //Capacidad max de la lista


public:
    void rehashing(); //Crece el arreglo al doble del tamaño del arreglo actual + 1
    int getPos(std::string key);

    MyHashTable();  //Tamaño inicial 11
    bool isEmpty(); //O(1)
    void put(std::string key,int value);
    int get(std::string key);
    void remove(std::string key);
};


#endif //HASHTABLE_MYHASHTABLE_H
