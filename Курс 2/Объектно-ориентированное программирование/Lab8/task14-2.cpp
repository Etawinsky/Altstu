#include <iostream>
#include <cmath>
using namespace std;
template <class T> class Array 
{
public:
	Array(int s);
	void Read();
	T Display();
	T Sum();
	T Max();
private:
	T *data;
	int size;
};

class Parabola{
    public:
        Parabola(double _a, double _b, double _c);
        Parabola(); 
        double Distance();
        Parabola Add(Parabola jeden, Parabola dwa);
		Parabola operator + (Parabola b);
		friend void operator >> (istream &o, Parabola &r);
		friend void operator << (ostream &o, Parabola r);
		friend bool operator >(Parabola a, Parabola b);
		friend bool operator <(Parabola a, Parabola b);
		void operator = (const Parabola &x);
    protected:
        double a;
        double b;
        double c; 
};
class Parabaloid: public Parabola{
	private: 
		double z;
	public:
		Parabaloid();
        Parabaloid(double _a, double _b, double _c, double _z);
		double Distance();
		Parabaloid operator + (Parabaloid b);
		friend void operator >> (istream &o, Parabaloid &r);
		friend void operator << (ostream &o, Parabaloid r);
		friend bool operator >(Parabaloid a, Parabaloid b);
		friend bool operator <(Parabaloid a, Parabaloid b);
		void operator = (const Parabaloid &x);

};

Parabaloid::Parabaloid(){}
Parabaloid::Parabaloid(double _a, double _b, double _c, double _z):Parabola(_a,_b,_c)
{
	z= _z;
}
double Parabaloid::Distance()
{	
	double x;
    double y;
    x = -b/(2*a);
    y = (b*b - 4*a*c)/(4*a);
    return sqrt(x*x + y*y) + z;
}

Parabaloid Parabaloid::operator + (Parabaloid b)
{
	Parabaloid tmp;
	tmp.a = this->a + b.a;
	tmp.b = this->b + b.b;
	tmp.c = this->c + b.c;
	tmp.z = this->z + b.z;
	return tmp;
}
void operator >> (istream &o, Parabaloid &r)
{
	cin >> r.a >> r.b >> r.c >> r.z;
}

void operator << (ostream &o, Parabaloid r)
{
	cout<< r.a << " " << r.b << " " << r.c << " " << r.z << endl; ;
}

bool operator >(Parabaloid a, Parabaloid b)
{
	if(a.a + a.b + a.c + a.z > b.a + b.b + b.c + a.z)
		return true;
	else 
		return false;
}
bool operator <(Parabaloid a, Parabaloid b)
{
	if(a.a + a.b + a.c + a.z < b.a + b.b + b.c + a.z)
		return true;
	else 
		return false;
}

void Parabaloid::operator = (const Parabaloid &x)
{
	this->a = x.a;
	this->b = x.b;
	this->c = x.c;
	this->z = x.z;
}


template <class T> Array<T>::Array(int s)
{
	data = new T[s];
	size = s;
}

template <class T> void Array<T>::Read()
{
	for(int i = 0; i < size; i++)
		cin >> data[i];
}

template <class T> T Array<T>::Display()
{
	for(int i = 0; i < size; i++){
		cout << data[i];
		cout << " ";
	}
	cout << endl;
}

template <class T> T Array<T>::Sum()
{
	T tmp;
	tmp = data[0];
	for(int i = 1; i < size; i++)
		tmp = tmp +  data[i];
	return tmp;
}
template <class T> T Array<T>::Max()
{
	T tmp;
	tmp = data[0];
	for(int i = 1; i < size; i++)
		if(data[i] > tmp)
			tmp = data[i];
	return tmp;
}
Parabola::Parabola(){}
Parabola::Parabola(double _a, double _b, double _c)
{
    a = _a;
    b = _b;
    c = _c;
}

Parabola Parabola::operator + (Parabola b)
{
	Parabola tmp;
	tmp.a = this->a + b.a;
	tmp.b = this->b + b.b;
	tmp.c = this->c + b.c;
	return tmp;
}
void operator >> (istream &o, Parabola &r)
{
	cin >> r.a >> r.b >> r.c;
}

void operator << (ostream &o, Parabola r)
{
	cout<< r.a << " " << r.b << " " << r.c << endl; ;
}

bool operator >(Parabola a, Parabola b)
{
	if(a.a + a.b + a.c > b.a + b.b + b.c)
		return true;
	else 
		return false;
}
bool operator <(Parabola a, Parabola b)
{
	if(a.a + a.b + a.c < b.a + b.b + b.c)
		return true;
	else 
		return false;
}

void Parabola::operator = (const Parabola &x)
{
	this->a = x.a;
	this->b = x.b;
	this->c = x.c;
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
	Array<int> D(2);
	Array<Parabola> P(4);
	Array<Parabaloid> Par(4);
	double sum;
	Parabaloid parab;
	Parabola max;
	D.Read();
	sum = D.Sum();
	cout << "Сумма: "<< sum << endl;
	sum = D.Max();
	cout << "Максимальное: "<< sum << endl;
	cout << "Вывод массива: " ;
	D.Display();
	
	P.Read();	
	max = P.Sum();
	cout << "Сумма: ";
	cout << max;
	max = P.Max();
	cout << "Максимальное: ";
	cout << max;
	cout << "Вывод массива: " << endl;
	P.Display(); 

	Par.Read();	
	parab = Par.Sum();
	cout << "Сумма: ";
	cout << parab;
	parab = Par.Max();
	cout << "Максимальное: ";
	cout << parab;
	cout << "Вывод массива: " << endl;
	Par.Display(); 

}
