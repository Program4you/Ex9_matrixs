// Ex9matrixs.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	float P[12][14];
	int N, K;

	printf("Enter N: ");
	scanf_s("%d", &N);

	printf("Enter K: ");
	scanf_s("%d", &K);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			printf("Enter P[%d][%d]: ", i, j);
			scanf_s("%f", &P[i][j]);
		}
	}

	printf("Matrix P:\n");
	for (int i = 0; i < N; i++) {
		float sum_odd = 0;
		float sum_even = 0;

		for (int j = 0; j < K; j++) {
			printf("%6.2f", P[i][j]);

			if (j % 2)
				sum_odd += P[i][j];
			else
				sum_even += P[i][j];
		}
		
		printf("\n");
	}

	float max_odd, min_even;
	for (int i = 0; i < 1; i++) {
		float sum_odd = 0;
		float sum_even = 0;

		for (int j = 0; j < K; j++)
			if (j % 2)
				sum_odd += P[i][j];
			else
				sum_even += P[i][j];

		printf("\nsum even: %f, sum odd: %f", sum_odd, sum_even);
		max_odd = sum_odd;
		min_even = sum_even;
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
			max_odd = sum_odd;

		if (min_even > sum_even)
			min_even = sum_even;

		printf("\nsum even: %f, sum odd: %f", sum_odd, sum_even);
	}

	printf("\n\nmax even: %f, min odd: %f\n", max_odd, min_even);
	system("pause");

    return 0;
}

