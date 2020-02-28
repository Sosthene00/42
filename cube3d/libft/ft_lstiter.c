/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 15:09:56 by agaubert          #+#    #+#             */
/*   Updated: 2019/11/30 21:27:44 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*cur;
	t_list	*next;

	cur = lst;
	while (cur != NULL)
	{
		next = cur->next;
		(*f)(cur->content);
		cur = next;
	}
}
