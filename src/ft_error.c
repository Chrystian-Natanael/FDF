/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:16:33 by cnatanae          #+#    #+#             */
/*   Updated: 2024/01/09 11:36:56 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *msn)
{
	if (errno)
		perror("Error");
	else
		ft_putendl_fd(msn, STDERR_FILENO);
	exit(EXIT_FAILURE);
}