#include "lemin.h"

int	ft_len_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr && *arr)
	{
		while (arr[i])
			i++;
	}
	return (i);
}

int ft_is_plint(char *str)
{
    int num;
    if (str && ft_strlen(str) >= 1)
    {
        num = ft_atoi(str);
        if (num >= 0 && num <= 2147483647)
            return (1);
    }
    return (0);
}