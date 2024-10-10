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

        // Inserta el elemento e en la posición pos
        void insert(int pos, T e) override {
            if(pos >= 0 && pos <= n){
				if(n == max){
					resize(2 * max);
				}
	
				for(int i = n; i > pos; i--){
					arr[i] = arr[i-1];		
				}
				
				// Asignación del elemento tras dejar hueco en el array
				arr[pos] = e;
				n++;
			}
			else
				throw std::out_of_range("Fuera del rango del array");
		}

		// Inserta el elemento e al final de la lista
		void append(T e) override {

			insert(n, e);  // Usa insert para agregar al final
		}


		// Inserta el elemento e al principio de la lista
		void prepend(T e) override{

			insert(0, e);

		}

        // Elimina y devuelve el elemento en la posición pos
        T remove(int pos) override {
            if(pos >= 0 && pos < n){
				// Guardamos el valor que será eliminado y es de tipo T
				T valor_eliminado = arr[pos];
				// Desplazamos TODOS  los elementos situados a la derecha del elemento a eliminar (pos) 1 posición a la izquierda, para así mantener la contigüidad del array
				for(int i = pos; i < n-1; i++){
					arr[i] = arr[i+1];
				}
			n--;
			return valor_eliminado;
			} else
				throw std::out_of_range("Fuera del rango del array");

		}

        // Devuelve el elemento en la posición pos
        T get(int pos)  override {
            if(pos >= 0 && pos < n){
				return arr[pos];
			} else
				throw std::out_of_range("Fuera del rango del array");
		}
        // Busca la primera ocurrencia de e y devuelve su posición, o -1 si no está
        int search(T e) const override {
            for (int i = 0; i < n; ++i) {
                if (arr[i] == e) {
                    return i;
                }
            }
            return -1;
        }

        // Indica si la lista está vacía
        bool empty() const override {
            if(n == 0)
				return true;
			else
				return false;
		}

        // Devuelve el número de elementos en la lista
        int size() const override {
            return n;
        }

		// Sobrecarga del operador []
        T operator[](int pos) {
            if(pos >= 0 && pos < n)	// Correcto si el elemento está dentro del rango [0, size()-1)]
				return arr[pos];		// Devuelve el elemento situado en la posición pos
			else
				throw std::out_of_range("Fuera del rango del array");
        }	

		// Sobrecarga del operador << para imprimir la lista
        friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list) {
            // Imprimir una instancia de ListArray<T> por pantalla
			if(list.n == 0)
				out << "List => []";
			else{
				out << "List => [";
				out << "\n";
				for (int i = 0; i < list.n; i++){
					out << "  ";
					out << list.arr[i];
					if(i != list.n -1){		// Si la posición del array i es distinto del ultimo elemento actual del array
						out << "\n";
					}
				}
				out << "\n";
				out << "]";
			}

			return out;
        }
};
