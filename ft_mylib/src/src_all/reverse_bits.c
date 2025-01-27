#include <unistd.h>
#include <stdio.h>

void	print_bits(unsigned char octet)
{
	int				i;
	unsigned char	bit;

	i = 8;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

unsigned char	reverse_bits(unsigned char octet)
{
	int				i;
	unsigned char	res;

	i = 8;
	res = 0;
	while (i--)
	{
		res = (res << 1) + (octet & 1);
		octet = octet >> 1;
	}
	return (res);
}
/*
int	main(void)
{
	unsigned char	octet;

	octet = 8;
	print_bits(octet);
	printf("(%d)", octet);
	printf("\n");
	print_bits(reverse_bits(octet));
	printf("(%d)", reverse_bits(octet));
	return (0);
}*/