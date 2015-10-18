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

class task10_2 {
		final static int x = 2;
		final static int n = 5;
    public static void main(String[] args) {
        double result;
		int array[][] = new int[n][n];
		dot.matrix(array, x,n);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				System.out.print(array[i][j] + "   ");
			System.out.println();
		}

    }
}

class dot{
    private double x;
	public static void matrix(int array[][], int x, int n)
	{
		int tmp = x;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				array[i][j] = tmp;
			tmp = tmp * x;
	}

	}
    public double getx()
    {
        return x;
    }
    public void setx()
    {
        Scanner in = new Scanner(System.in);
        x = in.nextDouble();
    }
    
    public void init(double _x)
    {
        x = _x;   
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
