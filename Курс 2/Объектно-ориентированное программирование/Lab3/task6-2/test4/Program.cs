/* и выполнить вычисления от элементов массива по варианту задания.
	*
		* Класс – краска. Известны название, цвет, производитель, цена за единицу.
		* При "сложении" название берется из первого аргумента, цвет и производитель из второго.
		* Цена за единицу складывается. Выдать перечень наименований краски данного цвета,
		* цена за единицу которой превышает заданную.
		* 
		* 
		* В новом проекте создать структуру (struct) [см. 10) лек. 3] с полями и методами класса из ч.1 . 
		* Продемонстрировать различие между присваиванием объектов в классе и структуре.
*/

using System;

namespace test4
{

	class Paint1
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
		public void Init(int _price)
		{
			price = _price;
		}
		public int GetPrice()
		{
			return price;
		}
	}
	struct Paint
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
		public void Init(int _price)
		{
			price = _price;
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

			a[0].Init (24);
			a[1].Init (45);
			a[0].Name = "Красная";
			a[0].Manufacturer = "РЗК";

			a[1].Name = "Синяя";
			a[1].Manufacturer = "КЗК";

			string tmp = a[0].Manufacturer;
			a[2].Init (44);
			a[2].Manufacturer = tmp;
			a[2].Name = "Белая";
		

			a[3] = a[0].Add (a[0], a[0]);

			a [0].Display ();
			Console.WriteLine ("Это была первая структура");
			a [1].Display ();
			Console.WriteLine ("Вторая структура");
			a [0] = a [1];
			a [0].Display ();
			Console.WriteLine ("Cкопированная");

			Paint1 b = new Paint1 ();
			b.Init (77);
			b.Name = "Зеленая";
			b.Manufacturer = "РЗК";
			b.Display ("первый класс");
			Paint1 c = new Paint1 ();
			c.Init (37);
			c.Name = "Оранжевая";
			c.Manufacturer = "РЗК";
			c.Display ("второй класс");
			c = b;
			c.Display ("скопированный");





			/*структу*/



		}
	}
}