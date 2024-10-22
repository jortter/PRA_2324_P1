#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include "Point2D.h"

class Shape{
	
	protected:
	// Atributos
		std::string color;
	
	public:
	// Métodos
		Shape();							// Constructor crea una figura
		Shape(std::string color);			// Crea figura de color, excepción si color no válido
		std::string get_color() const;		// Devuelve el color relleno de la figura
		void set_color(std::string c);		// Modifica el color relleno de la figura, excepción si color no válido
		// Los  métodos virtuales puros los igualamos a 0
		virtual double area() const = 0;		// Método virtual puro. Calcula el área de una figura
		virtual double perimeter() const = 0;	// " " ". Calcula el perímetro de una figura
		virtual void translate(double incX, double incY) = 0;	// " " ". Traslada la figura sobre el espacio de representación, aplicando los incrementos de X e Y proporcionados
		virtual void print() = 0;				// " " ". Imprimirá por pantalla información básica sobre la figura

};


#endif
