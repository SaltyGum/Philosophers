/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modlib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:15:21 by jeluiz4           #+#    #+#             */
/*   Updated: 2023/01/08 20:35:15 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_philo.h"

int	ft_space(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_atoi(char *str, int i, long int out, int sign)
{
	int	pop;

	if (str == NULL)
		return (0);
	while (ft_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		out = out * 10 + str[i] - '0';
		i++;
	}
	if ((out > 2147483647) || (out < -2147483648) || (str[i] != '\0')
		|| !ft_isdigit(str[i - 1]))
		return (0);
	pop = out * sign;
	return (pop);
}
