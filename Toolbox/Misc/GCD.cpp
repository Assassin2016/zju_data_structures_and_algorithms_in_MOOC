/**
 * Greatest common divisor
 * (Euclidean algorithm)
 */
#include <cstdio>

int gcd(int a, int b)
{
	return !b ? a : gcd(b, a % b);
}

int main()
{
	int m, n;

	while (scanf("%d%d", &m, &n) != EOF)
		printf("%d\n", gcd(m, n));

	return 0;
}

