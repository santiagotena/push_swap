/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:12:33 by stena-he          #+#    #+#             */
/*   Updated: 2022/10/13 17:33:52 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void mx_print_strarr(char **arr, const char *delim){
    if(!arr || !delim){
        return;
    }
    int exist = 0;
    int i = 0;

    for(; arr[i + 1]; i++){
        fprintf(stderr, "%s%s", arr[i], delim);
        exist = 1;
    }

    fprintf(stderr, "%s\n", arr[i]);
}

int	main(int argc, char **argv)
{
	t_stack		*a_stack;
	t_stack		*b_stack;
	int			is_string;

	b_stack = NULL;
	is_string = 0;
	if(argc < 2)
		return 1;
	if (argc == 2)
	{
		// fprintf(stderr, "before split\n");
		argv = ft_split(argv[1], ' ');
		mx_print_strarr(argv, "\n");
		// fprintf(stderr, "after split\n");
		if(argv == NULL)
			return 1;
		is_string = 1;
	}
	a_stack = parse_args(argv, is_string);
	// fprintf(stderr, "after prse\n");
	ft_sort(&a_stack, &b_stack);
	free_stack(&a_stack);
	free_stack(&b_stack);
	return (0);
}
