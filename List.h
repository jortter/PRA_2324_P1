#ifndef LIST_H
#define LIST_H

#include <stdexcept>  // Para std::out_of_range


// Clase abstracta genérica; este tipo de clases SOLO definen los métodos (no tienen atributos)
template <typename T> 
class List {
    public:       
	// Metodos virtuales
		virtual void insert(int pos, T e) = 0;

        // Inserta el elemento e al final de la lista
        virtual void append(T e) = 0;

        // Inserta el elemento e al principio de la lista
        virtual void prepend(T e) = 0;

        // Elimina y devuelve el elemento en la posición pos
        virtual T remove(int pos) = 0;

        // Devuelve el elemento en la posición pos
        virtual T get(int pos) = 0;

        // Busca la primera ocurrencia de e y devuelve su posición, o -1 si no está
        virtual int search(T e) = 0;

        // Indica si la lista está vacía
        virtual bool empty() = 0;

        // Devuelve el número de elementos en la lista
        virtual int size() = 0;
};

#endif
