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
int _heunIsIstarted = 0;
int _heunN;
double *_heunXa, *_heunK1, *_heunK2;

void heun_setUp(int N)
{
	_heunN = N;
	
	/* 
	 ** Dynamically allocating arrays for 'double Xa[N]', 'double K1[N]' and 'double K2[N]'.
	 */
	_heunXa = vector(_heunN);
	_heunK1 = vector(_heunN);
	_heunK2 = vector(_heunN);
	_heunIsIstarted = 1;
}

void heun_Free()
{
	free_vector(_heunXa);
	free_vector(_heunK1);
	free_vector(_heunK2);
	_heunIsIstarted = 0;
}

void heun(double h, void (*dXdt)(double t, double X[], double dXdt[]),
		   double t, double X0[], double X[])
{
	int i;
	
	if(!_heunIsIstarted)
	{ return; }
	 
	/* Xa = X0 + h * F(x(t), t) */
	dXdt(t, X0, _heunK1);
	for(i = 0; i < _heunN; i++)
	{
		_heunXa[i] = X0[i] + h * _heunK1[i];
	}
	
	/* x(t + h) = x(t) + h * ( F(x(t), t) + F(x_tilde, t + h)) / 2 */
	dXdt(t + h, _heunXa, _heunK2);
	for(i = 0; i < _heunN; i++)
	{
		X[i] = X0[i] + h * (_heunK1[i] + _heunK2[i]) / 2.0;
	}
}

#endif /* __HEUN_H__ */
