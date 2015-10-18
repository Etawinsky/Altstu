/* В функции main task1 продемонстрировать использование одного динамического объекта, 
а также  динамического массива объектов. [см. 1) лекция 2]. 
Использовать new, delete, delete[] . При обращении к методам использовать (*a) и ->. 
Заменить поля объектов вспомогательного класса в основном классе на массив объектов с 
изменением методов основного класса. [(см. 1) лекция 2 Пример 1]
Написать программу на java по варианту. Выполнить программу как консольное приложение (compile.bat, run,bat) 
и в среде eclipse. Использовать ввод-вывод (printf, scaner), использовать при выводе русские буквы.
Программа должна вычислять значение выражения, в зависимости от введенных данных, после проверки соответствующих условий.
Проверку следует оптимизировать, чтобы количество условий , && , ||  было минимальным. 
 
 
 Метод, по варианту задания в task4 ч.1 языка Java, возвращающий целое или вещественное значение, сделать статическим.
 [см.1) лек. 5]. В main продемонстрировать вызов метода классом. Задание выполнить в новом проекте.*/

import java.util.Scanner;
import java.lang.Math;

class task9_1 {
    public static void main(String[] args) {
        double result;
        dot test = new dot();
        test.init(0);
        System.out.print("Введите x:");
        test.setx();
        if(test.getx(test) < 15e-5)
            result = test.funca();
        else if( dot.getx(test) >= 15e-5 && dot.getx(test) <= 3.0)
            result = test.funcb();
        else 
            result = test.funcc();
        System.out.println("Результат: " + result);
            }
}

class dot{
    private double x;

     static double getx(dot x)
    {
        return x.x;
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
