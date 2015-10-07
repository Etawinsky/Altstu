using System;

namespace tas6_2
{
	struct Stamp{
		private int num,year,cost;
		private string country;
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
			Stamp ret = new Stamp ();
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
		public void Display(){
			Console.WriteLine ("ID" + num);
			Console.WriteLine ("Страна: " + country);
			Console.WriteLine ("Год: " + year);
			Console.WriteLine("Цена: "+cost);
		}

	}
	class Album{
		const int N = 10;
		private String name;
		private Stamp[] a = new Stamp[N];
		private int year,count = 0;
		public void Add(int x, int b,int c, string d){
			a[count].Init(x,b,c,d);
			count++;
		}
		public void Insert(int f,int x,int b, int c, string d){
			if(f<count){for(int i = count;i>f;i--) a[i] = a[i-1];
			a[f].Init(x,b,c,d);
				count++;}
			else Add(x,b,c,d);
		}
		public void Delete(int f){
			for (int i = f; i < count-1; i++)
				a [i] = a [i + 1]; 
			count--;
		}
		public void Init(Stamp a,Stamp b, Stamp c, int year){
		}
		public void Read(){
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
			for (int i = 0; i < count; i++)
				a [i].Display ();
			Console.WriteLine("Год издания альбома: " + year);
		}
		public void costs(out int ret){
			ret = 0;
			for (int i = 0; i < count; i++)
				ret += a [i].Cost;
		}
		/*public void costs(ref int ret){
			ret = 0;
			for (int i = 0; i < count; i++)
				ret += a [i].Cost;
		}*/
		public String Name{
			get{
				return name;
			}
			set{
				name = value;
			}
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
	class MainClass
	{
		public static void Main (string[] args)
		{
			Album D = new Album();
			D.Read();
			D.Add (1, 1, 1, "a");
			D.Add (2, 2, 2, "b");
			D.Add (3, 3, 3, "c");
			D.Insert (1, 5, 5, 5, "g");
			D.Display();
			D.Delete (2);
			D.Display ();
			int a = 0;
			D.costs(out a);
			// D.costs(ref a);
			Console.WriteLine(a);
			Album test = new Album ();
			test.Name = "SSS - gggg";
			String s;
			int k;
			k = test.Name.IndexOf ("-");
			if (test.Name [k - 1].CompareTo(' ') == test.Name [k + 1].CompareTo(' ')) {
				s = test.Name.Replace (" - ", "-");
			} else
				s = test.Name.Replace ("-", " - ");
			Console.WriteLine (s);
		}
	}
}
