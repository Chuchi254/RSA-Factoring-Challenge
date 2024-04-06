#include <stdio.h>
#include <stdlib.h>

/**
 * factorize - factorizes any number
 * @n: input
 * Return: nothing
 */

void factorize(unsigned int long long n)
{
	unsigned int long long divisor = 2;

	while (divisor * divisor <= n)
	{
		if (n % divisor == 0)
		{
			printf("%llu=%llu*%llu\n", n, n / divisor, divisor);
			return;
		}
		divisor++;
	}
	printf("%llu=1*%llu\n", n, n);
}

/**
 * main - handles file as input
 * @argc: number of argument
 * @argv: argument vector
 * Return: 0 Always
 */

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return (1);
	}
	FILE *file = fopen(argv[1], "r");

	if (file == NULL)
	{
		perror("Error opening file");
		return (1);
	}

	unsigned int long long count;

	while (fscanf(file, "%llu", &count) != EOF)
		factorize(count);
	fclose(file);
	return (0);
}
