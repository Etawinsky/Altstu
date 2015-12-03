import java.io.*;
import java.util.*;

class task163{
 
	
	public static void main(String args[]){
		 ArrayList one = new ArrayList();
		 one.add("one");
		 one.add("t,wo.");
		 one.add("a,wo.");
		 one.add("t,hree.");
		 one.add("four");
		 one.add("fivwrwtyre");
		 Collections.sort(one, new  MyComparator());
		 Iterator ir=one.iterator(); 
		 while(ir.hasNext()){
		 	Object el=ir.next();
			System.out.println(el);
		 }
	}

	public static class MyComparator implements Comparator<String>{
	
	@Override
	public int compare(String a, String b){
		boolean c1 = (a.contains(".")/*&& !a.contains(",")*/) ;
		boolean c2 = (b.contains(".")/*&& !b.contains(",")*/) ;
		if(c1 == true && c2 == false)
			return -1;
		else if(c1 == false && c2 == true)
			return 0;
		else if(c1 == true && c2 == true)
			if(a.length() < b.length())
				return -1;
			else
				return 1;
		else 
			if(a.length() < b.length())
				return 1;
			else
				return -1;


			
		//return Integer.compare(c2,c1);
	}
	
/*
		public int compareTo(String left){
		if(left.length() < this.length())
			return 1;
		return 0;
	}
*/
	}
	
}
