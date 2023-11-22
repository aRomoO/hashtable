//
// Created by fredi on 21/11/23.
//

#include "MyHashTable.h"
#include "list"

MyHashTable::MyHashTable(){
    this->size=0;   //Valores almacenados
    this->sizeA=11; //Capacidad

    for (int i = 0; i < sizeA; ++i)
    {
        tabla[i] =  std::list<int>(this->sizeA);
    }
}
int MyHashTable::getPos(std::string key)
{
    size_t hashC = std::hash< std::string > {}(key);
    int hashCode = static_cast<int>(hashC);
    return 0;
}

bool MyHashTable::isEmpty()
{
    return (sizeof(tabla) == 0);
}

void MyHashTable::put(std::string key, int value)
{
    //Hacer la funcion de hash para encontrar el lugar al que pertenece el elemento
    //Añadir a la linked list de esa pocición
}
