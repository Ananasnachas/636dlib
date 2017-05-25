#include <stdio.h>
#include <stdlib.h>
#include "matr.h"

//Input: a - matrix (dim * dim), b - matrix (dim * dim) 
//Output: none
//stdout: result ('res' matrix);
double **matr(double **a, double **b, int n)
{
	double *d, *e;
	int i = 0, j = 0, k = 0;
	d = (double*)malloc(n*n*sizeof(double));
	e = (double*)malloc(n*n*sizeof(double));
	double **c;
	c = (double**)malloc(n*sizeof(double*));
	for (i = 0; i < n; i++)
	{
		c[i] = (double*)malloc(n*sizeof(double));
	}
	i = 0;
	while (i < n)
	{
		while (j < n)
		{
			d[k] = a[i][j];
			j++;
			k++;
		}
		i++;
		j = 0;
	}
	i = 0;
	j = 0;
	k = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{

			e[j*n + i] = b[i][j];
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	int nn = n*n;
	int f = n, jj, h = 0;
	while (k<n)
	{
		while (j < nn)
		{
			jj = h;
			c[k][i] = 0;
			while (j < n)
			{
				c[k][i] += d[jj] * e[j];
				j++;
				jj++;
			}
			i++;
			n += f;
		}
		j = 0;
		n = f;
		h += f;
		i = 0;
		k++;
	}
	free(d);
	free(e);
	return c;
}
