#include <iostream>
#include "Clases.h"
using namespace std;

//Funciones Punto
int Punto::nref=0; //inicializo el static
Punto::Punto(double x, double y=3): x(x), y(y){nref++;}
Punto::Punto(): x(0), y(0){nref++;}
void Punto::print(ostream &o){ o<<"["<<x<<", "<<y<<"]"<<endl; }
void Punto::edit(double a= 0.0, double b=0.0){
	x=a;
	y=b;
}
void Punto::times_created(){
	cout << "Se han creado puntos "<<nref<<" veces, contando todos los puntos copiados y pivotados" << endl;
}


//IMPORTANTE Y POR ESO LA CAGUE, NO SE INDEXA CON SIZE EL ULTIMO PARAMETRO, SE INDEXA CON SIZE - 1 JODER
// LA INDEXACIÓN AL CREAR EN NEW NO SE PORTA COMO INDEXACIÓN, PERO SI LO HACE LUEGO Y ME JODIO HASTA QUE ME DI CUENTA XD
// PARA LA PRÓXIMA LO MEJOR SERÁ PRESCINDIR DE LOS ++ Y -- ALANTE Y DETRÁS QUE SON LIOSOS E SIMPLEMENTE INDEXAR CON SIZE-1 Y YA SEGUIDO
// HACER SIZE+=1 O SIZE-=1

// Funciones lista_puntos
lista_puntos::lista_puntos(int nEnum, const Punto &p){
	size=nEnum;
	capacity=nEnum;
	l = new Punto[size];
	for(int i=0;i<size;i++){ l[i] = p;}

}
lista_puntos::~lista_puntos(){
	delete[]l; 
}
lista_puntos::lista_puntos(const lista_puntos &list){
	size=list.size;
	capacity=list.capacity;
	if(l !=NULL) delete [] l;
	l = new Punto[capacity];
	Punto *a = list.l; //para no poner list.l debajo
	for(int i=0;i<size;i++){
		l[i]=a[i];
	}
}

void lista_puntos::print(ostream &o){
	o<<endl; //Esto deja una linea en blanco antes de escribir la lista, para ver el espaciado
	for(int i=0;i<size;i++){
		l[i].print(o);
	}
	o<<endl; //Esto deja una linea en blanco para lo siguiente que se escriba tras la lista
}
void lista_puntos::push_break(const Punto &p){
	 int cont=0; 
	 if(size<capacity && !cont) l[size++]=p, cont++; // ESE CONT VIENE EXPLICADO MAS ABAJO, ES PARA EVITAR QUE SE EJECUTE TBN EL OTRO IF EN UN CASO QUE SE DA EN EL CODIGO
						//Si tenemos capacidad de sobra, simplemete aumentamos size 1 ud y a la siguiente libre en l ponemos la p
									// EN ESTA ITERACIÓN PARA IR AL ELEMENTO SIZEviejo +1 que es donde asignamos el nuevo, al indexar SIZE +1 -1 = SIZE;
									// LUEGO EL ++ ATRAS PARA QUE UNA VEZ EJECUTADO NOS AUMENTA EL VALOR DE SIZE
									//ADEMÁS ESTE IF SE PONE DELANTE YA QUE SI LO PONEMOS DETRÁS DEL OTRO YA QUE AL ACABAR EL IF SIEMPRE SE CUMPLE QUE
									// QUE SIZE<CAPACITY ENTONCES EN ESE CASO PONER EL IF SERIA TONTERIA, PUES SE DARIAN LOS 2 A LA VEZ
	 //					PONER DOS IF A LA VEZ DA PROBLEMAS, POR TANTO PONGO ESTO COMO UN ELSE MEJOR
	 //					CON DOS IF A VECES EJECUTABA LAS 2 SENTENCIAS YA QUE SI SIZE ERA  < QUE CAPACITY POR 1 UD LUEGO CUMPLIA LA SEGUNDA CONDICION
	 //					UNA POSIBLE SOLUCION ES AÑADIR UNA VARIABLE EXTRA QEUE HAGA DE CONTADOR PARA QUE NO SE DEN LOS DOS IFS ES DECIR, IMPONGO QUE IF TAL Y
	 //					QUE SOLO HAYA HABIDO UN IF QUE PARA ESO ESTA PENSADO MI CODIGO
	 //					OTRA ALTERNATIVA ES UN ELSE SI SOLO HAY DOS CASOS YA QUE ASI TE ASEGURAS DE NO REPETIR, PERO SOLO VALE SI HAY 2 CASOS, TENER ESTO EN CUENTA SIEMPRE QUE 
	 //					HAYA VARIOS IF Y QUE EL PARAMETRO DEL QUE DEPENDEN VAYA AUMENTANDO.
	 if(size==capacity && !cont){
		 capacity=2*size;
		 Punto *a; //Array de puntos pivote
		 a = new Punto[size+1]; 
		 for(int i=0;i<size;i++){
			 a[i]=l[i]; //Copiamos l en a
		 }
		 a[size] = p; // AL INDEXAR SIEMPRE SE LLAMA 1 POSICION MENOS DEL SIZE, POR ESO, AHORA AL INDEXAR SIZE, EN REALIDAD PONEMOS LA POSICION DEL NUEVO
		 size++;//               TÉRMINO Y LUEGO AUMENTAMOS PARA AHORARNOS UN SIZE+=1
		  delete [] l;
		 l = new Punto[capacity]; // ahora nos aseguramos de que aumenta la capacidad
		 for(int i=0;i<size;i++){
			 l[i]=a[i]; //Copiamos a en l
		 }
		 delete [] a; // Finalmente borramos nuestro pivote y solo queda la nueva l
		 cont++; //Aqui aumentamos cont, aunque realmente al ser este el ultimo if no hace falta, solo es necesario aumentarlo en el primer if
	 }

									
	
}

Punto lista_puntos::pop(){
	Punto p; // Inicializamos valor punto nulo es decir 0,0
	Punto p1;
	p1=l[size-1]; //cogemos el valor a devolver, QUE AL INDEXAR SU INDICE SERÁ SIZE-1
	l[size-- -1]=p; // le damos el valor punto nulo al punto de la vieja posición y despues reducimos el size
	//             Así ya para la proxima si volvemos a meter un numero con push_break() sobrescribira el punto nulo creado
	//				El -1 por ser indexación y el -- para poner directamente despues de ejecutarse eso que size decrece 1
	return p1;
}

int lista_puntos::get_size(){return size;}
int lista_puntos::get_capacity(){return capacity;}
Punto* lista_puntos::getl(){
	return l;}