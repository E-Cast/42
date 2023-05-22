/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 00:47:41 by ecastong          #+#    #+#             */
/*   Updated: 2023/05/22 02:38:04 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_minfieldlen(const char *format)
{
	size_t	min_fieldw;

	min_fieldw = 0;
	while (*format >= '0' && *format <= '9')
	{
		min_fieldw *= 10;
		min_fieldw += *format - '0';
		format++;
	}
	return (min_fieldw);
}

char	*ft_print_char(char c, int mfw, int dash)
{
	char	*buffer;

	if (mfw == 0)
		mfw = 1;
	buffer = ft_calloc(mfw + 1, sizeof(char));
	buffer = ft_memset(buffer, ' ', mfw * sizeof(char));
	if (!buffer)
		return (NULL);
	if (dash)
		buffer[0] = c;
	else
		buffer[ft_strlen(buffer) - 1] = c;
	return (buffer);
}

char	*ft_print_percent(int mfw, int dash)
{
	char	*buffer;

	if (mfw < 1)
		mfw = 1;
	buffer = ft_calloc(mfw + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	buffer = ft_memset(buffer, ' ', mfw * sizeof(char));
	if (dash)
		buffer[0] = '%';
	else
		buffer[ft_strlen(buffer) - 1] = '%';
	return (buffer);
}

char	*ft_print_str(char *str, size_t mfw, size_t precision, int presci, int dash)
{
	char	*buffer;
	size_t	i;
	size_t	j;

	if (ft_strlen(str) < precision || presci == 0)
		precision = ft_strlen(str);
	if (mfw < precision)
		mfw = precision;
	buffer = ft_calloc(mfw + 1, sizeof(char));
	buffer = ft_memset(buffer, '0', mfw * sizeof(char));
	if (!buffer)
		return (NULL);
	i = 0;
	j = 0;
	if (dash)
		i = ft_strlen(buffer) - precision;
	while (buffer[i] && precision)
	{
		buffer[i] = str[j];
		precision--;
		i++;
		j++;
	}
	return (buffer);
}

#include <stdio.h>
int	main(void)
{
	printf("%s\n", ft_print_char('a', 0, 0));
	printf("%s\n", ft_print_char('a', 6, 0));
	printf("%s\n", ft_print_char('a', 3, 1));
	printf("%s\n", ft_print_char('a', 50, 1));
	printf("%s\n", ft_print_char('a', 50, 0));
	printf("%s\n", ft_print_percent(0, 0));
	printf("%s\n", ft_print_percent(6, 0));
	printf("%s\n", ft_print_percent(3, 1));
	printf("%s\n", ft_print_percent(50, 1));
	printf("%s\n", ft_print_percent(50, 0));

	// printf("%-3.2147483648s\n", "hello");
	// printf("%-15.4s\n", "hello");
	// printf("%-3.5s\n", "hello");
	// printf("%-3.0s\n", "hello");
	printf("%s\n", ft_print_str("Hello", 15, 3, 0, 0));
	printf("%s\n", ft_print_str("Hello", 15, 4, 1, 0));
	printf("%s\n", ft_print_str("Hello", 3, 3, 0, 0));
	printf("%s\n", ft_print_str("Hello", 3, 3, 1, 0));
	printf("%s\n", ft_print_str("Hello", 15, 3, 0, 1));
	printf("%s\n", ft_print_str("Hello", 15, 5, 1, 1));
	printf("%s\n", ft_print_str("Hello", 10, 4, 1, 1));
}
