using namespace std;

class Punto {
	double x;
	double y;
	static int nref;
public:
	void print(ostream &o=cout);
	Punto(double a, double b);
	Punto();
	void edit(double a, double b);
	static void times_created();
};


class lista_puntos {
	int size;
	int capacity;
	Punto *l;
public:
	lista_puntos(int nEnum, const Punto &p);
	lista_puntos(const lista_puntos &list);
	~lista_puntos();
	Punto pop(); //Borra punto y lo devuelve
	void push_break(const Punto &p); //Inserta punto y duplica la capacidad si es necesario
	int get_size();
	int get_capacity();
	void print(ostream &o=cout); // pinta todos los puntos de la lista
	Punto * getl();
};