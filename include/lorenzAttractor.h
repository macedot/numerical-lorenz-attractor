/* The Lorenz equations (lorenz.h) */

/*
** This header file describes function type of the Lorenz equations
** for the Runge-Kutta routine (rk.h).
** The Lorenz equations derived by simplifying of convection rolls arising
** in the atmosphere, and described as ordinary differential equations
** that have 3 variables:
** dx / dt = -δx + δy,
** dy / dt = -xz + rx - y,
** dz / dt = xy - bz,
** , where δ, b, and r are parameters, and this time, they are set to as follows:
** δ = 10, b = 8 / 3, and r = 28.
** The Lorenz equations exhibit sensitive dependence on initial conditions.
** This phenomenon is used as the root of "the butterfly effectexternal link". 
*/

/* The notation of functions and variables are consistent with 'rk.h'. */
#define dxdt 	dXdt[0]
#define dydt 	dXdt[1]
#define dzdt 	dXdt[2]
#define x 		X[0]
#define y 		X[1]
#define z 		X[2]

/* The Lorenz equations */
void lorenz(double t, double X[], double dXdt[])
{
	double sigma = 10.0, b=8.0 / 3, r=28.0;

	dxdt = -sigma * x + sigma * y;
	dydt = -x * z + r * x - y;
	dzdt = x * y - b * z;
}

/* releasing the definitions */
#undef dxdt
#undef dydt
#undef dzdt
#undef x
#undef y
#undef z
