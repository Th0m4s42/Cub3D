#include <cub3D.h>


/*		EXTERNAL FUNCTS. :

	• open, close, read, write,
	printf, malloc, free, perror,
	strerror, exit, gettimeofday

	• All functions of the math
	library (-lm man man 3 math)

	• All functions of the MinilibX
*/

/*
	PARSING:

	int rgb_to_int(double r, double g, double b)
	{
    	int color = 0;
    	color |= (int)(b * 255);
    	color |= (int)(g * 255) << 8;
    	color |= (int)(r * 255) << 16;
    	return (color);
	}

*/

int	main(int ac, char **av, char **envp)
{
	t_game	game;

	(void)game;
	/*	Mise en place	*/
	printf("Mandatory Part\n");

	if (check_args(ac, ++av, envp) == false)
		return (1);
	return (0);
}
