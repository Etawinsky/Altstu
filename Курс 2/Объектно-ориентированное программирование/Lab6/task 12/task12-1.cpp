/*  Школа имеет целые поля - количество учеников и количество учителей в школе. 
    Определить метод вычисления среднего числа учеников, приходящихся на одного  учителя (вещественное число).
    Основным классом является районный отдел образования, в котором в подчинении 3 школы и заданное число инспекторов.
    Определить метод, вычисляющий общее число людей, 
    занятых в образовании и школу с максимальным числом учеников на одного учителя. */

#include "stdio.h"
#include "string.h"
#include <iostream>
using namespace std;
class Szkola{
    public:
        void Init(int _studenci, int _nauczycieli);
        Szkola(int _studenci, int _nauczycieli);
        Szkola();
        void Read();
        void Display();
        double Srednia();
        int Nauczycielej();
    protected:
        int studenci;
        int nauczycieli;
};
class OrGymnazium: public Szkola{
	public:
		double Srednia();
        OrGymnazium(int _studenci, int _nauczycieli, int _isgymnazium);
        OrGymnazium();
	protected:
		int isgymnazium;


};
class BigOne: public OrGymnazium
{
	private:
		Szkola Szkola1;
		OrGymnazium OrGymnazium;
	public:
		double SredniaTwo();
		BigOne(int _studenci1, int _nauczycieli1, int _studenci2, int _nauczycieli2, int _isgymnazium);

};

BigOne::BigOne(int _studenci1, int _nauczycieli1, int _studenci2, int _nauczycieli2, int _isgymnazium): OrGymnazium(_studenci2, _nauczycieli2, _isgymnazium)
{
	Szkola1.Init(_studenci1, _nauczycieli1);
}
double BigOne::SredniaTwo()
{
	return Szkola1.Srednia() + OrGymnazium.Srednia();
}

void Szkola::Init(int _studenci, int _nauczycieli)
{
    studenci = _studenci;
    nauczycieli = _nauczycieli;
}



void Szkola::Read()
{
    scanf("%d %d", &studenci, &nauczycieli);
}

void Szkola::Display()
{
    printf("%d %d\n", studenci, nauczycieli );
}

double Szkola::Srednia()
{
    return studenci/(double)nauczycieli;
}

int Szkola::Nauczycielej(){
    return nauczycieli;
}



Szkola::Szkola(int _studenci, int _nauczycieli)
{
	studenci = _studenci;
	nauczycieli = _nauczycieli;
}

Szkola::Szkola()
{
	studenci = 0;
	nauczycieli = 0;
}
OrGymnazium::OrGymnazium(int _studenci, int _nauczycieli, int _isgymnazium)
{
	studenci = _studenci;
	nauczycieli = _nauczycieli;
	isgymnazium = _isgymnazium;
}

OrGymnazium::OrGymnazium()
{
	studenci = 0;
	nauczycieli = 0;
	isgymnazium = 0;
}

double OrGymnazium::Srednia()
{
	if(isgymnazium)
    	return 2 * studenci/(double)nauczycieli;
	else 
		return  studenci/(double)nauczycieli;
}
int main()
{
	BigOne *test = new BigOne(1,2,3,4,5);
   	cout<< test->SredniaTwo() << "\n"; 	

}
