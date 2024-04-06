#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * prime_factor - attempt to find a prime factor of n by trial division
 * @n: number to factorize
 * Return: nothing
 */

void prime_factor(unsigned int long long n)
{
	unsigned int long long root = sqrt(n);
	unsigned int long long divisor;

	if (n % 2 == 0)
		printf("%llu=%llu*2\n", n, n / 2);
	for (divisor = 3; divisor <= root; divisor += 2)
	{
		if (n % divisor == 0)
			printf("%llu=%llu*%llu\n", n, n / divisor, divisor);
	}
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
		prime_factor(count);
	fclose(file);
	return (0);
}
