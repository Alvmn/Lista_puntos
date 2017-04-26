#include <iostream>
#include "Clases.h"
#include "funciones1.cpp"
using namespace std;
void decirhola(){cout << "hola" << endl;}
void main(){
	Punto A(0, 10.0);
	lista_puntos Lista(3, A);
	Lista.getl()[0].edit(2,5);
	Lista.getl()[2].edit(7.25,908.5);
	
	cout << "Imprimimos la lista inicial, con dos puntos editados" << endl;;
	Lista.print();
	Punto a(3.56,8.9678);
	Punto b(345,777.5);
	Punto c(567,3423);
	Punto d(609.4546,234562.78);
	Punto e(56609.46746,1162.738);
	Punto f(56.4546,2.78);
	//Insertamos puntos
	Lista.push_break(a);
	Lista.push_break(b);
	Lista.push_break(c);
	Lista.push_break(d);
	Lista.push_break(e);
	Lista.push_break(f);

	decirhola();

	cout << "Insertando puntos..." << endl;
	cout << "Lista tras insertar" << endl;
	Lista.print();
	cout<< "El tamanho es: "<<Lista.get_size()<<" y la capacidad actual: "<< Lista.get_capacity() << endl;
	cout <<endl<< "Ahora hacemos pop() a los siguientes puntos: " << endl;
	Lista.pop().print();
	Lista.pop().print();
	Lista.pop().print();
	cout <<endl << "La nueva lista sin esos puntos es: " << endl;
	Lista.print();
	cout<< "El tamanho es: "<<Lista.get_size()<<" y la capacidad actual: "<< Lista.get_capacity() << endl;
	Punto::times_created();
	decirhola();
	//QUI DISIS
	//QUITE HOLA
	// HE PUESTO HOLA
	// a VER
	// A VER EL MERGE
	//DALE
	//nuevo
	//joder
	
	//PARA VER SI HACE MERGE CON LA RAMA
}
