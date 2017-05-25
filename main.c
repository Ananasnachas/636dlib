/* main.c */
#include "matr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
	int n, i, j;
	FILE *in, *out;
	double **a, **b, **c;
	in = fopen("in.txt", "r");
	out = fopen("out.txt", "w");
	fscanf(in, "%d", &n);
	a = (double**)malloc(n*sizeof(double*));
	b = (double**)malloc(n*sizeof(double*));
	for (i = 0; i < n; i++)
	{
		a[i] = (double*)malloc(n*sizeof(double));
		for (j = 0; j < n; j++)
			fscanf(in, "%lf", &(a[i][j]));
	}
	for (i = 0; i < n; i++)
	{
		b[i] = (double*)malloc(n*sizeof(double));
		for (j = 0; j < n; j++)
			fscanf(in, "%lf", &(b[i][j]));
	}
	int st = clock();
	c = matr(a, b, n);
	int end = clock();
	printf("%d ", end - st);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			fprintf(out, "%lf ", c[i][j]);
		}
		fprintf(out, "\n");
		free(c[i]);
		free(a[i]);
		free(b[i]);
	}
	free(a);
	free(b);
	free(c);
	fclose(out);
	fclose(in);
	return 0;
}
