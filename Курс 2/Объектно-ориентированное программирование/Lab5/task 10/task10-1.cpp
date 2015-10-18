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
		static void matrix(int **array,int x, int n);
    private:
        double a;
        double b;
        double c; 
};

void Parabola::matrix(int **array,int x, int n)
{
	int tmp = x;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			array[i][j] = tmp;
		tmp = tmp * x;
	}
	

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

	const int x = 2;
	const int n = 6;
	int array[n][n];
	int *tmp[n];
	for(int i = 0; i < n; i++)
		tmp[i] = array[i];
	Parabola::matrix(tmp, x, n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			printf("%3d ", array[i][j]);
		printf("\n");
	}


}
