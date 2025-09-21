#include "../includes/ft_ls.h"

int only_lRart(char *str){

    int i;

    i = 0;
    while (str[i]){

        if (str[i] != '-' && str[i] != 'l' && str[i] != 'R' && str[i] != 'a' && str[i] != 'r' && str[i] != 't')
            return (1);
        i++;
    }
    return (0);
}

int	flag_checker(int argc, char **argv){

	int	i;

	i = 1;

	if (argc == 1)
		return (3);
	while (i < argc)
	{
		// l R a r t
		if (argv[i][0] == '-'){

			if (only_lRart(argv[i]) == 0)
				return (0);
			else
			{
				ft_putstr("./ft_ls: invalid option -- '");
				ft_putstr(argv[i]);
				ft_putstr("'\n");
				return (1);
			}
		}
		else
			return (3);
		i++;
	}
	return (0);
}

t_flags *flags_extracter(int argc, char **argv) {
    t_flags *head = NULL;
    t_flags *current = NULL;

    int i = 1;
    while (i < argc) {
        if (argv[i][0] == '-') {
            t_flags *node = malloc(sizeof(t_flags));
            node->name = argv[i];
            node->next = NULL;

            if (!head) {
                head = node;
                current = node;
            } else {
                current->next = node;
                current = node;
            }
        }
        i++;
    }
    return head;
}

void print_flags(t_flags *head) {
 
	t_flags *tmp;

	tmp = head;
	
	while (tmp) {
		ft_putstr(tmp->name);
		tmp = tmp->next;
    }
}
