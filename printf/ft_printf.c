#include "ft_printf.h"

t_tab	*ft_convertation(t_tab *tab)
{
	tab->len = 0;
	tab->hexa = 0;
	return (tab);
}

int	ft_how_to(t_tab *tab, const char *format, int i)
{
	if (format[i] == 'c')
		ft_char(tab);
	else if (format[i] == 's')
		ft_str(tab);
	else if (format[i] == 'p')
		ft_pointer(tab);
	else if (format[i] == 'd' || format[i] == 'i')
		ft_number(tab);
	else if (format[i] == 'u')
		ft_uns_int(tab);
	else if (format[i] == 'x')
		ft_form_hexa(tab);
	else if (format[i] == 'X')
	{
		tab->hexa = 1;
		ft_form_hexa(tab);
		tab->hexa = 0;
	}
	else if (format[i] == '%')
		tab->len += write(1, "%", 1);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	t_tab	*tab;
	int		i;
	int		count;

	if (!format)
		return (0);
	i = 0;
	count = 0;
	tab = (t_tab *)malloc(sizeof(t_tab));
	if (!tab)
		return (-1);
	ft_convertation(tab);
	va_start (tab->args, format);
	while (format[i])
	{
		if (format[i] == '%')
			i = ft_how_to(tab, format, i + 1);
		else
			count += write(1, &format[i], 1);
		i++;
	}
	count += tab->len;
	va_end (tab->args);
	free (tab);
	return (count);
}
