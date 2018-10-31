/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_insert_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:49:44 by sgarcia           #+#    #+#             */
/*   Updated: 2018/09/17 19:34:40 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst		*lst_insert_front(t_lst *lst, int id, char *name)
{
	t_lst		*element;

	element = ft_memalloc(sizeof(*element));
	if (!element)
		exit_str("Erreur : probleme allocation dynamique.");
	element->content = name;
	element->id = id;
	if (lst_is_empty(lst))
		element->next = NULL;
	else
		element->next = lst;
	return (element);
}
