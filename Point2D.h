#ifndef POINT2D_H
#define POINT2D_H

#include <ostream>

class Point2D{
    // ... definición de la clase point2d.h ... 
	public:
	// atributos
		double x, y;	// coordenadas x, y

	// métodos
		// constructor
		Point2D(double x = 0, double y = 0); 
		
		// calcula la distancia euclidiana entre dos puntos a y b
		static double distance(const Point2D &a, const Point2D &b);

				// la sobrecarga global de operadores binarios (== o !=) necesitan el friend solo si se necesita acceder a atributos y/o métodos privados.
		// cuando tienen el friend, se declara la funcion dentro de la clase pero se implementa fuera de la clase

		// comprueba si dos puntos son iguales
		friend bool operator==(const Point2D &a, const Point2D &b);

		// comprueba si dos puntos son diferentes
		friend bool operator!=(const Point2D &a, const Point2D &b);

		// sobrecarga global del operador <<
		friend std::ostream& operator<<(std::ostream &out, const Point2D &p);
};

#endif

// Comprobar si la sintaxis es correcta: g++ -fsyntax-only Point2D.h
