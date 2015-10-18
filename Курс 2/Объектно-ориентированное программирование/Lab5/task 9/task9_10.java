/* В функции main task1 продемонстрировать использование одного динамического объекта, 
а также  динамического массива объектов. [см. 1) лекция 2]. 
Использовать new, delete, delete[] . При обращении к методам использовать (*a) и ->. 
Заменить поля объектов вспомогательного класса в основном классе на массив объектов с 
изменением методов основного класса. [(см. 1) лекция 2 Пример 1]
Написать программу на java по варианту. Выполнить программу как консольное приложение (compile.bat, run,bat) 
и в среде eclipse. Использовать ввод-вывод (printf, scaner), использовать при выводе русские буквы.
Программа должна вычислять значение выражения, в зависимости от введенных данных, после проверки соответствующих условий.
Проверку следует оптимизировать, чтобы количество условий , && , ||  было минимальным. */

import java.util.Scanner;
import java.lang.Math;

class task9_10{
    public static void main(String[] args) {
        double result;
        dot test = new dot(2,3);
		try{
			result = test.angle(1,1);

		}catch( Ex e){
			System.out.println("исключение: " + e);
		}
        System.out.print("Введите x:");
        test.setx();
        if(test.getx() < 15e-5)
            result = test.funca();
        else if( test.getx() >= 15e-5 && test.getx() <= 3.0)
            result = test.funcb();
        else 
            result = test.funcc();
        System.out.println("Результат: " + result);
            }
}
class Ex extends Exception
{
  	private int Type;    
	Ex(int a)           
	{
		Type = a;
	}
}
class dot{
    private double x;
	private double y;
    public double getx()
    {
        return x;
    }
    public void setx()
    {
        Scanner in = new Scanner(System.in);
        x = in.nextDouble();
    }
   	public static double angle(int x, int y) throws Ex{
		if(x == 0)
			throw new Ex(1); 
		if(y == 0)
			throw new Ex(2);
	   return (Math.atan(x/y));	
	}
    public dot(double _x, double _y)
    {
        x = _x;  
	   	y = _y;	
    }
    public double funca()
    {
        return Math.sin(x*x) + x;
    }

    public double funcb()
    {
        return Math.cos(Math.sqrt(x)) ;
    }

    public double funcc()
    {
        return Math.atan(x*x) ;
    }

    
}
