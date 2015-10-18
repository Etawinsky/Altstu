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
*/

using System;

namespace task96
{
	class Paint
	{
		private string name;
		private string manufacturer;
		private int price;

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
		public Paint(int _price)
		{
			price = _price;
		}

		public Paint()
		{
			price = 0;
		}

		public int GetPrice()
		{
			return price;
		}
		public Paint Add(Paint a, Paint b)
		{
			Paint c;
			c = new Paint();
			c.name = a.name;
			c.manufacturer = b.manufacturer;
			c.price = b.price;
			return c;
		}
	}
	class MainClass
	{
		public static void Main (string[] args)
		{
			Paint[] a = new Paint[4];

			int i;
			for (i = 0; i < 4; i++)
				a [i] = new Paint ();
		
			Paint a[1] = new Paint(2);
			Paint a[2] = new Paint();
			Paint a[3] = new Paint();
			Paint a[4] = new Paint();
			Paint[]d =new Paint[5];

			for (int i = 0; i < 5; i++)
			{
				d[i] = new Paint (i); // конструктор с одним параметром
			}



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

			a[3] = a[0].Add (a[0], a[0]);
			a[3].Display ();

			string s = "";
			int number;
			Console.Write ("Введите цену:");
			s = Console.ReadLine ();
			number = Convert.ToInt32 (s);

			Console.WriteLine ("Результат:");
			for (i = 0; i < 4; i++)
				if (a [i].GetPrice () > number) {
					a [i].Display ();
					Console.WriteLine ();
				}

		}
	}
}