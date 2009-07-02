#include <stdio.h>
#include <math.h>
#include <string.h>
#include <getopt.h>

int main(int argc, char** argv)
{
	static struct option long_options[] = 
	{
		{"dimension" , required_argument , NULL , 'd'},
		{"file1"     , required_argument , NULL , '1'},
		{"file2"     , required_argument , NULL , '2'},
		{"help"      , required_argument , NULL , 'h'},
		{ NULL }
	};
	int option_index = 0;
	int c = 0;
	int N = -1;
	int i;
	char *s1 = NULL, *s2 = NULL;
	FILE *f1, *f2;
	double d1, d2, length;
	
	while (c != EOF)
	{
		switch ((c = getopt_long (argc, argv, "ehras:t:x:y:z:", long_options, &option_index)))
		{
			case 'd': /* dimension */
				N = (int) atoi(optarg);
				break;
			case '1': /* file1 */
				s1 = optarg;
				break;
			case '2': /* file2 */
				s2 = optarg;
				break;
			
			case 'h': /* help */
			case '?': /* wrong options */
				fprintf (stderr,
						 "Usage: vectorDiffLength -d [dimension] -1 [file1] -2 [file2]\n"
						 "\n"
						 "Reports bugs at %s\n",
						 "Numerical solution for Lorenz Attractors problem.",
						 "http://code.google.com/p/numerical-lorenz-attractor/");
				return (c != 'a'); /* success or failure */
		}
	}
	if (N == -1 || s1 == NULL || s2 == NULL)
	{
		fprintf (stderr,
				 "Usage: vectorDiffLength -d [dimension] -1 [file1] -2 [file2]\n"
				 "\n"
				 "Reports bugs at %s\n",
				 "Numerical solution for Lorenz Attractors problem.",
				 "http://code.google.com/p/numerical-lorenz-attractor/");
		return (1);
	}
	
	printf("Aqui\n");
	printf("%d\n%s\n%s\n", N, s1, s2);
	
	f1 = fopen(s1, "r");
	f2 = fopen(s2, "r");
	
	while (!feof(f1) && !feof(f2))
	{
		length = 0.0;
		for(i = 0; i < N; i++)
		{
			fscanf(f1, "%lf", &d1);
			fscanf(f2, "%lf", &d2);
			length += (d1 - d2) * (d1 - d2);
		}
		length = sqrt(length);
		printf("%lf\n", length);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}
