#include <ostream>
#include "List.h"
#include <stdexcept>  // Para std::out_of_range

template <typename T> 
class ListArray : public List<T> {

    private:
		// Atributos
		T* arr;		// Puntero al array dinamico
		int max;	// Tamaño del array
		int n;		// Numero de elementos de la lista
		static const int MINSIZE = 2;	// Tamaño minimo del array que debe inicializarse a 2

        // miembros privados
		void resize(int new_size) {
            T* new_arr = new T[new_size];  // Crear nuevo array dinámico
            for (int i = 0; i < n; ++i) {
                new_arr[i] = arr[i];       // Copiar elementos actuales
            }
            delete[] arr;                  // Liberar memoria del array antiguo
            arr = new_arr;                 // Actualizar el puntero
            max = new_size;                // Actualizar la capacidad máxima
        }  

	public:
        // miembros públicos, incluidos los heredados de List<T>
		// Constructor sin argumentos
		ListArray() {
   			arr = new T[MINSIZE];  // Reservar memoria para el array inicial
    		max = MINSIZE;         // Inicializar la capacidad máxima al valor mínimo
    		n = 0;                 // Inicializar el número de elementos a 0
		}	
		~ListArray() {
            delete[] arr;  // Liberar la memoria dinámica
        }
		// Sobrecarga del operador []
        T operator[](int pos) {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición fuera de rango");
            }
            return arr[pos];
        }	
		// Sobrecarga del operador << para imprimir la lista
        friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list) {
            out << "[";
            for (int i = 0; i < list.n; ++i) {
                out << list.arr[i];
                if (i < list.n - 1) {
                    out << ", ";
                }
            }
            out << "]";
            return out;
        }
};
