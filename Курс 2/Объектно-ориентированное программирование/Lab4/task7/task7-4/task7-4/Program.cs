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
		* 
		* 
		*  Метод, в task6 ч.3 для основного класса языка C#, возвращающий целое или вещественное значение ,
		* дополнить методом, возвращающий значение через параметр out. 
		* [см.5) лек. 4]. В main продемонстрировать все оба метода, через ref и out, закомментировав один из методов.

*/

using System;

namespace task74
{
	class Store{

		public Paint p1 = new Paint();
		public Paint p2 = new Paint();
		public Paint p3 = new Paint();

		private int allsum;

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

		/*
		public void MostExpensive(out int mstexpensive ){
			Paint temp = new Paint();
			if (p1.GetPrice () > p2.GetPrice ())
				temp = p1;
			else 
				temp = p2;
			if (p3.GetPrice () > temp.GetPrice())
				temp = p3;
			mstexpensive = p3.GetPrice();
		}
		*/
		public void MostExpensive(ref int mstexpensive ){
			Paint temp = new Paint();
			if (p1.GetPrice () > p2.GetPrice ())
				temp = p1;
			else 
				temp = p2;
			if (p3.GetPrice () > temp.GetPrice())
				temp = p3;
	
		}

	}

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

	class MainClass
	{
		public static void Main (string[] args)
		{
			int mstexpensive = 0;
			Store fs = new Store ();


			fs.p1.Init (24);
			fs.p1.Name = "Красная";
			fs.p2.Init (45);
			fs.p2.Name = "Серая";
			fs.p3.Init (45);
			fs.p3.Name = "Коричневая";

			fs.Allsum = 150;
			//fs.MostExpensive (out mstexpensive);


			fs.MostExpensive (ref mstexpensive);
			Console.WriteLine ("Самый дорогой продукт: {0}", mstexpensive);

	


}
}

}