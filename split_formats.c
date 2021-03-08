#include "../ft_printf.h"

int   count_format(char *str)
{
    int i;
    int count;
  
    i = 0;
    count = 0;
    while (str[i])
    {
            if (str[i] == '%')
            {
                    count++;
                    if (str[i + 1] == '%')
                            i++;
            }
            i++;
    }
    return (count);
}

//Faire en sorte de copier ce qui est apres le % pour gerer le cas %
char    *ft_format_dup(char *str)
{
        char  *copy;
        int i;
	
	i = 0;
        while (str[i] && (correct_type(str[i]) != 1))
		i++;
        if (!(copy = (char *)malloc(sizeof(char) * (i + 2))))
                return (NULL);
        i = 0;
        //Condition a faire 
        while (str[i] && !(correct_type(str[i])))
        {
                copy[i] = str[i];
                i++;
        }
        copy[i] = str[i];
        i++;
        copy[i] = '\0';
        return (copy);
}

char **split_format(char *str)
{
	char **strs;
	int formats_number;
	int i;
	int j;

	if (!(str))
		exit (1);
	formats_number = count_format(str);
	if (!(strs = (char **)malloc(sizeof(char *) * (formats_number + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (!(str[i] == '%')) && str[i])
			i++;
		if (str[i] == '%')
		{
			strs[j] = ft_format_dup(str + i);
			printf("%s\n, strs[j]);
			j++;
		}
		i++;
	}
	strs[++j] = NULL;
	printf("%s\n", strs[j]);
	printf("%s\n", j);
	return (strs);
}			       
