/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 01:00:34 by stena-he          #+#    #+#             */
/*   Updated: 2022/09/28 01:38:06 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error_exit(void)
{
	ft_printf("Error");
	exit (0);
}

/**
 * @brief Converts the initial portion of the string pointed to by str to 
 * int representation.
 * 
 * @param str 
 * @return int 
 */
long int	ft_atoi_mod(const char *str)
{
	long int			output;
	long int			sign;

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
			error_exit();
		output = output * 10 + (*str - '0');
		str++;
	}
	output = sign * output;
	if (output < -2147483648 || output > 2147483647)
		error_exit();
	return (sign * output);
}
