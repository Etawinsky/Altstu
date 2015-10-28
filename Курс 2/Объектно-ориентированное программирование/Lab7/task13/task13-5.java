/* Поле first – координата x, second – y точки на плоскости, вещественные числа. 
    Определить метод, вычисляющий угол в радианах отрезка (0,0 x,y) с осью OX.
    В основном классе добавлено целое поле K=1,2,3,4; дополнительный метод вычисляет суммарный угол от двух углов (от 0 до 360),
    находит квадрант Z, где он находится и дает в качестве результата 1, если Z=K и нуль в противном случае. */




import java.util.Scanner;
import java.lang.Math;

class task13_5 {
	public static void main(String[] args) {

	arbeit a=new arbeit(2,5,3,10);
	arbeit b=new arbeit(1,1,4,23);
	b.Display();
	a=(arbeit)b.clone();
    a=(arbeit)b.clone();
	a.Display(); 
}

}

class dot{
    private double first;
    private double second;

	public Object clone(){
		try{
			return (dot)super.clone();
		}catch(CloneNotSupportedException e){}
		return this;
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

class arbeit{
    public dot one = new dot();
    public dot two = new dot();
    private int k;

    arbeit (double x1, double y1, double x2, double y2)
    {
        one.Init(x1,y1);
        two.Init(x2,y2);
    }
    public void Display()
    {
        one.Display();
        two.Display();
        System.out.println(k);
    }
    
    public void setk(int _k)
    {
        k = _k;
    }
/*
	public Object clone()
	{
		try{
				arbeit clone=(arbeit)super.clone();
				return clone;
     		}catch(CloneNotSupportedException e){}
     	return this;
	} 
*/
 	public Object clone()
	{
		try{
			arbeit clone=(arbeit)super.clone();
			clone.one=(dot)one.clone();	
			clone.two=(dot)two.clone();	
			return clone;
		}
	catch(CloneNotSupportedException e){}
  return this;  
}
    public int sum_Of_Angles()
    {
        double angle = one.degrees_radians() + two.degrees_radians();
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
