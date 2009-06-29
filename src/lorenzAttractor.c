/* Drawing the strange attractor of chaos of the Lorenz equations. */

/*
** For explanation of the Lorenz equations refer to the comments of 'lorenz.h'. 
** An attractor is the stationary state after a long enough time in dissipative
** dynamical system.
** That volume reduces with respect to time passage.
** Especially, the attractor of chaos is called as the strange attractor.
** The Runge-Kutta method was used for the numerical calculation of the ordinary
** differential equations.
** Refer to the comments of 'rk.h' for the Runge-Kutta method.
** For drawing "gnuplotexternal link" was used. 
** The checking of operations of these programs had been done several versions of
** Linux.
*/

#include <stdio.h>
#include <stdlib.h>
#include "rk.h"
#include "lorenzAttractor.h" /* lorenz(double t, double X[], double dXdt[]) */
#define N 3 /* dimension of state variable */
#define h 0.01 /* Runge-Kutta step */
#define T 10000 /* Numbers of caculation of Runge-Kutta */

int main(void)
{
	int t, i;
	/* Dynamically allocating arrays for 'double X0[N],' and 'double X1[N]'. */
	double *X0 = vector(N),*X1 = vector(N);

	/* Initial setting */
	X0[0] = 10.0;
	X0[1] = 20.0;
	X0[2] = 30.0;

	/* Main part */
	for(t = 0; t < T; t++)
	{
		for(i = 0; i < N; i++)
		{
			printf("%f", X0[i]);
			if(i == (N - 1)) putchar('\n');
			else putchar(' ');
		}
		
		/*
		** Putting the function 'lorenz' and the state variable 'X0' at time 'h*t'
		** to get the state variable 'X1' at time 'h*(t+1)'.
		*/
		rk(h,N, lorenz, h*t, X0, X1);
		copy_vector(N, X1, X0);
	}

	return 0;
}
