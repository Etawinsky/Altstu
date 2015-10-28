using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace task132
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
		 public double Priceafter(int monthsince){
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
		public bool lowerthan(int monthsince){
			double tmp = Priceafter (monthsince);
			if (tmp < monthsince)
				return true;
			else
				return false;		
		}
		public string Name
		{
			get{
				return name;
			}
			set{
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
		private double prim;
		private const double z = 0.01;

		public Procent(int _price, string _man, string _name, double _prim):base(_price, _man, _name)
		{
			prim = _prim;
		}
		public  double Priceafter(int monthsince){
			string s;
			try{
				if (monthsince > 12)
					throw e1 = new Exception("Аргумент > 12"); 
				if(monthsince < 0)
					throw e2 = new Exception("Аргумент < 0");

				for (int i = 0; i < monthsince; i++){
					price = price * (1 -coefficient );
					price += prim * (1 - z );
				}

			} catch (Exception e1){
				s = e1.Message;
				Console.WriteLine (s);
			}
			return price;

		}
		public bool lowerthan(int monthsince){
			double tmp = Priceafter (monthsince);
			if (tmp < monthsince)
				return true;
			else
				return false;		
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
		public static void Main (string[] args)
		{
			Paint a = new Paint (2, "one", "two");
			Procent b = new Procent (2, "four", "three", 3);

			bool f1, f2;
			f1 = b.lowerthan (9);

			a = b;




			f1 = a.lowerthan (9);
			f2 = a.lowerthan (9);




			Console.WriteLine (f1);
			Console.WriteLine (f2);



		}
	}
}