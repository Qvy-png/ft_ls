/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvy <qvy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 12:40:37 by rdel-agu          #+#    #+#             */
/*   Updated: 2025/09/20 23:42:27 by qvy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int	main(int argc, char **argv){

	DIR				*dir;
	t_file			*head;
	struct dirent	*entry;
	char			*arg_path;
	int				close_ret;
	struct stat		st;
	char			type;
	char			*full_name;
	int len;

	head = NULL;
	if (argc == 1)
		arg_path = ft_strdup(".");
	else
		arg_path = ft_strdup(argv[1]);
	dir = opendir(arg_path);
	if (dir == NULL)
	{
		ft_putstr("Failed to open path, exiting!");
		free(arg_path);
		return(1);
	}

	entry = readdir(dir);
	while (entry != NULL){

		len = ft_strlen(arg_path) + ft_strlen(entry->d_name) + 2;
		full_name = malloc(len);

		ft_strlcpy(full_name, arg_path, len);
        ft_strlcat(full_name, "/", len);
        ft_strlcat(full_name, entry->d_name, len);
		
		if (lstat(full_name, &st) != 0) {
			
			ft_putstr("Could not lstat element, continuing!");
			continue;
		}

		if (S_ISREG(st.st_mode)) {
			type = 'f';
		} else if (S_ISDIR(st.st_mode)) {
			type = 'd';
		} else if (S_ISLNK(st.st_mode)) {
			type = 'l';
		} else if (S_ISCHR(st.st_mode)) {
			// character device
		} else if (S_ISBLK(st.st_mode)) {
			// block device
		} else if (S_ISFIFO(st.st_mode)) {
			// FIFO / pipe
		} else if (S_ISSOCK(st.st_mode)) {
			// socket
		}

		head = add_file(head, entry->d_name, type);
		entry = readdir(dir);
	}

	sort_list_alpha(head);
	print_list_no_dot(head);

	close_ret = closedir(dir);
	if (close_ret == -1)
		ft_putstr("Closedir failed, exiting!");
	free(arg_path);
	free_list(head);
}

