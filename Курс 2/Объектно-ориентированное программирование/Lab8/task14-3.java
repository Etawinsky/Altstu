/* Поле first – координата x, second – y точки на плоскости, вещественные числа. 
    Определить метод, вычисляющий угол в радианах отрезка (0,0 x,y) с осью OX.
    В основном классе добавлено целое поле K=1,2,3,4; дополнительный метод вычисляет суммарный угол от двух углов (от 0 до 360),
    находит квадрант Z, где он находится и дает в качестве результата 1, если Z=K и нуль в противном случае. */




import java.util.Scanner;
import java.lang.Math;

class task14_3 {
	public static <T extends arbeit> double sum(T one){
		return one.sum_Of_Angles();
	}		

    public static void main(String[] args) {
			arbeit one = new arbeit(1.0,2.0,1);
			subarbeit two = new subarbeit(1.0,5.0,3.0,1);
			double a, b;
			a = sum(one);
			b = sum(two);
			System.out.println("a" + a + " b " + b);
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
    protected dot two = new dot(1.0,2.0);
    protected int k;

    public arbeit(double x1, double y1 , int _k){
        super(x1,y1);
		k = _k;
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
            return 1;
        else 
            return 0;
    }
} 

class subarbeit extends arbeit
{
	private double z;
	public subarbeit(double _z, double _x, double _y, int _k)
	{
		super(_x, _y, _k);
		z = _z;
	}
    public double sum_Of_Angles()
	{
		return super.sum_Of_Angles() + z ; 
    }

}
