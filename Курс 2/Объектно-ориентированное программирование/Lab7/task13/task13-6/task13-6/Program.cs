/* и выполнить вычисления от элементов массива по варианту задания.
        *
                * Класс – краска. Известны название, цвет, производитель, цена за единицу.
                * При "сложении" название берется из первого аргумента, цвет и производитель из второго.
                * Цена за единицу складывается. Выдать перечень наименований краски данного цвета,
                * цена за единицу которой превышает заданную.
                *
                *
                * Основной класс - хозяйственный магазин. Дополнительное поле - суммарная стоимость всех других товаров.
                * Дополнительные методы: суммарная стоимость всех товаров  и самая дорогая краска.
 
*/
 
using System;
 
namespace task136
{
 
        class Paint: ICloneable
        {
                public string name;
                public string manufacturer;
                public int price;
 
 
                public Paint(string _n, string _m, int p){
                        name = _n;
                        manufacturer = _m;
                        price = p;
 
                }
                public object Clone()  // перегрузка метода клонирования
                {
                        return new Paint(name, manufacturer, price);
                }
                public string Name
                {
                        get
                        {
 
                                return name;
                        }
                        set
                        {
                                if(value.Length > 1)
                                        name = value;
                        }
                }
 
                public string Manufacturer
                {
                        get
                        {
                                return manufacturer;
                        }
                        set
                        {
                                if(value.Length > 1)
                                        manufacturer = value;
                        }
                }
                //public int Price;
 
                public void Display()
                {
                        Console.WriteLine ("Название {0}", name);
                        Console.WriteLine ("Производитель {0}", manufacturer);
                        Console.WriteLine ("Цена {0}", price);
                }
                public void Init(int _price)
                {
                        price = _price;
                }
                public int GetPrice()
                {
                        return price;
                }
       
        }
 
        class Store: ICloneable{
 
                public Paint p1;
                public Paint p2;
                public Paint p3;
 
                private int allsum;
                public Store(){
                }
 
                public Store(Paint a,Paint b, Paint c){
                        p1 = a;
                        p2 = b;
                        p3 = c;
                }
		

                public object Clone() // перегрузка клонирования
                {
                        return new Store(p1,p2,p3);
                }

                public int Allsum
                {
                        get
                        {
                                return Allsum;
                        }
                        set
                        {
                                allsum = value;
                        }
                }
                public int AllSum(){
                        allsum = p1.GetPrice() + p2.GetPrice()+ p3.GetPrice();
                        return allsum;
                }
 
                public int MostExpensive(){
                        Paint temp;
                        if (p1.GetPrice () > p2.GetPrice ())
                                temp = p1;
                        else
                                temp = p2;
                        if (p3.GetPrice () > temp.GetPrice())
                                temp = p3;
                        return p3.GetPrice();
                }
        }
 
        class MainClass
        {
                public static void Main (string[] args)
                {
                        Paint p1 = new Paint ("wrw", "werwer", 3);
                        Paint p2 = new Paint ("wrw", "werwer", 3);
                        Paint p3 = new Paint ("wrw", "werwer", 3);
                        Store a = new Store(p1,p2,p3);
                        Store b = new Store();
                        a = (Store)b.Clone();
						a = b;
       
 
 
}
}
 
}