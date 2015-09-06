/*  Школа имеет целые поля - количество учеников и количество учителей в школе. 
    Определить метод вычисления среднего числа учеников, приходящихся на одного  учителя (вещественное число).
    Основным классом является районный отдел образования, в котором в подчинении 3 школы и заданное число инспекторов.
    Определить метод, вычисляющий общее число людей, 
    занятых в образовании и школу с максимальным числом учеников на одного учителя. */

#include "stdio.h"
#include "string.h"
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
        char* Get_Imie();           /* Получить название района */
        void Set_Imie(char *s);     /* Задать название района */
        void Init(int s1, int n1, int s2, int n2, int s3, int n3, int _inspektory);
        void Read();
        Szkola Moar();              /* Определить наибольшее число учеников в одной из трех школ */
        int  Total();
    private: 
        char imie_rajona[30];
        int inspektory;
        Szkola Szkola1;
        Szkola Szkola2;
        Szkola Szkola3;
};

char* Rajon::Get_Imie()
{
    return imie_rajona;
}           

void Rajon::Set_Imie(char *s)
{
    strcpy(imie_rajona, s);   
}

void Rajon::Read()
{
    Szkola1.Read();
    Szkola2.Read();
    Szkola3.Read();
    scanf("%d", &inspektory);
}

void Rajon::Init(int s1, int n1, int s2, int n2, int s3, int n3, int _inspektory)
{
    Szkola1.Init(s1, n1);
    Szkola2.Init(s2, n2);
    Szkola3.Init(s3, n3);
    inspektory = _inspektory;
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

void Szkola::Read()
{
    scanf("%d %d", &studenci, &nauczycieli);
}

void Szkola::Display()
{
    printf("%d %d", studenci, nauczycieli );
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
    Rajon jeden;
    int ludziej;
    double srednia;
    Szkola moar;
    jeden.Init(0,0,0,0,0,0,0);
    printf("введите количество учеников и преподавателей для трех школ, а так же количество инспекторов: ");
    jeden.Read();
    ludziej = jeden.Total();
    printf("Всего людей, занятых в образовании в данном районе:  %d\n", ludziej);
    moar = jeden.Moar();
    printf("Количество учеников и учителей в школе с наибольшим отношением ученик/преподаватель: ");
    moar.Display();
    printf("\n");
    srednia = moar.Srednia();  
    printf("Количество учеников на одного учителя в этой школе: %lf\n", srednia);
}
