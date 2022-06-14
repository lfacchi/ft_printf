/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s < lucdos-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:27:37 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/06/14 16:39:08 by lucdos-s         ###   ########.fr       */
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
		//c Prints a single character.
			if (input[i + 1] == 'c')
			{
				bytes += ft_print_char(va_arg(list, int));
				i++;
			}
		// //s Prints a string (as defined by the common C convention).
			if (input[i + 1] == 's')
			{
				bytes += ft_print_str(va_arg(list, char *));
				i++;
			}
		// //p The void * pointer argument has to be printed in hexadecimal format.
		// 	if (input[i + 1] == 'p')
		// //d Prints a decimal (base 10) number.
			if (input[i + 1] == 'd' || 'i')
			{
				bytes += ft_print_nbr(va_arg(list, int));
				i++;
			}
		// //u Prints an unsigned decimal (base 10) number.
			if (input[i + 1] == 'u')
			{
				bytes += ft_print_unbr(va_arg(list, unsigned long int));
				i++;
			}
		// //x Prints a number in hexadecimal (base 16) lowercase format.
		// 	if (input[i + 1] == 'x')
		// //X Prints a number in hexadecimal (base 16) uppercase format.
		// 	if (input[i + 1] == 'X')
		// //% Prints a percent sign.
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

// int ft_in_list(char *text_list, char c)
// {

// }
