//20. Класс – марки. Известны страна, каталожный номер, год выпуска,
//цена. При "сложении" страна берется из первого аргумента, номер из
//второго. Годом выпуска является минимальный из двух годов, цена равна
//сумме цен.Выдать список каталожных номеров марок серии «Фауна» с 
//ценой, больше заданной.
using System;

namespace task144
{
	class Stamp{
		protected int num,year,cost;
		protected string country;
		static protected double k = 0.1;
		public double K{
			get {
				return k;
			}
			set{
				k = value;
			}
		}
		public int Num{
			get {
				return num;
			}
			set{
				num = value;
			}
		}
		public int Year{
			get {
				return year;
			}
			set{
				if (value > 1500 & value < 2015)
					year = value;
				else
					year = 0;
			}
		}
		public int Cost{
			get {
				return cost;
			}
			set{
				if (value > 0)
					cost = value;
				else
					cost = 1;
			}
		}
		public string Country{
			get {
				return country;
			}
			set{
				country = value;
			}
		}
		public void Init(int a, int b, int c, string d){
			num = a;
			Year = b;
			Cost = c;
			country = d;
		}
		public Stamp add(Stamp s1,Stamp s2){
			Stamp ret = new Stamp (1,1,1,"sad");
			int year1,id;
			if (s1.year > s2.year)
				year1 = s2.year;
			else
				year1 = s1.year;
			if (s1.num < s2.num)
				id = s2.num + 1;
			else
				id = s1.num + 1;
			ret.Init (id, year1, s1.cost + s2.cost, s1.country);
			return ret;
		}
		public void Read(){
			bool f = false;
			Console.WriteLine ("Введите ID, год, цену, страну:");
			string[] s = Console.ReadLine().Split(new char[] { ' ', '\t' },StringSplitOptions.RemoveEmptyEntries);
			while(!f){
				if(f){
					Console.WriteLine ("Введите ID повторно:");
					s [0] = Console.ReadLine ();
				}
				f = int.TryParse (s [0], out num);
			}
			f = false;
			while(!f){
				if(f){
					Console.WriteLine ("Введите год повторно:");
					s [1] = Console.ReadLine ();
				}
				f = int.TryParse (s [1], out year);
			}
			f = false;
			while(!f){
				if(f){
					Console.WriteLine ("Введите цену повторно:");
					s [2] = Console.ReadLine ();
				}
				f = int.TryParse (s [2], out cost);
			}
			country = s [3];
		}
		public override string ToString() 
		{
			string s = "";
			s += Convert.ToString(num) + "  " + Convert.ToString(year)+" " +
				Convert.ToString(cost) + " " + country;
			return s;
		}
		public void Display(){
			Console.WriteLine ("ID" + num);
			Console.WriteLine ("Страна: " + country);
			Console.WriteLine ("Год: " + year);
			Console.WriteLine("Цена: "+cost);
		}
		public Stamp(int n,int year,int cost,string count){
			num=n;
			Year=year;
			Cost=cost;
			country=count;
		}
	}
	class Col_Stamp:Stamp{
		static private double z;
		public Col_Stamp(int n,int year,int cost,string coun,double ou):base(n,year,cost,coun){
			z=ou;
		}
		public override string ToString() 
		{
			string s = "";
			s += Convert.ToString(num) + "  " + Convert.ToString(year)+" " +
				Convert.ToString(cost) + " " + country+ " " + Convert.ToString(z);
			return s;
		}
		public int Cost{
			get {
				return Convert.ToInt32(cost+(cost*z));
			}
			set{
				if (value > 0)
					cost = value;
				else
					cost = 1;
			}
		}

	}
	class Album{
		private Stamp a;
		private Col_Stamp b;
		private int year;
		static private double k;
		public int cost(){
			int max = a.Cost;
			if(max<b.Cost)
				max=b.Cost;
			return max;
		}
		public int L_years(){
			int max = a.Year;
			if (max < b.Year)
				max = b.Year;
			if (max < year)
				max = year;
			return max;
		}
		public void Init(Stamp a,Stamp b, Stamp c, int year){
		}
		public void Read(){
			a.Read();
			b.Read();
			Console.WriteLine("Введите год альбома:");
			bool f = false;
			string s  = Console.ReadLine();
			while(!f){
				if(f){
					Console.WriteLine ("Введите год повторно:");
					s = Console.ReadLine ();
				}
				f = int.TryParse (s, out year);
			}
		}
		public void Display(){
			Console.WriteLine ("Первая марка:");
			a.Display();
			Console.WriteLine ("Вторая марка:");
			b.Display();

			Console.WriteLine("Год издания альбома: " + year);
		}
		public int Year{
			get{
				return year;
			}
			set{
				if (value > 1500 & value < 2015)
					year = value;
				else
					year = 0;
			}
		}	

	}
	class MainClass{
		static double cost_of_n <T>(T i,int year) where T:Stamp{
			double a = i.Cost;
			for(int j = 0; j<year;j++){
				a = a+a*i.K;
			}
			return a;
		}
		public delegate double Coost(Stamp i, int year);
		public static void Main (string[] args)
		{
			Coost a = cost_of_n;
			Col_Stamp c=new Col_Stamp(1, 1, 1, "23", 0.12);
			Stamp b=new Stamp(2, 2, 2, "asd");
			double res = a (b, 10);
			Console.WriteLine(cost_of_n(c,10)+" "+cost_of_n(b,10)+" "+res);
		}
	}
}
