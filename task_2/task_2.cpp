/*
2. Дан двумерный массив размерностью 5x5, заполненный
случайными числами из диапазона от 0 до 100. Выполнить
циклический сдвиг массива на заданное количество столбцов.
Направление сдвига задаёт пользователь.
*/

#include <iostream>
#include <iomanip>
#include <windows.h> // Содержит SetConsoleOutputCP()

using namespace std;

const int arr2Dsize{ 5 }; // Размер двумерного массива. Глобальная переменная.

void Init2DArrayRandom(int arr2D[][arr2Dsize], int min, int max) // Функция инициализирует двумерный массив псевдослучайными числами с заданным диапазоном.
{
	for (int i = 0; i < arr2Dsize; i++)
	{
		for (int j = 0; j < arr2Dsize; j++)
		{
			arr2D[i][j] = rand() % (max - min + 1) + min;
		}
	}
}

void Print2DArr(int arr2D[][arr2Dsize]) // Функция выводит на экран двумерный массив.
{
	for (int i = 0; i < arr2Dsize; i++)
	{
		for (int j = 0; j < arr2Dsize; j++)
		{
			cout << setw(4) << arr2D[i][j];
		}
		cout << endl;
	}
}

void ShiftColumnLeft(int arr2D[][arr2Dsize], int numberOfColumns) // Функция в двумерном массиве сдвигает столбец влево.
{
	for (int q = 0; q < numberOfColumns; q++)
	{
		for (int i = 0; i < arr2Dsize; i++)
		{
			int temp = arr2D[i][0];
			for (int j = 0; j < arr2Dsize - 1; j++)
			{
				arr2D[i][j] = arr2D[i][j + 1];
			}
			arr2D[i][arr2Dsize - 1] = temp;
		}
	}
}

void ShiftColumnRight(int arr2D[][arr2Dsize], int numberOfColumns) // Функция в двумерном массиве сдвигает столбец вправо.
{
	for (int q = 0; q < numberOfColumns; q++)
	{
		for (int i = 0; i < arr2Dsize; i++)
		{
			int temp = arr2D[i][arr2Dsize - 1];
			for (int j = arr2Dsize - 1; j > 0; j--)
			{
				arr2D[i][j] = arr2D[i][j - 1];
			}
			arr2D[i][0] = temp;
		}
	}
}

int main()
{
	SetConsoleOutputCP(1251);
	srand(time(0));
	/*
		Функция srand() используется для установки начала последовательности,
	генерируемой функ­цией rand() (функция rand() возвращает псевдослучайные числа).
		Функция srand() позволяет запускать программу несколько раз	с различными
	последователь­ностями псевдослучайных чисел.
	*/

	int min{ 0 }; // Минимальное значение диапазона.
	int max{ 100 }; // Максимальное значение диапазона.
	int arr2D[arr2Dsize][arr2Dsize]{ 0 }; // Объявляем двумерный массив.

	Init2DArrayRandom(arr2D, min, max);
	Print2DArr(arr2D);

	int shearDirection{ 0 };
	do {
		cout << "\nЗадайте направление сдвига: \n"
			<< "1 - влево; 2 - вправо" << endl;
		cin >> shearDirection;

	} while (shearDirection != 1 && shearDirection != 2);

	cout << "\nЗадайте количество столбцов для сдвига: \n";
	int numberOfColumns{ 0 };
	cin >> numberOfColumns;

	enum ShiftDirection
	{
		left = 1, right = 2
	};

	switch (shearDirection)
	{
	case left:
		ShiftColumnLeft(arr2D, numberOfColumns);
		Print2DArr(arr2D);
		break;
	case right:
		ShiftColumnRight(arr2D, numberOfColumns);
		Print2DArr(arr2D);
		break;
	}

	return 0;
}