/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-agu <rdel-agu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 12:40:32 by rdel-agu          #+#    #+#             */
/*   Updated: 2025/09/20 13:06:04 by rdel-agu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/xattr.h>
#include <dirent.h>

// STR_UTILS
int	ft_strlen(char *str);
void	ft_putstr(char *str);
void    ft_putnbr(int n);
