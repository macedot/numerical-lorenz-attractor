#ifndef __EULER_H__
#define __EULER_H__

/* Explicit Euler Method (euler.h) */

/*
** This header file is for resolving a rank-1 ordinary differential equations.
** The number of state variables of each equation is 'N'.
** This time, the Explicit Euler method was used. The order is up to 2.
** Since using computer simulation cannot resolve analytically
** the differential equation 'dx(t) / dt = F(x(t), t),'
** the time 't' should be discretized.
** The Explici Euler method is as follows:
** x(t + h) = x(t) + hF(x(t), t),
** , where 'h' is the size of discretized time, and is the Runge-Kutta step.
*/

/* Explicit Euler Method  */
int _eulerIsIstarted = 0;
int _eulerN;
double *_eulerdX;

void euler_setUp(int N)
{
	_eulerN = N;
	
	/* 
	** Dynamically allocating arrays for 'double X[N]'.
	*/
	_eulerdX = vector(_eulerN);
	_eulerIsIstarted = 1;
}

void euler_Free()
{
	free_vector(_eulerdX);
	_eulerIsIstarted = 0;
}

void euler(double h, void (*dXdt)(double t, double X[], double dXdt[]),
	double t, double X0[], double X[])
{
	int i;
	
	if(!_eulerIsIstarted)
	{ return; }
	
	/* x(t + h) = x(t) + hF(x(t), t) */
	dXdt(t, X0, _eulerdX);
	for(i = 0; i < _eulerN; i++)
	{
		X[i] = X0[i] + h * _eulerdX[i];
	}
}

#endif /* __EULER_H__ */
