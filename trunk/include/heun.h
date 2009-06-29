#ifndef __HEUN_H__
#define __HEUN_H__

/* Heun Method (heun.h) */

/*
 ** This header file is for resolving a rank-1 ordinary differential equations.
 ** The number of state variables of each equation is 'N'.
 ** This time, the Heun method was used. The order is up to 2.
 ** Since using computer simulation cannot resolve analytically
 ** the differential equation 'dx(t) / dt = F(x(t), t),'
 ** the time 't' should be discretized.
 ** The Heun method is as follows:
 ** x_tilde = x(t) + hF(x(t), t),
 ** x(t + h) = x(t) + h * ( F(x(t), t) + F(x_tilde, t + h)) / 2,
 ** , where 'h' is the size of discretized time, and is the Runge-Kutta step.
 */

/* Heun Method  */
void heun(double h, int N, void (*dXdt)(double t, double X[], double dXdt[]),
		   double t, double X0[], double X[])
{
	int i;
	/* 
	 ** Dynamically allocating arrays for 'double X[N]'.
	 */
	double *dX = vector(N);
	
	/* x(t + h) = x(t) + hF(x(t), t) */
	dXdt(t, X0, dX);
	for(i = 0; i < N; i++)
	{
		X[i] = X0[i] + h * dX[i];
	}
	
	free_vector(dX);
}

#endif /* __HEUN_H__ */
#define __EULER_H__
