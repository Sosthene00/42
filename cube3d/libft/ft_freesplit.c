/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freesplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:03:37 by agaubert          #+#    #+#             */
/*   Updated: 2019/11/14 14:06:29 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_freesplit(char **ptr)
{
    int i;

    i = -1;
    while (ptr[++i] != 0)
    {
        free(ptr[i]);
        ptr[i] = NULL;
    }
    free(ptr[i]);
    free(ptr);
    ptr = NULL;
}