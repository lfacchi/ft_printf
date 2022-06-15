/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s < lucdos-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:27:37 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/06/15 00:19:18 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			if (input[i + 1] == 'c')
			{
				bytes += ft_print_char(va_arg(list, int));
				i++;
			}
			if (input[i + 1] == 's')
			{
				bytes += ft_print_str(va_arg(list, char *));
				i++;
			}
			if (input[i + 1] == 'p')
			{
				bytes += write(1, "0x", 2);
				bytes += ft_print_pointer(va_arg(list, unsigned long));
				i++;
			}
			if (input[i + 1] == 'd' || input[i + 1] == 'i')
			{
				bytes += ft_print_nbr(va_arg(list, int));
				i++;
			}
			if (input[i + 1] == 'u')
			{
				bytes += ft_print_unbr(va_arg(list, unsigned int));
				i++;
			}
			if (input[i + 1] == 'x')
			{
				bytes = ft_print_hex_low(va_arg(list, unsigned long));
				i++;
			}
			if (input[i + 1] == 'X')
			{
				bytes = ft_print_hex_up(va_arg(list, unsigned long));
				i++;
			}
			if (input[i + 1] == '%')
			{
				bytes += ft_print_char('%');
				i++;
			}
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

