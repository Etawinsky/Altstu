/* Реализовать на c# в среде Visual Studio класс по варианту задания. 
 * Для полей добавить свойства [(см. 3) лек. 3]. Использовать методы Read,
 * Display для ввода и вывода значений всех полей. 
 * Для задания/получения значений одного из полей использовать свойства,
 * остальные через Init. Добавить метод add с двумя аргументами объектов класса, 
 * который в качестве результата дает объект того же класса, являющийся "смесью" 
 * аргументов по варианту задания[см.  6) лек. 3]. В main создать массив объектов 
 * и выполнить вычисления от элементов массива по варианту задания.
 * 
 * Класс – краска. Известны название, цвет, производитель, цена за единицу.
 * При "сложении" название берется из первого аргумента, цвет и производитель из второго.
 * Цена за единицу складывается. Выдать перечень наименований краски данного цвета,
 * цена за единицу которой превышает заданную.
 * 
 * 
 * По варианту задания для класса из jtask6 на языке C# добавить 
 * вычисляемый метод с аргументом, сделав его статическим. [см.1) лек. 5].
 * 
 * Цена падает каждый месяц на k1 процент. (константа). 
 * Метод вычисляет цену  краски через n месяцев после выпуска (аргумент).
 * Исключения – месяцев больше 12 и месяцев меньше нуля
 * 
*/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace task123
{
	class Paint
	{
		static  protected Exception e1; 
		static  protected Exception e2; 

		protected string name;
		protected string manufacturer;
		protected double price;
		protected const double coefficient = 0.2;

		public Paint(int _price, string _man, string _name)
		{
			price = _price;
			manufacturer = _man;
			name = _name;
		}
	    public double Priceafter(Paint x, int monthsince){
		string s;
			try{
			if (monthsince > 12)
				throw e1 = new Exception("Аргумент > 12"); 
			if(monthsince < 0)
				throw e2 = new Exception("Аргумент < 0");
			
				for (int i = 0; i < monthsince; i++)
					x.price = x.price * (1 - coefficient ); 
			
			} catch (Exception e1){
				s = e1.Message;
				Console.WriteLine (s);
			}
			return x.price;

		}
		public string Name
		{
			get
			{
				return name;
			}
			set
			{
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

		public double GetPrice()
		{
			return price;
		}
		public Paint Add(Paint a, Paint b)
		{
			Paint c;
			c = new Paint(1,"one", "two");
			c.name = a.name;
			c.manufacturer = b.manufacturer;
			c.price = b.price;
			return c;
		}
		public override string ToString() // перегрузка встроенного метода перевода полей в строку
		{
			string s = "";
			s += Convert.ToString(price) + "  " + name + manufacturer;
			return s;
		}
	}
	class Procent:Paint{

		public Procent(int _price, string _man, string _name, double _prim):base(_price, _man, _name)
		{
			prim = _prim;
		}

		private double prim;
		private const double z = 0.01;

		public double Priceafter( int monthsince){
			string s;
			try{
				if (monthsince > 12)
					throw e1 = new Exception("Аргумент > 12"); 
				if(monthsince < 0)
					throw e2 = new Exception("Аргумент < 0");

				for (int i = 0; i < monthsince; i++){
					price = price * (1 - coefficient );
					prim = prim * (1 - z );
				}

			} catch (Exception e1){
				s = e1.Message;
				Console.WriteLine (s);
			}
			return price;

		}
/*

		public double Priceafter(Paint x, int monthsince){
			double price;
			price = base.Priceafter(x, monthsince);
			prim = prim * (1 - z );
			return price;

		}
*/

		public override string ToString() // перегрузка встроенного метода перевода полей в строку
		{
			string s = "";
			s += Convert.ToString(price)+ " " + Convert.ToString(prim)  + "  " + name + manufacturer;
			return s;
		}
	}
	class BigOne: Procent
	{
		private Paint paint1;
		private Procent procent1;
		public BigOne(int _price, string _man, string _name, double _prim):base(_price, _man, _name, _prim)
		{

		}
		public double Priceafter(){
			return paint1.Priceafter (paint1, 3) + procent1.Priceafter (paint1, 2); 
		}


			
	}
	class MainClass
	{
		public static void Main (string[] args)
		{
			Procent[] a = new Procent[4];

			int i;
			for (i = 0; i < 4; i++)
				a [i] = new Procent (i,"Y","z",i+2);

			a[0].Init (24);
			a[1].Init (45);
			a[0].Name = "Красная";
			a[0].Manufacturer = "РЗК";

			a[1].Name = "Синяя";
			a[1].Manufacturer = "КЗК";

			a[0].Display ();
			Console.WriteLine ();

			string tmp = a[0].Manufacturer;
			a[2].Init (44);
			a[2].Manufacturer = tmp;
			a[2].Name = "Белая";
			a[2].Display ();
			Console.WriteLine ();



			string s = "";
			int number;
			Console.Write ("Введите цену:");
			s = Console.ReadLine ();
			number = Convert.ToInt32 (s);
			Console.WriteLine (a [0]);
			double test; 
			try{
				test = a[2].Priceafter (a [2], 14);
				Console.WriteLine (test);


			}catch(Exception e2){
				s = e2.Message;
				Console.WriteLine (s);
			}



		}
	}
}