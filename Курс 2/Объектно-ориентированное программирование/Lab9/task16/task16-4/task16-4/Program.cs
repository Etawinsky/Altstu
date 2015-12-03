//20. Класс – марки. Известны страна, каталожный номер, год выпуска,
//цена. При "сложении" страна берется из первого аргумента, номер из
//второго. Годом выпуска является минимальный из двух годов, цена равна
//сумме цен.Выдать список каталожных номеров марок серии «Фауна» с 
//ценой, больше заданной.
using System;
using System.Collections;
namespace task_6
{
	class Stamp: IComparable,IComparer {
		public int num,year,cost;
		public string country;
		static protected double k = 0.1;
		public Stamp(){
			num = 1;
			year = 1999;
			cost = 1000;
		}
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
		public int Compare(Object x0, Object y0)  // сравнение 2 объектов
		{
			double t1, t2;
			Stamp a;
			a = (Stamp)x0;
			t1 = a.cost_of_n(2015);
			a = (Stamp)y0;
			t2 = a.cost_of_n(2015);
			if (t1 < t2)
				return -1;
			else
				return 1;
		}
		public double cost_of_n(int year){
			double a = cost;
			for(int j = 0; j<year;j++){
				a = a+a*k;
			}
			return a;
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
		public int CompareTo(Object x)
		{

			return Compare(this, x);

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
	
	}
	class man : IComparer{
		int IComparer.Compare(object a1, object b1)  // сравнение 2 объектов
		{
			int a = (int)a1;
			int b = (int)b1;
			if(((b%7==0)&&(b%3==0))&&(a%7!=0)&&(a%3!=0)) return 1;
			else if ((b%3==0)&&(a%3!=0)) return 1;
			else if ((b%7==0)&&(a%7!=0)) return 1;
			else return -1;
		}
	}
	class MainClass{

		public static void Main (string[] args){
			Col_Stamp c=new Col_Stamp(1, 1, 1, "23", 0.12);
			Stamp b=new Stamp(2, 2, 2, "asd");
			ArrayList a = new ArrayList ();
			a.Add (c);
			a.Add (b);
			a.Add(new Col_Stamp(3,4,45,"as",2121));
	      	a.Add(new Stamp(12,12323,123123,"dsf"));
			foreach (Stamp j in a) {
				j.Display ();
			}
			IComparer comp = new Stamp ();
			a.Sort (comp);
			foreach (Stamp j in a) {
				j.Display ();
			}
			ArrayList mmm = new ArrayList ();
			Random jj = new Random ();
			for(int i = 0;i<10;i++) mmm.Add(jj.Next(100));
			foreach (int h in mmm)
				Console.WriteLine (h);
			comp = new man ();
			Console.WriteLine (" ");
			mmm.Sort (comp);
			foreach (int h in mmm)
				Console.WriteLine (h);
		}
	}
}
