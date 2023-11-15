/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:31:39 by jucheng           #+#    #+#             */
/*   Updated: 2023/07/22 18:31:41 by jucheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
int		ft_printstr(char *s);
int		ft_print_undec(unsigned int number);
int		ft_print_dec(int number);
int		ft_print_ptr(unsigned long long ptr);
int		ft_print_hexa(unsigned long long ptr);
int		ft_print_long_hexa(unsigned int ptr, char format);
int		ft_formats(va_list args, const char str);

#endif
