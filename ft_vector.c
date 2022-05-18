/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 11:24:26 by lorbke            #+#    #+#             */
/*   Updated: 2022/05/18 21:03:29 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// whole reallocf function is shitty
static void	*ft_reallocf(void *ptr, size_t size)
{
	void	*ptr_cpy;

	if (ptr == NULL)
		return (NULL);
	else if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	ptr_cpy = (void *)malloc(size);
	if (ptr_cpy == NULL)
		return (NULL);
	ft_memmove(ptr_cpy, ptr, size);
	free(ptr);
	return (ptr_cpy);
}

void	ft_vector_init(t_vector *vector)
{
	vector->len = 0;
	vector->temp_len = 0;
	vector->output = (char *)malloc(sizeof(char) * 1);
}

void	ft_vector_push_back(t_vector *vector, char c, int n)
{
	if (vector->temp_len + n >= vector->len)
	{
		vector->len += n + 100;
		vector->output = ft_reallocf(vector->output, vector->len);
	}
	while (n > 0)
	{
		vector->output[vector->temp_len] = c;
		vector->temp_len++;
		n--;
	}
}
