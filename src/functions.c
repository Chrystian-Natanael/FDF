/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 02:05:21 by cnatanae          #+#    #+#             */
/*   Updated: 2024/01/14 02:41:20 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

int	ipart_(double X)
{
	return ((int)(X));
}

int	round_(double X)
{
	return ((int)(((double)(X)) + 0.5));
}

double	fpart_(double X)
{
	return (((double)(X)) - (double)ipart_(X));
}

double	rfpart_(double X)
{
	return (1.0 - fpart_(X));
}

void	swap(double *a, double *b)
{
	double	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
