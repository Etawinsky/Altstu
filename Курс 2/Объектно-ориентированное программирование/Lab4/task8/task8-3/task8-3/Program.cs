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
 * Название состоит из нескольких строк, разделенных '\n'. 
 * Это четырехстрочная строфа (не более 80 символов).
 * Записать стих "лесенкой" (по одному слову в строке). 
 * добавляя  пустую строку после четверостишья.
*/

using System;

namespace task83
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
		public String Getname(){

			return name;
		}
		public void Putname(string s)
		{
			name = s;
		}

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
			Paint a = new Paint();
			string s = "Вы ушли, как говорится, в мир иной.\n Пустота..." +
				"Летите, в звезды врезываясь.\n Ни тебе аванса, ни пивной.\n Трезвость";
			a.Putname (s);
			string tmp = a.Getname();
			string[] answer;
			answer = tmp.Split (' ');
			foreach(string c in answer){
				Console.WriteLine (c);

			}

		}
	}
}
