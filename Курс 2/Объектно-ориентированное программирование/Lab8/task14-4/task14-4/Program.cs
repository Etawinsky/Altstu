using System;

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace task144
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
		public double Priceafter( int monthsince){
			string s;
			try{
				if (monthsince > 12)
					throw e1 = new Exception("Аргумент > 12"); 
				if(monthsince < 0)
					throw e2 = new Exception("Аргумент < 0");

				for (int i = 0; i < monthsince; i++)
					price = price * (1 - coefficient ); 

			} catch (Exception e1){
				s = e1.Message;
				Console.WriteLine (s);
			}
			return price;

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
	class MainClass
	{
		static int Price<T>(T a, int monthsince) where T:Paint
		{
			string s;
			try{
				if (monthsince > 12)
					throw a.e1 = new Exception("Аргумент > 12"); 
				if(monthsince < 0)
					throw a.e2 = new Exception("Аргумент < 0");

				for (int i = 0; i < monthsince; i++)
					a.price = a.price * (1 - a.coefficient ); 

			} catch (Exception e1){
				s = e1.Message;
				Console.WriteLine (s);
			}
			return a.price;
		}
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