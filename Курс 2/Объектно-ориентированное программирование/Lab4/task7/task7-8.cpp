/*  Класс парабола представлен тремя полями a, b, c. (ax2+bx+c) .
    Реализовать метод, вычисляющий расстояние от вершины параболы до начала координат и суммирующий две параболы.
    В результате суммирования соответствующие коэффициенты складываются. */

#include <cmath>
#include "stdio.h"

class Parabola{
    public:
        void Init(double _a, double _b, double _c);
        void Read();
        void Display();
        double Distance();
        Parabola Add(Parabola jeden, Parabola dwa);
		Parabola operator + ( Parabola dwa);
		Parabola operator + ( int num);
		friend Parabola operator + ( int num, Parabola dwa);
		Parabola & operator ++ (void);
		Parabola operator ++ (int unused);
    private:
        double a;
        double b;
        double c; 
};

 Parabola operator + ( int num, Parabola dwa)
{
	Parabola tmp;
	tmp.a = dwa.a;
	tmp.b = dwa.b + num;
	tmp.c = dwa.c;
}
Parabola Parabola::operator ++ (int unused)
{
	Parabola tmp = *this;
	this->b = this->b +1;
	return tmp;
}
Parabola & Parabola::operator ++ (void){
	this->b++;
	return *this;
}
Parabola Parabola::operator + (int num)
{
    Parabola tmp = *this;
    tmp->a = tmp-> + num;    
    return tmp;
}
Parabola Parabola::operator + (Parabola dwa)
{
    Parabola tmp;
    tmp.a = this->a + dwa.a;
    tmp.b = this->b + dwa.b;
    tmp.c = this->c + dwa.c;
    return tmp;
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
    Parabola jeden, dwa, trzy;
    jeden.Init(0,0,0);
    dwa.Init(0,0,0);
    printf("Введите элементы параболы:");
    jeden.Read();
    printf("Введите элементы параболы:");
    dwa.Read();
    distance1 = jeden.Distance();
    printf("Расстояние между вершиной параболы и началом координат: %lf\n", distance1);
	dwa.Display();
    dwa = 5 + dwa ;
	dwa.Display();

    dwa =dwa++;
	dwa.Display();
    printf("Сумма коэффицентов двух парабол:");
    trzy = jeden + dwa;
	trzy.Display();

}
