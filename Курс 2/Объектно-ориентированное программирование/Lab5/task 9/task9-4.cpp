/*  Класс парабола представлен тремя полями a, b, c. (ax2+bx+c) .
    Реализовать метод, вычисляющий расстояние от вершины параболы до начала координат и суммирующий две параболы.
    В результате суммирования соответствующие коэффициенты складываются. 
 
 Метод Parabola задания в task1 языка C++ заменить на конструктор со всеми параметрами, 
 добавить конструктор с одним параметром и конструктор без параметров.
 В main продемонстрировать вызов всех конструкторов статическими и динамическими объектами.
 Инициализировать небольшой массив конструктором с одним параметром.
 */

#include <cmath>
#include "stdio.h"

class Parabola{
    public:
        Parabola(double _a, double _b, double _c);
        Parabola();
        Parabola(double _a);
        void Read();
        void Display();
        double Distance();
        Parabola Add(Parabola jeden, Parabola dwa);
    private:
        double a;
        double b;
        double c; 
};

Parabola::Parabola(double _a, double _b, double _c)
{
    a = _a;
    b = _b;
    c = _c;
}

Parabola::Parabola()
{
    a = 0;
    b = 0;
    c = 0;
}
Parabola::Parabola(double _a)
{
    a = _a;
    b = 0;
    c = 0;
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
    Parabola jeden(0,0,0);
    Parabola dwa(0);
    Parabola trzy(0);
	Parabola *test = new Parabola();
	Parabola tmp[3] = {1,2,3};
    
	
	printf("Введите элементы параболы:");
    jeden.Read();
    printf("Введите элементы параболы:");
    dwa.Read();
    distance1 = jeden.Distance();
    printf("Расстояние между вершиной параболы и началом координат: %lf\n", distance1);
    trzy = trzy.Add(jeden, dwa);
    printf("Сумма коэффицентов двух парабол:");
    trzy.Display();

}
