

#include"parsing.h"

double	ft_decimal_part(const char *str)
{
	double	result;
	int		i;

	result = 0;
	i = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (str[i] != 0)
		put_error("decimal error");
	return (result / (10 ^ i));
}

double	ft_atol(const char *str)
{
	double	result;
	int		i;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (str[i] != '.' && str[i] != 0)
		put_error("Integer error ");
	if (str[i] == '.')
		result = result + ft_decimal_part(&str[i + 1]);
	return (sign * result);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (str == 0)
		return (-1);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	i;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (sign * result);
}
