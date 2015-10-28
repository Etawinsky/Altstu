/* Поле first – координата x, second – y точки на плоскости, вещественные числа. 
    Определить метод, вычисляющий угол в радианах отрезка (0,0 x,y) с осью OX.
    В основном классе добавлено целое поле K=1,2,3,4; дополнительный метод вычисляет суммарный угол от двух углов (от 0 до 360),
    находит квадрант Z, где он находится и дает в качестве результата 1, если Z=K и нуль в противном случае. */




import java.util.Scanner;
import java.lang.Math;

class task11_2 {
    public static void main(String[] args) {
		Test1 one = new Test1(1,2,3);
		Test2 two= new Test2(2,3,4);
		Test3 three = new Test3(1,2,4);
      

   }
}

class dot{
    protected double first;
    protected double second;
    
	public dot(double _first,double _second)
	{
		first = _first;
		second = _second;
	}
    public void Display()
    {
        System.out.println(first + " " + second);
    
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
    
}

class arbeit extends dot{
    protected dot one = new dot(1.0,2.0);
    protected int k;

    public arbeit(double x1, double y1 ){
        super(x1,y1);
	}
    public void Init (double x1, double y1)
    {
        one.Init(x1,y1);
    }
    public void Display()
    {
        one.Display();
        System.out.println(k);
    }
    
    public void setk(int _k)
    {
        k = _k;
    }

    public int sum_Of_Angles()
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
            return 1;
        else 
            return 0;
    }
} 

abstract class subarbeit extends arbeit
{
	protected double z;
	private arbeit test;
	private dot test2;	
	public abstract double S();
	public subarbeit(double _z, double _x, double _y)
	{
		super(_x, _y);
		z = _z;
	}
    	public int sum_Of_Angles()
	{
		return test.sum_Of_Angles() + (int)test2.degrees_radians();	
    }

}

class Test1 extends subarbeit
{
	public Test1(double _z, double _x, double _y)
	{
		super(_x, _y, _z);
	}

	private dot dot1;	
	private dot dot2;	
	public double S(){
		return 0.0;
	};

}
class Test2 extends subarbeit
{
	public Test2(double _z, double _x, double _y)
	{
		super(_x, _y, _z);
	}

	private arbeit arbeit1;	
	private arbeit arbeit2;	
	public double S(){
	
		return 0.0;
	};

}
class Test3 extends subarbeit
{
	public Test3(double _z, double _x, double _y)
	{
		super(_x, _y, _z);
	}

	private dot dot1;	
	private arbeit arbeit2;	
	public double S(){
	
		return 0.0;
	};

}
