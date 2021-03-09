/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <jfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:56:47 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/11/07 14:23:38 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		ft_atoi(const char *str)
{
	int nb;
	int i;
	int s;

	s = 1;
	nb = 0;
	i = 0;
	while ((str[i] == 32) || (str[i] == 12) || (str[i] == 10) ||
			(str[i] == 13) || (str[i] == 9) || (str[i] == 11))
	{
		i++;
	}
	if ((str[i] == 45) || (str[i] == 43))
	{
		if (str[i] == 45)
			s = s * -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (nb * s);
}
