/*  Школа имеет целые поля - количество учеников и количество учителей в школе. 
    Определить метод вычисления среднего числа учеников, приходящихся на одного  учителя (вещественное число).
    Основным классом является районный отдел образования, в котором в подчинении 3 школы и заданное число инспекторов.
    Определить метод, вычисляющий общее число людей, 
    занятых в образовании и школу с максимальным числом учеников на одного учителя.

В первой половине массива выбрать самое длинное название, во второй самое короткое.
 Перед вторым элементом самого длинного названия вставить элементы с 3 по 5 самого короткого названия. Вывести преобразованный элемент.
 */

#include "stdio.h"
#include "string.h"
#include <string>
#include <iostream>
using namespace std;
class Szkola{
    public:
        void Init(int _studenci, int _nauczycieli);
        void Read();
        void Display();
        double Srednia();
        int Nauczycielej();
    private:
        int studenci;
        int nauczycieli;
};

class Rajon{
    public:
        string Get_Imie();           /* Получить название района */
        void Set_Imie(string s);     /* Задать название района */
        void Init(int s1, int n1, int s2, int n2, int s3, int n3, int _inspektory, string s);
        void Read();
        Szkola Moar();              /* Определить наибольшее число учеников в одной из трех школ */
        int  Total();
        void Display();
    private: 
        string imie_rajona;
        int inspektory;
        Szkola Szkola1;
        Szkola Szkola2;
        Szkola Szkola3;
};

string Rajon::Get_Imie()
{
    return imie_rajona;
}           

void Rajon::Set_Imie(string s)
{
    imie_rajona = s;
}

void Rajon::Read()
{
    Szkola1.Read();
    Szkola2.Read();
    Szkola3.Read();
    scanf("%d", &inspektory);
}

void Rajon::Init(int s1, int n1, int s2, int n2, int s3, int n3, int _inspektory, string s)
{
    Szkola1.Init(s1, n1);
    Szkola2.Init(s2, n2);
    Szkola3.Init(s3, n3);
    inspektory = _inspektory;
    imie_rajona = s;
}

int  Rajon::Total()
{
    return Szkola1.Nauczycielej() + Szkola2.Nauczycielej() + Szkola3.Nauczycielej() + inspektory;
}

Szkola Rajon::Moar(){
    Szkola tmp; 
    if(Szkola1.Srednia() > Szkola2.Srednia())
        tmp = Szkola1;
    else 
        tmp = Szkola2;
    if(Szkola3.Srednia() > tmp.Srednia())
        tmp = Szkola3;
    return tmp;
}
void Szkola::Init(int _studenci, int _nauczycieli)
{
    studenci = _studenci;
    nauczycieli = _nauczycieli;
}


void Rajon::Display(){
    
    printf("Школа №1(ученики - учителя): ");
    Szkola1.Display();   
    printf("Школа №2(ученики - учителя): ");
    Szkola2.Display();   
    printf("Школа №3(ученики - учителя): ");
    Szkola3.Display();  
    printf("Количество инспекторов: ");
    printf("%d\n", inspektory);
    printf("Название района: ");
	cout << imie_rajona << "\n";
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
int main()
{
	const int N = 6;
    Rajon jeden[N];
	Rajon tmp;
	Rajon tmp2;
    int ludziej;
	int i;
	string temp;
    double srednia;
    Szkola moar;
    jeden[0].Init(3,2,0,1,4,0,0, "northern");
    jeden[1].Init(4,0,3,0,0,5,6, "southern");
    jeden[2].Init(8,0,2,0,9,0,7, "eastern");
    jeden[3].Init(8,4,0,3,0,7,3, "western");
    jeden[4].Init(7,0,0,0,4,0,0, "eifd");
    jeden[5].Init(2,0,4,1,2,0,1, "kreski");
	tmp = jeden[0];

	for(i =0 ; i < N /2; i++)
		if(tmp.Get_Imie().length() < jeden[i].Get_Imie().length())
			tmp = jeden[i];
	tmp2 = jeden[N/2];
	for(i = N/2; i < N; i++)
		if(tmp.Get_Imie().length() > jeden[i].Get_Imie().length())
			tmp2 = jeden[i];
	tmp.Display();
	tmp2.Display();
	temp = tmp2.Get_Imie();
//	temp = temp[2] + temp[3] + temp[4];
   	tmp.Set_Imie(tmp.Get_Imie().insert(1, temp, 2,3));
	tmp.Display();


}
