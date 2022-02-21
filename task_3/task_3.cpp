/*
3. Дан двумерный массив размерностью 5x5, заполненный
случайными числами из диапазона от 0 до 100. Выполнить
циклический сдвиг массива на заданное количество строк.
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

void ShiftRowsUp(int arr2D[][arr2Dsize], int numberOfRows) // Функция в двумерном массиве сдвигает строку вверх.
{
	for (int q = 0; q < numberOfRows; q++)
	{
		for (int i = 0; i < arr2Dsize; i++)
		{
			int temp = arr2D[0][i];
			for (int j = 0; j < arr2Dsize - 1; j++)
			{
				arr2D[j][i] = arr2D[j + 1][i];
			}
			arr2D[arr2Dsize - 1][i] = temp;
		}
	}
}

void ShiftRowDown(int arr2D[][arr2Dsize], int numberOfRows) // Функция в двумерном массиве сдвигает строку вниз.
{
	for (int q = 0; q < numberOfRows; q++)
	{
		for (int i = 0; i < arr2Dsize; i++)
		{
			int temp = arr2D[arr2Dsize - 1][i];
			for (int j = arr2Dsize - 1; j > 0; j--)
			{
				arr2D[j][i] = arr2D[j - 1][i];
			}
			arr2D[0][i] = temp;
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
			<< "1 - вверх; 2 - вниз" << endl;
		cin >> shearDirection;

	} while (shearDirection != 1 && shearDirection != 2);

	cout << "\nЗадайте количество строк для сдвига: \n";
	int numberOfRows{ 0 };
	cin >> numberOfRows;

	enum ShiftDirection
	{
		up = 1, down = 2
	};

	switch (shearDirection)
	{
	case up:
		ShiftRowsUp(arr2D, numberOfRows);
		Print2DArr(arr2D);
		break;
	case down:
		ShiftRowDown(arr2D, numberOfRows);
		Print2DArr(arr2D);
		break;
	}

	return 0;
}