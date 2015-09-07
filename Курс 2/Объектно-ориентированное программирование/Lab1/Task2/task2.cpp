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
        void Set_Imie();     /* Задать название района */
        void Init(int s1, int n1, int s2, int n2, int s3, int n3, int _inspektory, char *s);
        void Read();
        Szkola Moar();              /* Определить наибольшее число учеников в одной из трех школ */
        int  Total();
        void Display();
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

void Rajon::Set_Imie()
{
    scanf("%s", imie_rajona);
}

void Rajon::Read()
{
    Szkola1.Read();
    Szkola2.Read();
    Szkola3.Read();
    scanf("%d", &inspektory);
}

void Rajon::Init(int s1, int n1, int s2, int n2, int s3, int n3, int _inspektory, char *s)
{
    Szkola1.Init(s1, n1);
    Szkola2.Init(s2, n2);
    Szkola3.Init(s3, n3);
    inspektory = _inspektory;
    strcpy(imie_rajona, s);
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
    printf("%s\n", imie_rajona);
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
    Rajon jeden;
    int ludziej;
    double srednia;
    Szkola moar;
    jeden.Init(0,0,0,0,0,0,0, "Ленинский");
    printf("введите количество учеников и преподавателей для трех школ, а так же количество инспекторов: ");
    jeden.Read();
    ludziej = jeden.Total();
    printf("Всего людей, занятых в образовании в данном районе:  %d\n", ludziej);
    moar = jeden.Moar();
    printf("Количество учеников и учителей в школе с наибольшим отношением ученик/преподаватель: ");
    moar.Display();
    srednia = moar.Srednia();  
    printf("Количество учеников на одного учителя в этой школе: %lf\n", srednia);
    printf("Изменить название района: ");
    jeden.Set_Imie();
    printf("Название района стало: %s\n", jeden.Get_Imie());
    printf("Вся информация о районе: \n");
    jeden.Display();


}
