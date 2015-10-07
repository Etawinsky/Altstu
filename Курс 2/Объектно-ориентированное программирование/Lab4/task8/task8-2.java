/* Поле first – координата x, second – y точки на плоскости, вещественные числа. 
    Определить метод, вычисляющий угол в радианах отрезка (0,0 x,y) с осью OX.
    В основном классе добавлено целое поле K=1,2,3,4; дополнительный метод вычисляет суммарный угол от двух углов (от 0 до 360),
    находит квадрант Z, где он находится и дает в качестве результата 1, если Z=K и нуль в противном случае.


	Название состоит из слов, разделенных пробелами. 
	Первое встретившееся сочетание "ab" переставить в конец слова.
	Если сочетания нет оставить слово без изменения.
 */




import java.util.Scanner;
import java.lang.Math;

class task82 {
    public static void main(String[] args) {
        int result, i;
        double[] back = new double[5];
        double tmp = -1;;
        arbeit point = new arbeit();
        point.Init(2,6,1,3, "ab 1 2 3 grzegorz brzęczyszczykiewicz 34");
		String temp = point.Getname();
		String temp2 = temp;
		i = temp.indexOf("ab");
		System.out.println(temp + "----"+ i);
		if(i >= 0){
			temp2 = temp.substring(i+2, temp.length());
			temp2 = temp2 + "ab";
		}
		System.out.println(temp2);
	}
}

class dot{
    private double first;
    private double second;
    
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
    private dot one = new dot();
    private dot two = new dot();
    private int k;
	private String Name;
	public String Getname()
	{
		return Name;
	}
	public void Putname(String s){
		Name = s;
	}
    public void Init (double x1, double y1, double x2, double y2, String s)
    {
        one.Init(x1,y1);
        two.Init(x2,y2);
		Putname(s);
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
