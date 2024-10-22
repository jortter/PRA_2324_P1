#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include "Shape.h"
#include <ostream>

// Comprobar si la sintaxis de este archivo.h es correcta: g++ -fsyntax-only Point2D.h

class Circle : public Shape {
	private:
	// Atributos
		Point2D center;		// Centro del círculo
		double radius;		// Radio del círculo
	
	public:
    // Métodos abstractos heredados de la interfaz Shape
		double area() const override;		// Método virtual puro. Calcula el área de una figura
		double perimeter() const override;	// " " ". Calcula el perímetro de una figura
		void translate(double incX, double incY) override;	// " " ". Traslada la figura sobre el espacio de representación, aplicando los incrementos de X e Y proporcionados
		void print() override;				// " " ". Imprimirá por pantalla información básica sobre la figura
	
	// Métodos de CIRCLE
		Circle();						// Constructor, crea un círculo del color que se haya establecido por defecto, centro (0,0) y radio 1
		Circle(std::string color, Point2D center, double radius);		// Método constructor (con parámetros)
		Point2D get_center() const;		// Método consultor del atributo center
		void set_center(Point2D p);		// Método modificador del atributo center
		double get_radius() const;		// Método consultor del atributo radius
		void set_radius(double r);		// Método modificador del atributo radius
		std::ostream& operator<<(std::ostream &out, const Circle &c);	// Sobrecarga global del operador <<. Recuerda incluir la cabecera <ostream> en el .h, así como declararlo friend en la clase.
};

#endif
