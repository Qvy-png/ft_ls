/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvy <qvy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 12:46:54 by rdel-agu          #+#    #+#             */
/*   Updated: 2025/09/20 22:07:04 by qvy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_putchar(char c){

	write(1, &c, 1);
}

void	ft_putstr(char *str){

	write(1, str, ft_strlen(str));
}

int	ft_strlen(char *str){

	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void    ft_putnbr(int n){

	long int	nb;

	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

char	*ft_strdup(const char *s1){

	int		i;
	char	*dup;

	i = 0;
	while (s1[i])
		i++;
	dup = (char *)malloc(sizeof(char) * i + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < dstsize)
		i++;
	while (src [j] && (i + j + 1) < dstsize)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < dstsize)
		dst[i + j] = '\0';
	return (i + ft_strlen((char *)src));
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while ((char)dst[i] != '\0')
		i++;
	while ((char)src[j] != '\0' && j + 1 < dstsize)
	{
		dst[j] = (char)src[j];
		j++;
	}
	if (j < dstsize)
		dst[j] = '\0';
	return (ft_strlen((char *)src));
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*cs1;
	unsigned char	*cs2;

	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (cs1[i] && cs2[i] && i < n - 1)
	{
		if (cs1[i] != cs2[i])
			return (cs1[i] - cs2[i]);
		i++;
	}
	return (cs1[i] - cs2[i]);
}

char to_lower(char c) {
	if (c >= 'A' && c <= 'Z')
		return c + ('a' - 'A');
	return c;
}

int	ft_strncmp_case(const char *s1, const char *s2, size_t n) {
	size_t i = 0;
	while (i < n && s1[i] && s2[i]) {
		char c1 = to_lower(s1[i]);
		char c2 = to_lower(s2[i]);
		if (c1 != c2)
			return c1 - c2;
		i++;
	}
	if (i < n)
		return to_lower(s1[i]) - to_lower(s2[i]);
	return 0;
}
