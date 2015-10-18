/*  Класс парабола представлен тремя полями a, b, c. (ax2+bx+c) .
    Реализовать метод, вычисляющий расстояние от вершины параболы до начала координат и суммирующий две параболы.
    В результате суммирования соответствующие коэффициенты складываются. 
 
 

	Метод, по варианту задания в task1  языка C++,
   	возвращающий целое или вещественное значение сделать статическим.
   	[см.1) лек. 5]. В main продемонстрировать вызов метода классом. 
	Задание выполнить в новом проекте.

 */

#include <cmath>
#include "stdio.h"

class Parabola{
    public:
        void Init(double _a, double _b, double _c);
        void Read();
        void Display();

        static double Distance(Parabola x);
 
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


double Parabola::Distance(Parabola x){
    double c;
    double y;
    c = -x.b/(2*x.a);
    y = (x.b*x.b - 4*x.a*x.c)/(4*x.a);
    return sqrt(c*c + y*y);
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
    distance1 = Parabola::Distance(jeden);
    printf("Расстояние между вершиной параболы и началом координат: %lf\n", distance1);
    trzy = trzy.Add(jeden, dwa);
    printf("Сумма коэффицентов двух парабол:");
    trzy.Display();

}
