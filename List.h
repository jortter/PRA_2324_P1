#ifndef LIST_H
#define LIST_H

#include <stdexcept>  // Para std::out_of_range


// Clase abstracta genérica
template <typename T> 
class List {
    public:       
	// Metodos virtuales
	// Inserta el elemento e en la posición pos
        virtual void insert(int pos, T e) = 0;

        // Inserta el elemento e al final de la lista
        virtual void append(T e) {
            insert(size(), e);  // append es equivalente a insertar al final
        }

        // Inserta el elemento e al principio de la lista
        virtual void prepend(T e) {
            insert(0, e);  // prepend es equivalente a insertar al inicio
        }

        // Elimina y devuelve el elemento en la posición pos
        virtual T remove(int pos) = 0;

        // Devuelve el elemento en la posición pos
        virtual T get(int pos) const = 0;

        // Busca la primera ocurrencia de e y devuelve su posición, o -1 si no está
        virtual int search(T e) const = 0;

        // Indica si la lista está vacía
        virtual bool empty() const = 0;

        // Devuelve el número de elementos en la lista
        virtual int size() const = 0;

        // Destructor virtual para garantizar la correcta destrucción de las subclases
        virtual ~List() {}
};

#endif
