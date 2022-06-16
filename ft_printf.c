/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s < lucdos-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:27:37 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/06/16 15:19:03 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_set_print(va_list arg, char c)
{
	if (c == 'c')
		return (ft_print_char(va_arg(arg, int)));
	if (c == 's')
		return (ft_print_str(va_arg(arg, char *)));
	if (c == 'p')
		return (write(1, "0x", 2) + ft_print_pointer(va_arg(arg, unsigned long)));
	if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(arg, int)));
	if (c == 'u')
		return (ft_print_unbr(va_arg(arg,unsigned int)));
	if (c == 'x')
		return (ft_print_hex_low(va_arg(arg, unsigned long)));
	if (c == 'X')
		return (ft_print_hex_up(va_arg(arg, unsigned long)));
	if (c == '%')
		return (ft_print_char('%'));
	return (-1);
}

int ft_printf(const char *input, ...)
{
	va_list list;
	va_start(list, input);
	int i;
	int bytes;

	i = 0;
	while (input[i])
	{
		if (input[i] == '%')
		{
			bytes += ft_set_print(list, input[i + 1]);
			i += 2;
		}
		else
		{
			bytes++;
			write(1, &input[i], 1);
		}
		i++;
	}
	return (bytes);
}
