// Ex9matrixs.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	float P[12][14];
	int N, K;

	printf("Enter N: ");
	scanf_s("%d", &N); // ввод числа строк матрицы

	printf("Enter K: ");
	scanf_s("%d", &K); // ввод числа столбцов матрицы

	// ввод матрицы
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			printf("Enter P[%d][%d]: ", i, j);
			scanf_s("%f", &P[i][j]);
		}
	}

	// вывод матрицы
	printf("Matrix P:\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++)
			printf("%6.2f", P[i][j]);
		
		printf("\n");
	}

	float max_odd, min_even; // переменные для максимальной суммы нечётных столбцов и минимальной суммы чётных столбцов
	for (int i = 0; i < 1; i++) {
		float sum_odd = 0; // сумма элементов нечётных столбцов
		float sum_even = 0; // сумма элементов чётных столбцов

		for (int j = 0; j < K; j++)
			if (j % 2)
				sum_odd += P[i][j]; // если столбец чётный, то прибавляем к сумме элементов чётных столбцов 
			else
				sum_even += P[i][j]; // а иначе к сумме элементов нечётных столбцов

		printf("\nsum even: %f, sum odd: %f", sum_odd, sum_even);
		max_odd = sum_odd; // задаём начальное значение максимальной суммы
		min_even = sum_even; // и минимальной суммы
	}

	for (int i = 1; i < N; i++) {
		float sum_odd = 0;
		float sum_even = 0;

		for (int j = 0; j < K; j++) {
			if (j % 2)
				sum_odd += P[i][j];
			else
				sum_even += P[i][j];
		}

		if (max_odd < sum_odd)
			max_odd = sum_odd; // обновляем значения максимальной суммы, если нужно

		if (min_even > sum_even)
			min_even = sum_even; // обновляем значения минимальной суммы, если необходимо

		printf("\nRow %d. sum even: %f, sum odd: %f", i, sum_odd, sum_even); // выводим значения сумм для каждой строки
	}

	printf("\n\nmax even: %f, min odd: %f\n", max_odd, min_even); // выыодим значения максимумов
	system("pause");

    return 0;
}

