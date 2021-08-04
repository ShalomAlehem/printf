#include "../ft_printf.h"

char	*ft_itoa_hexa(t_tab *tab, char *s, unsigned long n, int base)
{
	int		l;

	l = 0;
	if (n == 0)
	{
		s[l] = '0';
		l++;
	}
	while (n > 0)
	{
		if (base > 10 && (n % base >= 10))
		{
			if (tab->hexa == 0)
				s[l] = (n % base) + 87;
			else
				s[l] = (n % base) + 87 - 32;
		}
		else
			s[l] = ((n % base) + '0');
		l++;
		n = n / base;
	}
	s[l] = '\0';
	return (s);
}

int	ft_len_n_base(unsigned int n, int base)
{
	int		i;

	i = 0;
	if (n == 0)
	{
		i += 1;
		return (i);
	}
	while (n > 0)
	{
		i++;
		n /= base;
	}
	return (i);
}

void	ft_form_hexa(t_tab *tab)
{
	unsigned int	j;
	int				len;
	char			*num;

	j = va_arg(tab->args, unsigned int);
	len = ft_len_n_base(j, 16);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return ;
	num = ft_itoa_hexa(tab, num, j, 16);
	while (num && len-- > 0)
		tab->len += write(1, &num[len], 1);
	free(num);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	char	*s;
	int		len;

	len = ft_len_n_base(n, 10);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	s[len] = '\0';
	len--;
	while (len >= 0)
	{
		s[len] = ((n % 10) + '0');
		n = n / 10;
		len--;
	}
	return (s);
}
