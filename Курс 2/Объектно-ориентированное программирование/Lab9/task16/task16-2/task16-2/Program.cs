using System;
using System.Collections;
using System.Linq;
using System.Text;

namespace task162
{
	class Paint: IComparable
	{

		public string name;
		public string manufacturer;
		public int price;

		public Paint(){}
		public Paint(string a, string b, int c)
		{
			name = a;
			manufacturer = b;
			price = c;

		}

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

		virtual public void Display()
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
		virtual public int AllSum(){
			return price;
		}

		public int CompareTo(object rhs){
			return 4;
		}

		public int Compare(object left, object right){
			Paint lef = (Paint)left;
			Paint righ = (Paint)right;
			if (lef.AllSum () < righ.AllSum ())
				return -1;
			else if (lef.AllSum () > righ.AllSum ())
				return 1;
			else
				return 0;
		}
	}
	class Store: Paint   {

		public Paint p1;
		public Paint p2;
		public Paint p3;

		public Store(string a1, string b1, int c1, string a2, string b2, int c2, string a3, string b3, int c3)
		{
			p1 = new Paint (a1, b1, c1);
			p2 = new Paint (a2, b2, c2);
			p3 = new Paint (a3, b3, c3);
		}
		private int allsum;


		override public int AllSum(){
			allsum = p1.GetPrice() + p2.GetPrice()+ p3.GetPrice();
			return allsum;
		}

		public int MostExpensive(){
			Paint temp = new Paint();
			if (p1.GetPrice () > p2.GetPrice ())
				temp = p1;
			else 
				temp = p2;
			if (p3.GetPrice () > temp.GetPrice())
				temp = p3;
			return p3.GetPrice();
		}

		override public void Display()
		{
			Console.WriteLine("_______");
			p1.Display ();
			p2.Display ();
			p3.Display ();
			Console.WriteLine("_______");
		}
	}



	class MainClass
	{
		private static int compare(Object left, Object right){
		
			if (left is Paint && right is Store)
				return -1;
			if (left is Store && right is Paint)
				return 1;
			return 0;

		}
		public static void Main (string[] args)
		{

			ArrayList one = new ArrayList();  

			int mstexpensive;
			Store fs = new Store ("pzae", "yqe", 4, "qeyqey", "qeyqey", 1, "qe645645", "hsfgd",5);
			Store fd = new Store ("pzawrtree", "yqrgurte", 4, "qeyqey", "qeyqey", 1, "qe645645", "hsfgd",5);
			Paint qw = new Paint ("werwer", "wer", 5);
			Paint qu = new Paint ("werwer", "wer", 6);
			Paint qr = new Paint ("werwer", "wer", 5);

			one.Add (fs);
			one.Add (fd);
			one.Add (qw);
			one.Add (qu);
			one.Add (qr);
			one.Sort ();


			foreach (Object fe in one) {
				Paint ty = fe as Paint;
				ty.Display ();	
			}

		}
	}

}