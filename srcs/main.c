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

	int				len;
	int				flag_ret;
	int				close_ret;
	// int				l, R, a, r, t;
	// int				i;

	char			type;
	char			*arg_path;
	char			*full_name;
	struct stat		st;
	struct dirent	*entry;
	DIR				*dir;
	t_file			*head;
	t_flags			*flags;

	flag_ret = 0;
	head = NULL;
	flags = NULL;
	full_name = NULL;
	// l = R = a = r = t = i = 0;
	if (argc == 1)
		arg_path = ft_strdup(".");
	else //TODO find and store all paths in a linked list
		arg_path = ft_strdup(argv[1]);

	flag_ret = flag_checker(argc, argv);
	if (flag_ret == 1)
		return (2);
	else if (flag_ret == 0)
		flags = flags_extracter(argc, argv);
	else
		ft_putstr("That is the normal ls man\n");

	print_flags(flags);	
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
		full_name = malloc(sizeof(char) * len);
		if (full_name == NULL)
			return (127);
		full_name[0] = '\0';
		ft_strlcpy(full_name, arg_path, ft_strlen(arg_path) + 1);
        ft_strlcat(full_name, "/", len);
        ft_strlcat(full_name, entry->d_name, len);
		
		if (lstat(full_name, &st) != 0) {
			
			ft_putstr("Could not lstat element, continuing!");
			continue;
		}
		free(full_name);

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
	// print_list_no_dot(head);
	print_big_r(head);

	close_ret = closedir(dir);
	if (close_ret == -1)
		ft_putstr("Closedir failed, exiting!");
	free(arg_path);
	free_list(head);
	// free(full_name);
}

