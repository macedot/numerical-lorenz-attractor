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

#ifndef EOF
#define EOF (-1)
#endif

      double time_step  = 0.01;     /* Time step (h) */
unsigned int time_final = 10000;    /* Numbers of steps in time */

void (*numericalMethod)(double, int, void (*)(double, double [], double []), 
						double, double [], double []);

int main(int argc, char *argv[])
{
	unsigned int i, t;
	
	/* Dynamically allocating arrays for 'double X0[N],' and 'double X1[N]'. */
	double *X0 = vector(N),
	       *X1 = vector(N);
	
	static struct option long_options[] = {
		{"euler"  , no_argument       , NULL , 'e'},
		{"heun"   , no_argument       , NULL , 'h'},
		{"rk"     , no_argument       , NULL , 'r'},
		{"help"   , no_argument       , NULL , 'a'},
		{"init-x" , required_argument , NULL , 'x'},
		{"init-y" , required_argument , NULL , 'y'},
		{"init-z" , required_argument , NULL , 'z'},
		{ NULL }
	};
	int option_index = 0;
	int c = 0;
	
	/* Initial setting */
	numericalMethod = rk;
	X0[0] = 10.0;
	X0[1] = 20.0;
	X0[2] = 30.0;	
	 
	/* parse options using getopt */
	while (c != EOF) {
		switch ((c = getopt_long (argc, argv, "ehras:t:x:y:z:", long_options, &option_index))) {
			case 'e': /* euler */
				numericalMethod = euler;
				break;
			case 'h': /* heun */
				numericalMethod = heun;
				break;
			case 'r': /* runge-kutta 4-4 */
				numericalMethod = rk;
				break;
				
			case 's': /* time step */
				time_step = (double) atof(optarg);
				break;
			case 't': /* final time */
				time_final = (unsigned int) atoi(optarg);
				break;
				
			case 'x': /* Initial Condition for x */
				X0[0] = (double) atof(optarg);
				break;
			case 'y': /* Initial Condition for y */
				X0[1] = (double) atof(optarg);
				break;
			case 'z': /* Initial Condition for z */
				X0[2] = (double) atof(optarg);
				break;
				
			case 'a': /* help */
			case '?': /* wrong options */
				fprintf (stderr,
						 "Usage: lorenzAttractor [OPTION]\n"
						 "%s\n"
						 
						 "\n"
						 
						 "  -e   --euler				use explicit Euler method\n"
						 "  -h   --heun					use Heun Method\n"
						 "  -r   --rk					use Runge-Kutta 4-4 method\n"
						 
						 "  -s   --step VALUE			time step\n"
						 "  -t   --time VALUE			final time\n"
						 
						 "  -x   --init-x VALUE			initial condition for x\n"
						 "  -y   --init-y VALUE			initial condition for y\n"
						 "  -z   --init-z VALUE			initial condition for z\n"

						 "  -a   --help					display this help and exit\n"
						 
						 "\n"
						 "Reports bugs at %s\n",
						 "Numerical solution for Lorenz Attractors problem.",
						 "http://code.google.com/p/numerical-lorenz-attractor/");
				return (c != 'a'); /* success or failure */
		}
	}

	/* Main part */
	for(i = 0; i < N; i++)
	{
		printf("%f", X0[i]);
		if(i == (N - 1)) putchar('\n');
		else putchar(' ');
	}
	
	for(t = 0; t < time_final; t++)
	{
		/*
		** Putting the function 'lorenz' and the state variable 'X0' at time 'h*t'
		** to get the state variable 'X1' at time 'h*(t+1)'.
		*/
		numericalMethod(time_step, N, lorenz, time_step*t, X0, X1);
		copy_vector(N, X1, X0);
		
		for(i = 0; i < N; i++)
		{
			printf("%f", X0[i]);
			if(i == (N - 1)) putchar('\n');
			else putchar(' ');
		}		
	}

	return 0;
}
