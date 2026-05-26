/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:22:03 by aternero          #+#    #+#             */
/*   Updated: 2025/03/24 14:57:15 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	ft_printchar(int c);
int	ft_printstr(char *str);
int	ft_printptr(uintptr_t ptr);
int	ft_printnbr(int nb);
int	ft_printunsigned(unsigned int nb);
int	ft_printhexl(unsigned int nb);
int	ft_printhexu(unsigned int nb);

#endif