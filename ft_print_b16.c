/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_b16.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s < lucdos-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:19:49 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/06/15 20:22:51 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_hex_low(unsigned long num)
{
	int n_printed;

	n_printed = 0;
	if (num > 16)
	{
		n_printed += ft_print_hex_low(num / 16);
	}
	n_printed += ft_print_char(HEXBASE[num % 16]);
	return (n_printed);

}
int ft_print_hex_up(unsigned long num)
{
	int n_printed;

	n_printed = 0;
	if (num > 16)
	{
		n_printed += ft_print_hex_up(num / 16);
	}
	n_printed += ft_print_char(HEXBASEUP[num % 16]);
	return (n_printed);
}

int ft_print_pointer(unsigned long p)
{
	int	n_printed;
	n_printed = 0;
	if (p == 0)
		write(1,"(nil)", 6);
	else
	{
		if (p > 9)
		{
			n_printed += ft_print_pointer(p / 16);
		}
		n_printed += ft_print_char(HEXBASE[p % 16]);
		
	}
	return (n_printed);
}

