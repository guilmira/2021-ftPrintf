#include "ft_printf.h"

void advance_string(char **str, char *new_position)
{
	if (new_position)
		*str = new_position;
}

char	*get_flag_string(char *str)
{
	if (ft_strchr_plus(str, CONVERTERS))
		return (ft_substr(str, 0, ft_strchr_plus(str, CONVERTERS) - str));
	else
		return (NULL);
}

int main (void)
{
	char *str = "holaqeXeer";

	printf("%s\n", ft_strchr(str, 'X'));
	printf("%s\n", ft_strchr_plus(str, CONVERTERS));
	advance_string(&str, ft_strchr_plus(str, CONVERTERS) + 1);
	printf("%s\n", str);
}
