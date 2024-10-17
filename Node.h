#include <ostream>

template <typename T> 
class Node {
    public:
        // miembros públicos
   		// Atribtutos
		T data;			// Elemento almacenado de tipo T
		Node<T>* next;	// Puntero al siguiente nodo de la secuencia (o nullptr si es el último nodo de la secuencia).

		// Métodos
		Node(T data, Node<T>* next = nullptr){	// Constructor
			this->data = data;
			this->next = next;
		}

		friend std::ostream& operator<<(std::ostream &out, const Node<T> &node){ //Sobrecarga global del operador << para imprimir una instancia de Node<T> por pantalla. Se limitará a imprimir su atributo data.
			out << node.data;
			return out;
		}

};
