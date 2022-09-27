/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 01:00:34 by stena-he          #+#    #+#             */
/*   Updated: 2022/09/28 01:00:36 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief Converts the initial portion of the string pointed to by str to 
 * int representation.
 * 
 * @param str 
 * @return int 
 */
int	ft_atoi_mod(const char *str)
{
	int		output;
	int		sign;

	output = 0;
	sign = 1;
	if (*str == '-')
	{
		str++;
		sign = -1;
	}
	if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			ft_printf("Error");
			exit (0);
		}
		output = output * 10 + (*str - '0');
		str++;
	}
	return (sign * output);
}
