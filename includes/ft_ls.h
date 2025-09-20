/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvy <qvy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 12:40:32 by rdel-agu          #+#    #+#             */
/*   Updated: 2025/09/20 23:04:03 by qvy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/xattr.h>
#include <dirent.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// STORING LIST
typedef struct s_file {
    char			*name;
    char			type;
    int				printed;
    struct s_file	*next;
} t_file;

// STR_UTILS
void    ft_putnbr(int n);
char    to_lower(char c);
void	ft_putchar(char c);
int	    ft_strlen(char *str);
void	ft_putstr(char *str);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int	    ft_strncmp(const char *s1, const char *s2, size_t n);
int     ft_strncmp_case(const char *s1, const char *s2, size_t n);

// LIST_UTILS
void    free_list(t_file *head);
void    print_raw_list(t_file *head);
void    sort_list_alpha(t_file *head);
void    print_list_no_dot(t_file *head);
t_file  *add_file(t_file *head, const char *filename, char type);

#endif