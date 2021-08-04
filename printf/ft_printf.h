#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct s_tab
{
	va_list	args;
	int		len;
	int		hexa;
}				t_tab;

int		ft_printf(const char *format, ...);
int		ft_how_to(t_tab *tab, const char *format, int i);
t_tab	*ft_convertation(t_tab *tab);
void	ft_pointer(t_tab *tab);
void	ft_str(t_tab *tab);
void	ft_char (t_tab *tab);
void	ft_uns_int(t_tab *tab);
void	ft_number(t_tab *tab);
char	*ft_unsigned_itoa(unsigned int n);
void	ft_form_hexa(t_tab *tab);
int		t_len_n_base(unsigned int n, int base);
char	*ft_itoa_hexa(t_tab *tab, char *s, unsigned long n, int base);

#endif
