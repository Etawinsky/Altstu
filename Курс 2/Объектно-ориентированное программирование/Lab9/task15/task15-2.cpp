/*  Класс парабола представлен тремя полями a, b, c. (ax2+bx+c) .
    Реализовать метод, вычисляющий расстояние от вершины параболы до начала координат и суммирующий две параболы.
    В результате суммирования соответствующие коэффициенты складываются. */

#include <cmath>
#include "stdio.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Parabola{
    public:
        void Init(double _a, double _b, double _c);
		Parabola();
        Parabola(double _a, double _b, double _c);
        void Read();
       	virtual void Display();
       	virtual double Distance();
        Parabola Add(Parabola jeden, Parabola dwa);
		friend void operator << (ostream &o, Parabola r);
		friend bool operator >(Parabola a, Parabola b);
		friend bool operator <(Parabola a, Parabola b);
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
       	void Display();
		void operator =(Parabola b);
		friend void operator << (ostream &o, Parabaloid r);
};
void operator << (ostream &o, Parabola r)
{
	cout<< r.a << " "<< r.b<< " " << r.c;
}

void operator << (ostream &o, Parabaloid r)
{
	cout<< r.z<< " " << r.a << " "<< r.b<<" "  << r.c;
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
void Parabaloid::Display()
{
    printf("%lf %lf %lf %lf --%lf--\n", a, b, c, z , Distance());
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
    printf("%lf %lf %lf --%lf--\n", a, b, c, Distance());
}

double Parabola::Distance(){
    double x;
    double y;
    x = -b/(2*a);
    y = (b*b - 4*a*c)/(4*a);
    return sqrt(x*x + y*y);
}

Parabola Parabola::Add(Parabola jeden, Parabola dwa)
{
    Parabola tmp;
    tmp.a = jeden.a + dwa.a;
    tmp.b = jeden.b + dwa.b;
    tmp.c = jeden.c + dwa.c;
    return tmp;
}
bool operator >(Parabola a, Parabola b)
{
	if(a.a + a.b + a.c > b.a + b.b + b.c)
		return true;
	else 
		return false;
}
bool operator <(Parabola a, Parabola b)
{
	if(a.a + a.b + a.c < b.a + b.b + b.c)
		return true;
	else 
		return false;
}
bool les(Parabola *a, Parabola *b)
{
	if(dynamic_cast<Parabola*>(a) && dynamic_cast<Parabola*>(b))
		return ((Parabola* )a)->Distance() < ((Parabola* )b)->Distance();

	if(dynamic_cast<Parabaloid*>(a) && dynamic_cast<Parabaloid*>(b))
		return ((Parabaloid* )a)->Distance() > ((Parabaloid* )b)->Distance();

	if(dynamic_cast<Parabola*>(a) && dynamic_cast<Parabaloid*>(b))
		return true;
	
	if(dynamic_cast<Parabola*>(b) && dynamic_cast<Parabaloid*>(a)) 
		return false;

}
int main()
{
	vector <Parabola *>v1; 	
		
	double distance1;

	double par = 0;
	double parab = 0;
	Parabaloid *one, *two;	
	Parabola *three, *four;
	one = new Parabaloid(1,2,4,6);
	two= new Parabaloid(6,3,6,9);
	three= new Parabola(6,8,3);
	four = new Parabola(2,8,7);

	v1.push_back(three);
	v1.push_back(one);
	v1.push_back(two);
	v1.push_back(four);
	
	for(int i = 0; i< v1.size(); i++){
		(v1[i])->Display();
	}
	cout << endl;
	sort(v1.begin(), v1.end(), les );
	for(int i = 0; i< v1.size(); i++){
		(v1[i])->Display();
	}
	cout << "введите число: ";
	cin >> distance1;
	
	for(int i = 0; i< v1.size(); ){
		if (dynamic_cast<Parabaloid*>(v1[i])){
			if(v1[i]->Distance() > distance1){
				par++;
				v1.erase(v1.begin() + i);
			}else
				i++;
		}else{

			if(v1[i]->Distance() > distance1){
				parab++;
				v1.erase(v1.begin() + i);
			}else 
				i++;
		}
	}
	cout<< "объектов базового класса " << par << "\n";	
	cout<< "объектов производного класса " << parab << "\n";	
	cout<< "Осталось\n"; 
	
	for(int i = 0; i< v1.size(); i++){
		(v1[i])->Display();
	}
	for(int i = 0; i< v1.size(); i++){
		delete v1[i];
	}

    /*printf("Введите элементы параболы:");
    jeden.Read();
    printf("Введите элементы параболы:");
    dwa.Read();
    distance1 = jeden.Distance();
    printf("Расстояние между вершиной параболы и началом координат: %lf\n", distance1);
    printf("Сумма коэффицентов двух парабол:");
    trzy.Display(); */

}
