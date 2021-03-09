#include "Libft1/libft.h"
int		ft_intlen(int i)
{
	int		len;

	len = 0;
	if (i < 0)
	{
		len++;
		i *= -1;
	}
	while (i)
	{
		i /= 10;
		len++;
	}
	return (len);
}

void	msg(const char *str)
{
	ft_putstr_fd(str, 1);
}
