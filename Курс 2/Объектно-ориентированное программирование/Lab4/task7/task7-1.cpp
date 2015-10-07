/*
    Поля из объектов вспомогательного класса заменить на массив объектов,
	максимальный размер объявить в константе. Для C++ использовать динамический массив [ 4) лек.4] 
	в отличие от п.2 task3. Добавить метод Insert, позволяющий добавить вспомогательный объект 
	в произвольное место массива (со сдвигом [4)  лек.4 ], в том числе и в конец массива,
	если указанное место превышает имеющееся количество объектов.
	Кроме этого, добавить метод Delete, удаляющий объект из заданного места в массиве (массив в цикле сдвигается). 
	Выполнить задание для C++, Java и C#.
 */

#include <stdio.h>

const int size = 3;
class Test{
	public:
		void Init(int _left, int _right);
		void Display();
	private:
		int left;
		int right;
}

class BigTest{
	public:
		void Init();
		void Insert(int _left, int _right, int pos);
		void Delete(int pos);
	private:
		int n;
		Test *testy;
}
void Test::Init(int _left, int _right)
{
	left = _left;
	right = _right;
}

void Test::Display()
{
	printf("%d %d\n", left, right);
}

void BigTest::Insert(int _left, int _right, int pos)
{
	

}
