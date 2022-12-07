// ChyrunSofialab7.2.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Lab_07_2.cpp
// < Чирун Софія >
// Лабораторна робота № 7.2.1
// Опрацювання багатовимірних масивів ітераційним способом
// Варіант 18

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n);
void Min(int** a, int& jmin, const int k, int& min, int& imin);
int Max(int** a, int& jmax, const int k, int& max, int& imax);
void Change(int** a, const int k, const int n);

int main()
{
	srand((unsigned)time(NULL));
	int Low = -12;
	int High = 23;
	int k = 7;
	int n = 6;
	int min = High, imin = 0;
	int max = Low, imax = 0;
	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];
	Create(a, k, n, Low, High);
	Print(a, k, n);
	Change(a, k, n);
	Print(a, k, n);
	for (int i = 0; i < k; i++)
		delete[] a[i];
	    delete[] a;
	return 0;
}

void Create(int** a, const int k, const int n, const int Low, const int High)
{
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int k, const int n)
{
	cout << endl;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		    cout << endl;
	}
	cout << endl;
}

void Min(int** a, int& jmin, const int k, int& min, int& imin)
{
	for (int i = 0; i < k; i++)
		if (a[i][jmin] < min)
		{
		   min = a[i][jmin];
		   imin = i;
		}
}

int Max(int** a, int& jmax, const int k, int& max, int& imax)
{
	for (int i = 0; i < k; i++)
		if (a[i][jmax] > max)
		{
		   max = a[i][jmax];
		   imax = i;
		}
	return max;
}

void Change(int** a, const int k, const int n)
{
	int tmp, min, max, imin = 0, imax = 0, b;
	for (int j = 0; j < n; j = j + 2)
	{
		b = j + 1;
		min = a[imin][b];
		Min(a, b, k, min, imin);
		cout << min << "  " << imin << endl;
		max = a[imax][j];
		Max(a, j, k, max, imax);
		cout << max << "  " << imax << endl;
		tmp = a[imax][j];
		a[imax][j] = a[imin][b];
		a[imin][b] = tmp;
		imax = 0;
		imin = 0;
	}
}

