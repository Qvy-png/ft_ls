/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvy <qvy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 22:05:27 by qvy               #+#    #+#             */
/*   Updated: 2025/09/20 23:46:26 by qvy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_file	*add_file(t_file *head, const char *filename, char type) {

	t_file *new;

	new = malloc(sizeof(t_file));
	if (new == NULL)
		return (NULL);

	new->name = ft_strdup(filename);
	new->type = type;
	new->next = head;
	return (new);
}

void	print_raw_list(t_file *head) {

	t_file *tmp = head;
	while (tmp) {

		ft_putstr(tmp->name);
		ft_putstr("\n");
		tmp = tmp->next;
	}
}

void	sort_list_alpha(t_file *head) {
	t_file	*i;
	t_file	*j;
	char	*tmp_name;
	char	tmp_type;

	for (i = head; i && i->next; i = i->next) {
		for (j = i->next; j; j = j->next) {
			if (ft_strncmp_case(i->name, j->name, 1024) > 0) {
				tmp_name = i->name;
				i->name = j->name;
				j->name = tmp_name;
				tmp_type = i->type;
				i->type = j->type;
				j->type = tmp_type;
			}
		}
	}
}

void	print_list_no_dot(t_file *head) {
	t_file *tmp = head;
	while (tmp) {
		if (tmp->name[0] != '.')
		{
			ft_putstr(tmp->name);
			ft_putstr("  ");
		}
		tmp = tmp->next;
	}
	ft_putstr("\n");
}

void	free_list(t_file *head) {

	t_file *tmp;
	while (head) {

		tmp = head;
		head = head->next;
		free(tmp->name);
		free(tmp);
	}
}

void	print_big_r(t_file *head) {
	
	t_file *tmp;
	
	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->name[0] != '.')
		{
			if (tmp->type == 'd' && ft_strncmp(tmp->name, "..", ft_strlen(tmp->name) != 0))
			ft_putstr("Dir -> ");
			ft_putstr(tmp->name);
			ft_putstr("  ");
			ft_putchar('\n');
		}
		tmp = tmp->next;
	}
	// ft_putchar('\n');
}