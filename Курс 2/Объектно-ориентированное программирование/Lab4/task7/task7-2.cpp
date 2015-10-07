/*  Класс парабола представлен тремя полями a, b, c. (ax2+bx+c) .
    Реализовать метод, вычисляющий расстояние от вершины параболы до начала координат и суммирующий две параболы.
    В результате суммирования соответствующие коэффициенты складываются. 
	
	
	Метод, по варианту задания в task1 языка C++, возвращающий целое или вещественное значение, 
	дополнить двумя методами, возвращающие значения через указатель (*) и через ссылку (&) [см.5) лек. 4]. 
	В main продемонстрировать все три метода.
 */

#include <cmath>
#include "stdio.h"

class Parabola{
    public:
        void Init(double _a, double _b, double _c);
        void Read();
        void Display();
        double Distance();
        void Distance(double *result);
        void Distance(double &result);
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
    x = -b/(2*a);
    y = (b*b - 4*a*c)/(4*a);
    return sqrt(x*x + y*y);
}

void Parabola::Distance(double &result)
{
	double x;
    double y;
    x = -b/(2*a);
    y = (b*b - 4*a*c)/(4*a);
	result =  sqrt(x*x + y*y);
}
void Parabola::Distance(double *result)
{
	double x;
    double y;
    x = -b/(2*a);
    y = (b*b - 4*a*c)/(4*a);
	*result =  sqrt(x*x + y*y);
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
    double distance, distance2;
	double *distance1; 
    Parabola jeden, dwa, trzy;
    jeden.Init(0,0,0);
//    dwa.Init(0,0,0);
    printf("Введите элементы параболы:");
    jeden.Read();
//    printf("Введите элементы параболы:");
//    dwa.Read();
    distance = jeden.Distance();
	printf("Distance: %lf\n", distance);
    jeden.Distance(distance1);
	printf("Distance1: %lf\n", distance1);
    jeden.Distance(&distance2);
	printf("Distance2: %lf\n", distance2);
/*
    printf("Расстояние между вершиной параболы и началом координат: %lf\n", distance1);
    trzy = trzy.Add(jeden, dwa);
    printf("Сумма коэффицентов двух парабол:");
    trzy.Display();
*/
}
