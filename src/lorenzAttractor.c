/* Drawing the strange attractor of chaos of the Lorenz equations. */

/*
** For explanation of the Lorenz equations refer to the comments of 'lorenz.h'. 
** An attractor is the stationary state after a long enough time in dissipative
** dynamical system.
** That volume reduces with respect to time passage.
** Especially, the attractor of chaos is called as the strange attractor.
** The Runge-Kutta method was used for the numerical calculation of the ordinary
** differential equations.
 
** Refer to the comments in include files of numerical methods.

** For drawing "gnuplot" was used. 

** The checking of operations of these programs had been done several versions of
** Linux.
*/

/* Standart C library */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <float.h>
#include <math.h>
#include <time.h>
#include <memory.h>
#include <getopt.h>

#include "vector.h"
#include "euler.h"
#include "heun.h"
#include "rk.h"
#include "lorenzAttractor.h" /* lorenz(double t, double X[], double dXdt[]) */

#define N 3			/* dimension of state variable */
#define h 0.01		/* Time step */
#define T 10000		/* Numbers of steps in time */

#ifndef EOF
#define EOF (-1)
#endif

/*
void (*numericalMethod)(double h, int N, void (*dXdt)(double t, double X[], double dXdt[]), 
						double t, double X0[], double X[]);
*/

int main(int argc, char *argv[])
{
	int t, i;
	/* Dynamically allocating arrays for 'double X0[N],' and 'double X1[N]'. */
	double *X0 = vector(N),
	       *X1 = vector(N);
	
	/* TODO : Parametro na linha de comando para selecionar o metodo; */
	/* TODO : Parametro na linha de comando para informar as condicoes iniciais e o passo no tempo; */

	static struct option long_options[] = {
	/* {"heun" , required_argument, NULL, 's'}, */
		{"euler", no_argument , NULL, 'e'},
		{"heun" , no_argument , NULL, 'h'},
		{"rk"   , no_argument , NULL, 'r'},
		{"help" , no_argument , NULL, 'a'},
		{ NULL }
	};
	int option_index = 0;
	int c = 0;
	
	/* Initial setting */
	X0[0] = 10.0;
	X0[1] = 20.0;
	X0[2] = 30.0;	
	/* numericalMethod = rk; */
	 
	/* parse options using getopt */
	while (c != EOF) {
		switch ((c = getopt_long (argc, argv, "ehra", long_options, &option_index))) {
		/* geodesation_order = (guint) atoi (optarg); */
			case 'e': /* euler */
				/* numericalMethod = euler; */
				break;
			case 'h': /* heun */
				/* numericalMethod = heun; */
				break;
			case 'r': /* runge-kutta 4-4 */
				/* numericalMethod = rk; */
				break;
			case 'a': /* help */
			case '?': /* wrong options */
				fprintf (stderr,
						 "Usage: lorenzAttractor [OPTION]\n"
						 "Numerical calculation of Lorenz Attractors.\n"
						 
						 "\n"
						 
						 "  --euler          use explicit Euler method\n"
						 "  --heun           use Heun Method\n"
						 "  --rk             use Runge-Kutta 4-4 method\n"
						 
						 "  --help           display this help and exit\n"
						 
						 "\n"
						 "Reports bugs at http://code.google.com/p/numerical-lorenz-attractor/\n");
				return (c != 'a'); /* success or failure */
		}
	}

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
		/* numericalMethod(h, N, lorenz, h*t, X0, X1); */
		rk(h, N, lorenz, h*t, X0, X1);
		copy_vector(N, X1, X0);
	}

	return 0;
}
