/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s < lucdos-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:27:37 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/06/15 20:06:50 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_set_print(va_arg arg, char c)
{
	if (c == 'c')
		return (ft_print_char(arg)):
	if (c == 's')
		return (ft_print_str(arg)):
	if (c == 'p')
		return (write(1, "0x", 2) + ft_print_pointer(arg)):
	if (c == 'd' || c == 'i')
		return (ft_print_nbr(arg)):
	if (c == 'u')
		return (ft_print_unbr(arg)):
	if (c == 'x')
		return (ft_print_hex_low(arg)):
	if (c == 'X')
		return (ft_print_hex_up(arg)):
	if (c == '%')
		return (ft_print_char('%');
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
			bytes += ft_set_print(va_arg(list, input[i + 1]));
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
