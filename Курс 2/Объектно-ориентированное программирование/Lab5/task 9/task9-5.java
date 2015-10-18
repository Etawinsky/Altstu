/* В функции main task1 продемонстрировать использование одного динамического объекта, 
а также  динамического массива объектов. [см. 1) лекция 2]. 
Использовать new, delete, delete[] . При обращении к методам использовать (*a) и ->. 
Заменить поля объектов вспомогательного класса в основном классе на массив объектов с 
изменением методов основного класса. [(см. 1) лекция 2 Пример 1]
Написать программу на java по варианту. Выполнить программу как консольное приложение (compile.bat, run,bat) 
и в среде eclipse. Использовать ввод-вывод (printf, scaner), использовать при выводе русские буквы.
Программа должна вычислять значение выражения, в зависимости от введенных данных, после проверки соответствующих условий.
Проверку следует оптимизировать, чтобы количество условий , && , ||  было минимальным. 
 
 Метод Init задания в task4 ч.1 языка Java заменить на конструктор со всеми параметрами, 
 добавить конструктор с одним параметром и конструктор без параметров. 
 В main продемонстрировать вызов всех конструкторов. Задать небольшой массив, используя  конструктор с одним параметром.
 */

import java.util.Scanner;
import java.lang.Math;

class task9_5 {
    public static void main(String[] args) {
        double result;
        dot test = new dot(1);
        dot tst = new dot();
		dot d[]=new dot[5];
		int i;
		for(i=0;i<5;i++){
				d[i]=new dot(i);
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
    
    public dot(double _x, double _y)
    {
		y = _y;
        x = _x;   
    }
    public dot(double _x)
    {
        x = _x;   
    }
    public dot()
    {
        x = 0;   
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
