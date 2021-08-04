#include "../ft_printf.h"

void	ft_char (t_tab *tab)
{
	char	c;

	c = va_arg(tab->args, int);
	tab->len += write(1, &c, 1);
}

void	ft_str(t_tab *tab)
{
	char	*str;
	int		i;

	str = va_arg(tab->args, char *);
	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		tab->len += write(1, &str[i], 1);
		i++;
	}
}

static char	*ft_get_str(unsigned long p, char *str, int count)
{
	unsigned long	temp;
	int				i;

	count = 0;
	i = 0;
	temp = p;
	while (temp != 0)
	{
		temp = temp / 16;
		i++;
	}
	while (p != 0)
	{
		if (p % 16 < 10)
			str[count++] = p % 16 + '0';
		else
			str[count++] = p % 16 + 87;
		p = p / 16;
	}
	return (str);
}

static int	ft_chest(unsigned long p)
{
	int	count;

	count = 0;
	while (p != 0)
	{
		count++;
		p = p / 16;
	}
	return (count);
}

void	ft_pointer(t_tab *tab)
{
	unsigned long	p;
	int				count;
	char			*str;

	p = (unsigned long)va_arg(tab->args, void *);
	count = ft_chest(p);
	tab->len += write(1, "0x", 2);
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return ;
	if (p == 0)
		tab->len += write(1, "0", 1);
	else
		str = ft_get_str(p, str, count);
	tab->len = tab->len + count;
	while (count-- > 0 && str[count] != '\0')
		write(1, &str[count], 1);
	free (str);
}
