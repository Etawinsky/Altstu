/*  Школа имеет целые поля - количество учеников и количество учителей в школе. 
    Определить метод вычисления среднего числа учеников, приходящихся на одного  учителя (вещественное число).
    Основным классом является районный отдел образования, в котором в подчинении 3 школы и заданное число инспекторов.
    Определить метод, вычисляющий общее число людей, 
    занятых в образовании и школу с максимальным числом учеников на одного учителя. 
    
    Заменить поля объектов вспомогательного класса в основном классе 
    на массив объектов с изменением методов основного класса.  */

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
        char* Get_Imie();          
        void Set_Imie();     
        void Init(int *m, char *s);
        void Read();
        Szkola Moar();   
        int  Total();
        void Display();
    private: 
        char imie_rajona[30];
        int inspektory;
        Szkola Szkoly[3];
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
    Szkoly[0].Read();
    Szkoly[1].Read();
    Szkoly[2].Read();
    scanf("%d", &inspektory);
}

void Rajon::Init(int *m, char *s)
{
    Szkoly[0].Init(m[0], m[1]);
    Szkoly[0].Init(m[2], m[3]);
    Szkoly[0].Init(m[4], m[5]);
    inspektory = m[6];
    strcpy(imie_rajona, s);
}

int  Rajon::Total()
{
    return Szkoly[0].Nauczycielej() + Szkoly[1].Nauczycielej() + Szkoly[2].Nauczycielej() + inspektory;
}

Szkola Rajon::Moar(){

    Szkola tmp;
    int i;
    tmp = Szkoly[0].Srednia();
    for(i = 1; i < 3; i++)
        if(Szkoly[i] > tmp)
            tmp = Szkoly[i]
    return tmp;
}


void Szkola::Init(int _studenci, int _nauczycieli)
{
    studenci = _studenci;
    nauczycieli = _nauczycieli;
}


void Rajon::Display(){
    
    printf("Школа №1(ученики - учителя): ");
    Szkoly[0].Display();   
    printf("Школа №2(ученики - учителя): ");
    Szkoly[1].Display();   
    printf("Школа №3(ученики - учителя): ");
    Szkoly[2].Display();   
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
    int initial[] = {0, 0, 0, 0, 0, 0, 0};
    jeden.Init(initial, "Ленинский");
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
