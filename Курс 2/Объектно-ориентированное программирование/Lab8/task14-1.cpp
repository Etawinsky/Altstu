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
        Parabola Add(Parabola jeden, Parabola dwa);
		friend void operator << (ostream &o, Parabola r);
		double geta() const{
			return a;
		}
		double getb() const{
			return b;
		}
		double getc() const{
			return c;
		}

	private:
        double a;
        double b;
        double c; 
};

class Parabaloid{
	private: 
        double a;
        double b;
        double c; 
		double z;
	public:
		Parabaloid();
        Parabaloid(double _a, double _b, double _c, double _z);
        void Init(double _a, double _b, double _c, double _z);
		void getdistance();
		void Put(double _z);
		double Get();
		void operator =(Parabola b);
		double geta() const{
			return a;
		}
		double getb() const{
			return b;
		}
		double getc() const{
			return c;
		}
		double getz() const{
			return z;
		}
		friend void operator << (ostream &o, Parabaloid r);
};
template <typename T> double Distance(T &A)
{
	double x;
    double y;
    x = -(A.getb())/(2*A.geta());
    y = (A.getb()*A.getb() - 4*A.getc()*A.geta())/(4*A.geta());
    return sqrt(x*x + y*y);

}
void operator << (ostream &o, Parabola r)
{
	cout<< r.c << r.a << r.b;
}

void operator << (ostream &o, Parabaloid r)
{
	cout<< r.z << r.a << r.b << r.c;
}
Parabaloid::Parabaloid()
{
	a = 0;
	b = 0;
	c = 0;
	z = 0;
}


Parabaloid::Parabaloid(double _a, double _b, double _c, double _z)
{
	
    a = _a;
    b = _b;
    c = _c;
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


/*
double Parabaloid::Distance()
{
    double x;
    double y;
    x = -b/(2*a);
    y = (b*b - 4*a*c)/(4*a);
    return sqrt(x*x + y*y) + z;
 
}
*/
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
/*
double Parabola::Distance(){
    double x;
    double y;
    x = -b/(2*a);
    y = (b*b - 4*a*c)/(4*a);
    return sqrt(x*x + y*y);
}
*/
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
	Parabola raz(1,2,3);
	Parabaloid	dwa(1,2,3,5);
	distance1 = Distance(raz);
	cout << distance1 << "\n";
	distance1 = Distance(dwa);
	cout << distance1 << "\n";
}
