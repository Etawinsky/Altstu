using System;

namespace task103
{
	class Paint
	{
		private string name;
		private string manufacturer;
		private int price;


		public static void matrix(int[,] array, int x, int n)
		{
			int tmp = x;
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++)
					array[i,j] = tmp;
				tmp = tmp * x;
			}

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
			const int x = 2;
			const int n = 6;
			int[,] array = new int[n,n];
			Paint.matrix(array, x,n);
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++)
					Console.Write(array[i,j] + "   ");
				Console.WriteLine();
			}

		}
	}
}