
// Created by fredi on 21/11/23.

#include <iostream>
#include <algorithm>
#include "MyHashTable.h"
#include "list"

MyHashTable::MyHashTable(){
    this->size=0;   //Valores almacenados
    this->sizeA=11; //Capacidad

    // Alloc mem para cada elemento del array
    tabla = new std::list<std::pair<std::string , int>>[sizeA];

}

bool MyHashTable::isEmpty()
{
    return (this->size == 0);
}
int MyHashTable::getPos(std::string key) {
    size_t hashC = std::hash<std::string>{}(key);
    int hashCode = static_cast<int>(hashC);

    // If it's negative, make it positive
    if (hashCode < 0)
        hashCode *= -1;

    // pos will be the modulo of hashC with the capacity of the array
    return hashCode % sizeA;

}


void MyHashTable::put(std::string key, int value)
{

    int pos = getPos(key);


    std::pair<std::string, int> keyval;
    keyval.first = key;
    keyval.second = value;
    this->tabla[pos].push_back(keyval);



    this->size++;

}
void MyHashTable::rehashing() {

    std::cout << "rehash \n";
    int newSizeA = sizeA * 2 + 1;  // Doble del tamaño actual + 1

    // Nueva tabla del nuevo tamaño
    std::list<std::pair<std::string, int>>* newTabla = new std::list<std::pair<std::string, int>>[newSizeA];

    // Mover elementos de la tabla actual a la nueva tabla:

    // Loop to iterate over the old array
    for (int i = 0; i < sizeA; ++i) {
        // Loop to iterate over each element in the linked list
        for (const auto& keyval : tabla[i]) {
            // Obtain the position in the new hash table
            int newPos = getPos(keyval.first);  // Use the new size
            std::cout << "newpos: " << newPos << std::endl;
            newTabla[newPos].push_back(keyval);
        }
    }


    // Liberar memoria de la tabla actual
    delete[] tabla;

    // Actualizar la tabla y la capacidad
    tabla = newTabla;
    sizeA = newSizeA;
}



int MyHashTable::get(std::string key) {
    // Obtener la posición
    int pos = getPos(key);

    // Recorrer la lista asociada a tabla[pos]
    for (auto it = tabla[pos].begin(); it != tabla[pos].end(); ++it) {
        if (it->first == key) {
            return it->second;
        }
    }

    // Si no se encuentra el valor, regresar -1
    return -1;
}


void MyHashTable::remove(std::string key) {
    // obtener posicion
    int pos = getPos(key);

    // iterador para encontrar el key en la linked list correspondiente a la key
    auto it =
            std::find_if(tabla[pos].begin(), tabla[pos].end(),
                    [key](const std::pair<std::string, int>& keyval)
                           {
                               return keyval.first == key;
                           });

    // el iterador contiene el nodo a borrar
        //Si se encuentra, borrarlo
    if (it != tabla[pos].end())
    {
        tabla[pos].erase(it);
        // actualizar tamaño
        --size;
    }
    else
    {
        // si no se encuentra, mostrar error
        throw std::invalid_argument("No se encontró el key a borrar");

    }

}