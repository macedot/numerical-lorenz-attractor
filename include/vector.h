#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stdlib.h>
#include <string.h>

/* Allocating vector region */
double *vector(int N)
{
	/*
	 ** Dynamically allocating an array using "malloc".
	 ** The size of the array is 'N'.
	 */
	return (double *)malloc(N * sizeof(double));
}

/* Releasing vector region */
void free_vector(double *v)
{
	/* Releasing the region of the pointer 'v'. */
	free(v);
}

/* Copying the vector 'a' to the vector 'b' */
void copy_vector(int N, double a[], double b[])
{
	/*
	int i;

	for(i = 0; i < N ; i++) 
	b[i] = a[i];
	*/
	
	memcpy(b, a, N*sizeof(double));
}

#endif /* __VECTOR_H__ */