/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:25:40 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/06/11 13:16:59 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_duplicate(char **argv, int argc, int index)
{
	int	i;

	i = index + 1;
	while (i < argc)
	{
		if (ft_atoi(argv[index]) == ft_atoi(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

int	validate_args(int argc, char **argv)
{
	int		i;
	long	num;

	i = 0;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (0);
		num = ft_atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (0);
		if (is_duplicate(argv, argc, i))
			return (0);
		i++;
	}
	return (1);
}
