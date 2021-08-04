#include "../ft_printf.h"

void	ft_number(t_tab *tab)
{
	char	*num;
	int		j;
	int		i;

	j = va_arg(tab->args, int);
	i = 0;
	num = ft_itoa(j);
	if (!num)
		return ;
	while (num[i])
	{
		 tab->len += write(1, &num[i], 1);
		i++;
	}
	free(num);
}

void	ft_uns_int(t_tab *tab)
{
	char			*num;
	unsigned int	j;
	int				i;
	int				n_len;

	j = va_arg(tab->args, unsigned int);
	i = 0;
	num = ft_unsigned_itoa(j);
	if (!num)
		return ;
	n_len = ft_strlen(num);
	while (num[i])
	{
		tab->len += write(1, &num[i], 1);
		i++;
	}
	free(num);
}
