#include "../cub3D.h"


/*		EXTERNAL FUNCTS. :

	• open, close, read, write,
	printf, malloc, free, perror,
	strerror, exit, gettimeofday

	• All functions of the math
	library (-lm man man 3 math)

	• All functions of the MinilibX
*/

int	main(int ac, char **av, char **envp)
{

	/*	Mise en place	*/
	printf("Mandatory Part\n");

	if (check_args(ac, ++av, envp) == false)
		return (1);
	return (0);
}
