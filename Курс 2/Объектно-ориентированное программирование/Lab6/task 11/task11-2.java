/* Поле first – координата x, second – y точки на плоскости, вещественные числа. 
    Определить метод, вычисляющий угол в радианах отрезка (0,0 x,y) с осью OX.
    В основном классе добавлено целое поле K=1,2,3,4; дополнительный метод вычисляет суммарный угол от двух углов (от 0 до 360),
    находит квадрант Z, где он находится и дает в качестве результата 1, если Z=K и нуль в противном случае. */




import java.util.Scanner;
import java.lang.Math;

class task11_2 {
    public static void main(String[] args) {
        int result, i;
        double[] back = new double[5];
        double tmp = -1;;
        subarbeit point = new subarbeit(1,2,3);

		/*
        point.Init(2,6,1,3);
        point.setk(2);
        result = point.sum_Of_Angles();
        if(result == 1)
            System.out.println("Сумма углов находится в той же четверти, что и k");
        else
            System.out.println("Сумма углов не находится в той же четверти, что и k");
            
        dot[] many_dots = new dot[5];
        for(i = 0; i < 5; i++ ){
            many_dots[i] = new dot();
            many_dots[i].Init(1, (i+1)*2);
            back[i]=many_dots[i].degrees_radians();
            System.out.println(i+ "-ый элемент массива: " + back[i]);
            if(back[i] > tmp)
                tmp = back[i];
        }
            
            System.out.printf("Максимальный элемент массива: %f\n", tmp );
            System.out.printf("Отображение элементов массива объектов...\n");
            for(i = 0; i < 5; i++)
                many_dots[i].Display();
				*/
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

class subarbeit extends arbeit
{
	private double z;
	public subarbeit(double _z, double _x, double _y)
	{
		super(_x, _y);
		z = _z;
	}
    public double sum_Of_Angles()
	{
		return atan((x + z) / (y + z) )
    }

}

