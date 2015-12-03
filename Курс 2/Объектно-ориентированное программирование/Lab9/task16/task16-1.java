/* Поле first – координата x, second – y точки на плоскости, вещественные числа. 
    Определить метод, вычисляющий угол в радианах отрезка (0,0 x,y) с осью OX.
    В основном классе добавлено целое поле K=1,2,3,4; дополнительный метод вычисляет суммарный угол от двух углов (от 0 до 360),
    находит квадрант Z, где он находится и дает в качестве результата 1, если Z=K и нуль в противном случае. */




import java.util.Scanner;
import java.lang.Math;
import java.util.*;
class task11_2 {
    public static void main(String[] args) {
        int result, i;
        double[] back = new double[5];
        double tmp = -1;
		dot one = new dot(1.0,2.0);
		dot two = new dot(6.0,4.0);
		arbeit three = new arbeit(6.0,7.0,6);
		arbeit four = new arbeit(3.0,8.0,3);
        subarbeit point = new subarbeit(1.0,2.5,3.3,3);
		ArrayList a=new ArrayList();
		a.add(one);
		a.add(two);
		a.add(three);
		a.add(four);
		a.add(point);
	 	Iterator<dot> ir=a.iterator();
		ArrayList<dot> b=new ArrayList<dot>() ;
		while(ir.hasNext()){
			dot el= ir.next();
			if(el instanceof arbeit){
				if(b.isEmpty() || b.get(0).sum_Of_Angles() > el.sum_Of_Angles()){
					b.clear();
					b.add(el);
				}else if(!b.isEmpty() && b.get(0).sum_Of_Angles() == el.sum_Of_Angles()){
					b.add(el);
				}
			}
			el.Display();
			System.out.println("");
		}
		System.out.println("________");
		for(dot el:b){
			el.Display();
			System.out.println("");
	   }
	}
}

class dot{
    protected  double first;
    protected  double second;
    
	public dot(double _first,double _second)
	{
		first = _first;
		second = _second;
	}
    public void Display()
    {
        System.out.print(first + " " + second + " ");
    
    }

    public void Init(double _first, double _second)
    {
        first = _first;
        second = _second;
    }

    public double get_First()
    {
        return first;
    }

    public double get_Second()
    {
        return second;
    }
    
    public double degrees_radians()
    {
       return Math.atan(second/first); 
    }
    public double sum_Of_Angles(){
		return 0.0;
	}
    
}

class arbeit extends dot{
    protected int k;
	protected dot one; 
    public arbeit(double x1, double y1 , int _k){
        super(x1,y1);
    	 one = new dot(x1,y1);
		k = _k;
	}
    public void Init (double x1, double y1)
    {
        one.Init(x1,y1);
    }
    public void Display()
    {
        one.Display();
        System.out.print(k);
    }
    
    public void setk(int _k)
    {
        k = _k;
    }

    public double sum_Of_Angles()
    {
        double angle = one.degrees_radians() + one.degrees_radians();
        while(angle >= 2 * Math.PI)
            angle -= 2 * Math.PI;
        double borders[]= {0, Math.PI/2, Math.PI, 3*Math.PI/4, 0};
        int i;
        for(i = 1; i < 5; i++)
            if(angle>=borders[i-1] && angle <= borders[i])
                break;
        if(k == i)
            return 1.0;
        else 
            return 0.0;
    }
} 

class subarbeit extends arbeit
{
	private double z;
	private arbeit abeit;
	public subarbeit(double _z, double _x, double _y, int k)
	{
		super(_x, _y, k);
		abeit = new arbeit(_z, _x, k);
		z = _z;
	}

    public void Display()
    {
        abeit.Display();
        System.out.print(" " + k);
    }
    public double sum_Of_Angles()
    {
    	return z + abeit.sum_Of_Angles();
    }



}

