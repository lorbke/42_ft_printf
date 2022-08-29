/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:06:10 by lorbke            #+#    #+#             */
/*   Updated: 2022/08/29 16:06:29 by lorbke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char *format = "ddd";
	int	i = 423498;
	// int	i2 = 1111111111;

	printf(" |%i\n", ft_printf("%i, %s", i, format));
	printf(" |%i\n", printf("%i, %s", i, format));
	return (0);
}
