/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckenaip <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:31:58 by ckenaip           #+#    #+#             */
/*   Updated: 2023/11/16 11:32:16 by ckenaip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* to add "t_list *new" to the beginning of the list
   new -> next = lst Mettre l'adresse du debut de la liste dans next de new
   qui devient first
   *lst = new **lst etant l'adresse du 1er pointeur, on lui donne l'adresse
   de la nouvelle liste(new)
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
