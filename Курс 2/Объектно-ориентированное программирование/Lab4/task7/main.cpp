//Номер в гостинице имеет поля – площадь(целое) и стоимость проживания
//в сутки(вещественное).Реализовать метод вычисления привлекательности
//номера для экономных туристов(отношение цены к площади).Основной класс
//гостиница содержит три поля номеров и целое – длительность туристского
//сезона.Определить метод вычисления общего ожидаемого дохода гостиницы за
//сезон и метод определения самого привлекательного номера из трех.
#include <iostream>
#include <string>
using namespace std;
const int N = 10;
class Room{
    //Класс номер
private:
    int area;
    double price;
public:
    void Display();
    void Init(int a,int b);
    double Attractive();
    double GetPrice();
};
double Room::GetPrice(){
    //Метод получения цены
    return price;
}
double Room::Attractive(){
    //Метод вычисления коэффициента привлекательности
    return area / price;
}
void Room::Display(){
    //Метод вывода на экран
    cout << "Area: " << area << " Price: " << price<<" Attractive: "
        <<Attractive()<<endl;
}
void Room::Init(int a,int b){
     area=a ;price=b;
}

class Hotel{
    //Класс отель
private:
    string name;
    Room *room;
    int count;
    int time;
public:
    void Display();
    void Init();
    Room Attractive();
    double Income();
    void add(int,int);
    void Insert(int,int,int);
    void Delete(int i);
    void putname(string o);
    string getname();
};
void Hotel::putname(string x){
    name = x;
}
string Hotel::getname(){
    return name;
}
void Hotel::Delete(int i){
    for(int j = i;j<count-1; j++) room[j] = room[j+1];
    count--;
}

void Hotel::add(int a,int b){
    room[count].Init(a,b);
    count++;
}
void Hotel::Insert(int a,int b, int c){
    if(count>a){
    for(int i = count;i>a;i--){
        room[i]= room[i-1];
    }
    room[a].Init(b,c);
    count++;}
    else add(b,c);
}

Room Hotel::Attractive(){
    //Метод определяющий самый привлекательный номер
    Room rooms = room[0];
    for(int i = 1; i<count;i++){
        if(room[i].Attractive()>rooms.Attractive())
            rooms = room[i];
    }
    return rooms;
}
void Hotel::Init(){
    //Метод иницилизации
    cout << "Please enter Time and Name of hotel: ";
    cin >> time >> name;
    room = new Room[N];
    count = 0;
}
void Hotel::Display(){
    //Метод вывода на экран
    cout << "Hotel: " << name << " Time: " << time << " day(s)" <<endl;
    if(count)
    for(int i = 0; i<count;i++)  room[i].Display();
}
double Hotel::Income(){
    //Метод вычисляющий прибыль
    int r = 0;
     for(int i = 0; i<count;i++) r+=room->GetPrice();
    return r*time;
}

int main(){
    Hotel Alpha;
    Alpha.Init();
    Alpha.add(1,1);
    Alpha.add(30,5);
    Alpha.add(44,14);
    Alpha.add(12,2);
    Alpha.Insert(2,34,55);
    Alpha.Display();
    Alpha.Delete(1);
    Alpha.Display();
    cout << "More attractive room: ";
    Alpha.Attractive().Display();
    cout << "Income hotel: " << Alpha.Income();
    cout<<"task8"<<endl;
    Hotel *a = new Hotel[5];
    for(int i = 0;i<5;i++) a[i].Init();
    for(int i = 0;i<5;i++){
        int b;
        string temp = a[i].getname();
        int len = temp.length();
        if(len<7){
            b = temp.rfind("cba");
            if(b!= -1){
                temp.replace(temp.begin()+2,temp.begin()+5,"1234");
                a[0].putname(temp);
                a[0].Display();
            }
        }
    }
    return 0;
}
