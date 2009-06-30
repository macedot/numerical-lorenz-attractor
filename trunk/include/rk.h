#ifndef __RK_H__
#define __RK_H__

/* Runge-Kutta routine (rk.h) */

/*
** This header file is for resolving a rank-1 ordinary differential equations.
** The number of state variables of each equation is 'N'.
** This time, the Runge-Kutta method was used. The order is up to 3.
** Since using computer simulation cannot resolve analytically
** the differential equation 'dx(t) / dt = F(x(t), t),'
** the time 't' should be discretized.
** The order 4 Runge-Kutta method is as follows:
** d1 = hF(x(t), t),
** d2 = hF(x(t) + d1 / 2, t + h / 2),
** d3 = hF(x(t) + d2 / 2, t + h / 2),
** d4 = hF(x(t) + d3, t + h),
** x(t + h) = x(t) + d1 / 6 + d2 / 3 + d3 / 3 + d4 / 6,
** , where 'h' is the size of discretized time, and is the Runge-Kutta step.
*/

/*
** Putting the Runge-Kutta step 'h,' the rank of the differential equation N,
** the function 'dXdt' which describes the differential equation,
** and the vector 'X0' which contains the state variable at time 't'
** to get the state variable 'X1' at time 't + h'.
** 'dXdt,' which type is 'foo(double t, double X[], double dXdt[])' should be
** defined by user. 
*/

/* Runge-Kutta 4 - 4  */
/* Explicit Euler Method  */
int _rkIsIstarted = 0;
int _rkN;
double *_rkd1, *_rkd2, *_rkd3;
double *_rkXa, *_rkdX ;

void rk_setUp(int N)
{
	_rkN = N;
	
	/* 
	** Dynamically allocating arrays for 'double d1[N],' 'double d2[N],'
	** and 'double d3[N]'.
	*/
	_rkd1 = vector(_rkN), 
	_rkd2 = vector(_rkN),
	_rkd3 = vector(_rkN);
	/* 
	** Dynamically allocating arrays for 'double Xa[N],' and 'double X[N]'.
	*/
	_rkXa = vector(_rkN),
	_rkdX = vector(_rkN);
	_rkIsIstarted = 1;
}

void rk_Free()
{
	free_vector(_rkd1);
	free_vector(_rkd2);
	free_vector(_rkd3);
	free_vector(_rkXa);
	free_vector(_rkdX);
	_rkIsIstarted = 0;
}

void rk(double h, void (*dXdt)(double t, double X[], double dXdt[]),
	double t, double X0[], double X[])
{
	int i;
	
	if(!_rkIsIstarted)
	{ return; }
	
	/* d1 = hF(x(t), t) */
	dXdt(t, X0, _rkdX);
	for(i = 0; i < _rkN; i++)
	{
		_rkd1[i] = h * _rkdX[i];
		_rkXa[i] = X0[i] + 0.5 * _rkd1[i];
	}

	/* d2 = hF(x(t) + d1 / 2, t + h / 2) */
	dXdt(t + 0.5 * h, _rkXa, _rkdX);
	for(i = 0; i < _rkN; i++)
	{
		_rkd2[i] = h * _rkdX[i];
		_rkXa[i] = X0[i] + 0.5 * _rkd2[i];
	}

	/* d3 = hF(x(t) + d2 / 2, t + h / 2) */ 
	dXdt(t + 0.5 * h, _rkXa, _rkdX);
	for(i = 0; i < _rkN; i++)
	{
		_rkd3[i] = h * _rkdX[i];
		_rkXa[i] = X0[i] + _rkd3[i];
	}

	/* x(t + h) = x(t) + d1 / 6 + d2 / 3 + d3 / 3 */
	dXdt(t + h, _rkXa, _rkdX);
	for(i = 0; i < _rkN; i++)
	{ X[i] = X0[i] + (_rkd1[i] + _rkd2[i] * 2 + _rkd3[i] * 2 + h * _rkdX[i]) / 6.0; }
	
}

#endif /* __RK_H__ */

