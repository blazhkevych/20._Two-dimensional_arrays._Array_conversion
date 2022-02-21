/*
1. Дан двумерный массив размерностью 5х5, заполненный
случайными числами из диапазона от 0 до 100. Переформировать
массив таким образом, чтобы его столбцы располагались по
убыванию их поэлементных сумм.
*/

#include <iostream>
#include <iomanip>
using namespace std;

const int arr2Dsize{ 5 }; // Размер двумерного массива. Глобальная переменная.

void Init2DArrayRandom(int arr2D[][arr2Dsize], int size, int min, int max) // Функция инициализирует двумерный массив псевдослучайными числами с заданным диапазоном.
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr2D[i][j] = rand() % (max - min + 1) + min;
		}
	}
}

void Print2DArr(int arr2D[][arr2Dsize], int size) // Функция выводит на экран двумерный массив.
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << setw(4) << arr2D[i][j];
		}
		cout << endl;
	}
}

void SumOfColumnElements(int arr2D[][arr2Dsize], int size, int arr1D[]) // Функция подсчитывает поэлементную сумму каждого стобца.
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr1D[j] += arr2D[i][j];
		}
	}
}

void PrintSumOfColumnElements(int arr1D[], int size) // Функция выводит на экран поэлементную сумму каждого стобца.
{
	for (int i = 0; i < size; i++)
	{
		cout << setw(4) << arr1D[i];
	}
}

void ChangeColumns2DArr(int arr2D[][arr2Dsize], int size, int currElem, int prevElem) // Функция меняет местами столбцы в двумерном массиве.
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int temp = arr2D[i][currElem];
			arr2D[i][currElem] = arr2D[i][prevElem];
			arr2D[i][prevElem] = temp;
		}
	}
}

void Sort1DArr(int arr2D[][arr2Dsize], int size, int arr1D[]) // Функция сортирует одномерный массив с поэлементными суммами каждого стобца.
{
	int temp{ 0 };
	for (int i = 0; i < size; i++)
	{
		for (int j = 1; j < size - i; j++)
		{
			if (arr1D[j - 1] > arr1D[j]) // Если сумма 0-го елемента больше суммы 1-го елемента
			{
				temp = arr1D[j];
				arr1D[j] = arr1D[j - 1];
				arr1D[j - 1] = temp;
				ChangeColumns2DArr(arr2D, size, j, j - 1);
			}
		}
	}
}

int main()
{
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

	Init2DArrayRandom(arr2D, arr2Dsize, min, max);
	Print2DArr(arr2D, arr2Dsize);

	int arr1D[arr2Dsize]{ 0 }; // Одномерный массив сожержащий поэлементную сумму каждого столбца.

	SumOfColumnElements(arr2D, arr2Dsize, arr1D);
	PrintSumOfColumnElements(arr1D, arr2Dsize);

	Sort1DArr(arr2D, arr2Dsize, arr1D);
	cout << endl << endl;
	Print2DArr(arr2D, arr2Dsize);
	PrintSumOfColumnElements(arr1D, arr2Dsize);

	return 0;
}