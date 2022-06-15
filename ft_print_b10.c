/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_b10.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s < lucdos-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:04:22 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/06/14 22:47:51 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	unsigned int	number;
	unsigned int	n_printed;

	n_printed = 0;
	if (n < 0)
	{
		ft_print_char('-');
		n_printed++;
		number = -n;
	}
	else
		number = n;
	if (number > 9)
	{
		n_printed += ft_print_nbr(number / 10);
	}
	n_printed += ft_print_char((number % 10) + '0');
	
	return (n_printed);
}

int	ft_print_unbr(unsigned int n)
{
	int	n_printed;
	n_printed = 0;
	if (n > 9)
	{
		n_printed += ft_print_unbr(n / 10);
	}
	n_printed += ft_print_char((n % 10) + '0');
	
	return (n_printed);
}

