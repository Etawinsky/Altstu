/* Поле first – координата x, second – y точки на плоскости, вещественные числа. 
    Определить метод, вычисляющий угол в радианах отрезка (0,0 x,y) с осью OX.
    В основном классе добавлено целое поле K=1,2,3,4; дополнительный метод вычисляет суммарный угол от двух углов (от 0 до 360),
    находит квадрант Z, где он находится и дает в качестве результата 1, если Z=K и нуль в противном случае.

 	В task4 ч.2 языка Java к основному классу добавить методы Better с двумя и с одним аргументом (this), 
 	возвращающие "лучший" из вспомогательных объектов, по значению метода, указанного  варианте.
 	В main продемонстрировать обращение к обеим методам. [см.6) лек. 4].
 
 */




import java.util.Scanner;
import java.lang.Math;

class task752 {
    public static void main(String[] args) {
        int result, i;
        double[] back = new double[5];
        double tmp = -1;;
        arbeit point = new arbeit();
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

			arbeit pnt = new arbeit();
        	arbeit pnt1 = new arbeit();
        	pnt1.Init(2,6,1,3);

        	arbeit pnt2 = new arbeit();
        	pnt2.Init(1,4,4,6);

        	arbeit pnt3 = new arbeit();
        	pnt3.Init(3,2,1,6);

            System.out.printf("И еще один результат...\n");
			pnt = pnt1.Better(pnt2, pnt1);
			pnt.Display();
			pnt = pnt1.Better(pnt1);
			pnt.Display();

			
		
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

    public void Init (double x1, double y1, double x2, double y2)
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

	public arbeit Better(arbeit a, arbeit b){
		double s1, s2;
		s1 = a.sum_Of_Angles();
		s2 = b.sum_Of_Angles();
		if(s1 > s2)
			return a;
		else 
			return b;
	}
	public arbeit Better(arbeit b){
		double s1, s2;
		s1 = this.sum_Of_Angles();
		s2 = b.sum_Of_Angles();
		if(s1 > s2)
			return this;
		else 
			return b;
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
