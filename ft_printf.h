/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s < lucdos-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:39:34 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/06/15 20:16:53 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

# define HEXBASE "0123456789abcdef"
# define HEXBASEUP "0123456789ABCDEF"

int	ft_print_char(char c);
int	ft_print_nbr(int n);
int	ft_print_unbr(unsigned int n);
int	ft_print_str(char *s);
int ft_printf(const char *input, ...);
int ft_print_pointer(unsigned long p);
int ft_print_hex_low(unsigned long num);
int ft_print_hex_up(unsigned long num);
int ft_set_print(va_list arg, char c);

#endif