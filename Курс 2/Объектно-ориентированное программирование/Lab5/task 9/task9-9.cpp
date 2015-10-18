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
    private:
        double a;
        double b;
        double c; 
};

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
	try{
		if(a == 0)
			throw 0;
		if(b == 0)
			throw '1';
    x = -b/(2*a);
    y = (b*b - 4*a*c)/(4*a);
    return sqrt(x*x + y*y);
	}catch(int c){
		if(c == 0)
			printf("Boom!Boom!\n");
	
	};
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

	try{
    	distance1 = jeden.Distance();
	}catch(char c){
		if(c == '1')
			printf("Boom Boom\n");
	}
    printf("Расстояние между вершиной параболы и началом координат: %lf\n", distance1);
    trzy = trzy.Add(jeden, dwa);
    printf("Сумма коэффицентов двух парабол:");
    trzy.Display();

}
