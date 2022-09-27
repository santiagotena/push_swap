/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:36:59 by stena-he          #+#    #+#             */
/*   Updated: 2022/09/27 20:40:44 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	atod_loop(char *arr, int afterdot, float scale, float *val)
{
	while (*arr)
	{
		if (!ft_isdigit(*arr) && !(*arr == '.'))
		{
			ft_printf("Wait. That's illegal.\n\n");
			print_help();
			exit(0);
		}
		if (afterdot)
		{
			scale = scale / 10;
			*val = *val + (*arr - '0') * scale;
		}
		else
		{
			if (*arr == '.')
			afterdot++;
			else
			*val = *val * 10.0 + (*arr - '0');
		}
		arr++;
	}	
}

double	ft_atod(char *arr)
{
	float	val;
	int		afterdot;
	float	scale;
	int		neg;

	val = 0;
	afterdot = 0;
	scale = 1;
	neg = 0;
	if (*arr == '-')
	{
		arr++;
		neg = 1;
	}
	atod_loop(arr, afterdot, scale, &val);
	if (neg)
		return (-val);
	else
		return (val);
}