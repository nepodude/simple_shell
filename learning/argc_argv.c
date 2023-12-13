#include <stdio.h>

int main(int ac, char **av)
{
	av++;
	while (*av)
	{
		char *s = *av;
		while (*s)
		{
			putchar(*s);
			s++;
		}
		av++;
		putchar('\n');
	}
	return (0);
}
