/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckenaip <ckenaip@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:01:51 by ckenaip           #+#    #+#             */
/*   Updated: 2025/02/17 15:01:53 by ckenaip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static bool	check_name(char *name)
{
	size_t	it;
	size_t	len;

	len = ft_strlen(name);
	if (len < 5)
		return (ft_putendl_fd("Expect only one *.cub* argument", 2), false);
	it = len - 4;
	if (ft_strncmp(".cub", (name + it), 4) != 0)
		return (ft_putendl_fd(".cub file expected", 2), false);
	return (true);
}

bool	check_args(int ac, char **av, char **envp)
{
	if (ac != 2)
		return (ft_putendl_fd("Expect only one *.cub* argument", 2), false);
	if (envp == NULL)
		return (ft_putendl_fd("Environnement Variable unset", 2), false);
	return (check_name(*av));
}
