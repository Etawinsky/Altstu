/* Написать консольное' приложение на c# по вводу небольшого массива с консоли 
 * и созданию нового целочисленного или вещественного массива по варианту задания.
 * Ввод выполняется в одну строку, причем пользователь может вводить через несколько пробелов. 
 * При преобразовании в число проверить правильность ввода и при необходимости вывести сообщение
 * о повторном вводе. вывод произвольный (в строку, столбец).
 * 
 * 
 * В 21 Дан массив вещественных положительных чисел. 
 * Записать в массив B дробные части тех чисел, 
 * целая часть которых по модулю лежит в диапазоне [3,7].
 */

using System;

namespace test2
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			string[] s1;    // массив строк для разбивки строки на числа
			string s = "";
			double[] Data = new double[100]; // максимальное возможное количество
			int N = 0;
			int i;
			Console.WriteLine("Введите несколько чисел:");
			s = Console.ReadLine();

			s1 = s.Split(new char[] { ' ', '\t' },StringSplitOptions.RemoveEmptyEntries);
			for(i = 0; i < s1.Length; i++){
				try{
					Data[i] = Convert.ToDouble(s1[i]);
				}catch{
					Console.WriteLine("Ошибка в {0}",s1[i]);
					Console.WriteLine("введите еще это число:");
					while(!double.TryParse(Console.ReadLine(), out Data[i])){
						Console.WriteLine("Опять!:");
					}
				}
				Data [i] = Data[i] - Math.Truncate(Data[i]);
			}
			N = i;
			Console.WriteLine("Новый массив:");
			for(i =0; i < N; i++)
				Console.WriteLine("{0} -- {1}",i , Data[i]);
		}
	}
}
