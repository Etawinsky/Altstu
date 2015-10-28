using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace task133
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
	abstract class BigOne: Procent
	{
		private Paint paint1;
		private Procent procent1;
		public BigOne(int _price, string _man, string _name, double _prim):base(_price, _man, _name, _prim)
		{

		}
		public double Priceafter(){
			return paint1.Priceafter (paint1, 3) + procent1.Priceafter (paint1, 2); 
		}
		public abstract double S(); 
	}

	class Test1: BigOne{
		public Test1(int _price, string _man, string _name, double _prim):base(_price, _man, _name, _prim){}
		private Paint paint1;
		private Paint paint2;
		public override double S ()
		{
			return 4.0;
		}
	}
	
	class Test2: BigOne{
		public Test2(int _price, string _man, string _name, double _prim):base(_price, _man, _name, _prim){}
		private Procent procent1;
		private Procent procent2;
		public override double S ()
		{
			return 5.0;
		}
	}
	
	class Test3: BigOne{
		public Test3(int _price, string _man, string _name, double _prim):base(_price, _man, _name, _prim){
		}
		private Paint paint1;
		private Procent procent2;
		public override double S ()
		{
			return 4.0;
		}
	}


	class MainClass
	{
		public static void Main (string[] args)
		{
			Test1 one = new Test1(3, "4", "4",  5);
			Test2 three = new Test2(3, "4", "4",  5);
			Test3 four = new Test3(3, "4", "4",  5);




		}
	}
}