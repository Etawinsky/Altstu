/*  Класс парабола представлен тремя полями a, b, c. (ax2+bx+c) .
    Реализовать метод, вычисляющий расстояние от вершины параболы до начала координат и суммирующий две параболы.
    В результате суммирования соответствующие коэффициенты складываются. */

#include <cmath>
#include "stdio.h"
#include <iostream>

using namespace std;
class Parabola{
    public:
        void Init(double _a, double _b, double _c);
		Parabola();
        Parabola(double _a, double _b, double _c);
        void Read();
        void Display();
		virtual double Distance();
		void addtob();
        Parabola Add(Parabola jeden, Parabola dwa);
		friend void operator << (ostream &o, Parabola r);
	protected:
        double a;
        double b;
        double c; 
};

class Parabaloid:public Parabola{
	private : 
		double z;
	public:
		Parabaloid();
        Parabaloid(double _a, double _b, double _c, double _z);
        void Init(double _a, double _b, double _c, double _z);
		void getdistance();
     	double Distance();
		void Put(double _z);
		double Get();
		void operator =(Parabola b);
		friend void operator << (ostream &o, Parabaloid r);
};
void operator << (ostream &o, Parabola r)
{
	cout<< r.c << " " << r.a << " " << r.b << "\n";
}

void operator << (ostream &o, Parabaloid r)
{
	cout<< r.z << " " << r.c << " " << r.a << " " << r.b << "\n";
}
Parabaloid::Parabaloid()
{
	a = 0;
	b = 0;
	c = 0;
	z = 0;
}


Parabaloid::Parabaloid(double _a, double _b, double _c, double _z):Parabola(_a, _b, _c)
{
	z = _z;
}
/*
void Parabaloid::Init(double _a, double _b, double _c, double _z)
{
	Parabola::Init(_a,_b,_c)
    z = _z;
}
*/

void Parabaloid::Init(double _a, double _b, double _c, double _z)
{
    a = _a;
    b = _b;
    c = _c;
	z = _z;
}

void Parabaloid::operator =(Parabola b)
{
	this->z = b.Distance();
}
double Parabaloid::Distance()
{
    double x;
    double y;
    x = -b/(2*a);
    y = (b*b - 4*a*c)/(4*a);
    return sqrt(x*x + y*y) + z;
 
}
void Parabaloid::getdistance()
{
	z = a + b; 
}
void Parabaloid::Put(double _z)
{
	z = _z;
}

double Parabaloid::Get()
{
	return z;
}

Parabola::Parabola::Parabola()
{
	a = 0;
	b = 0;
	c = 0;
}
Parabola::Parabola(double _a, double _b, double _c)
{
    a = _a;
    b = _b;
    c = _c;
}
void Parabola::Init(double _a, double _b, double _c)
{
    a = _a;
    b = _b;
    c = _c;
}

void Parabola::Read()
{
    scanf("%lf %lf %lf", &a, &b, &c);
}

void Parabola::Display()
{
    printf("%lf %lf %lf\n", a, b, c);
}

double Parabola::Distance(){
    double x;
    double y;
    x = -b/(2*a);
    y = (b*b - 4*a*c)/(4*a);
    return sqrt(x*x + y*y);
}

void Parabola::addtob()
{
	b += Distance()/2;
}
Parabola Parabola::Add(Parabola jeden, Parabola dwa)
{
    Parabola tmp;
    tmp.a = jeden.a + dwa.a;
    tmp.b = jeden.b + dwa.b;
    tmp.c = jeden.c + dwa.c;
    return tmp;
}

int main()
{
    double distance1;
	
    Parabaloid jeden, dwa, trzy;
	Parabola *four= new Parabola(1,2,2);
	
	four->addtob();
	Parabaloid *five  = new Parabaloid(1,2,2,3);
	four =five;
	distance1 = four->Distance();
	cout<< distance1 << "\n";
	five->addtob();
	distance1 = five->Distance();
	cout <<distance1 <<"\n";
	
	
	/*Parabola test(1,2,3);
    jeden.Init(0,0,0,0);
    dwa.Init(0,0,0,0);
	dwa = test;
	*/
    /*printf("Введите элементы параболы:");
    jeden.Read();
    printf("Введите элементы параболы:");
    dwa.Read();
    distance1 = jeden.Distance();
    printf("Расстояние между вершиной параболы и началом координат: %lf\n", distance1);
    printf("Сумма коэффицентов двух парабол:");
    t
	rzy.Display(); */

}
