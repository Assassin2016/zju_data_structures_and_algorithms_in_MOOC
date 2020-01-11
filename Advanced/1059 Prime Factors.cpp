/**
 * Sample input:
 * 97532468
 * -------------
 * Sample output:
 * 97532468=2^2*11*17*101*1291
 */
#include <cstdio>
#include <cmath>

const int maxn = 100010;
int prime[maxn], pNum = 0;
struct factor {
	int x, cnt;
} fac[10];	// 10 is enough for 32bit integer

bool is_prime(int n)
{
	if (n == 1)
		return false;
	int sqr = (int)sqrt(1.0 * n);
	for (int i = 2; i <= sqr; i++)
		if (n % i == 0)
			return false;
	return true;
}

void Find_Prime()
{
	for (int i = 1; i < maxn; i++)
		if (is_prime(i))
			prime[pNum++] = i;
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	Find_Prime();

	int n, num = 0;
	scanf("%d", &n);
	if (n == 1)
		printf("1=1");
	else {
		printf("%d=", n);
		int sqr = (int)sqrt(1.0 * n);
		// If there's a prime factor of n, then:
		//   1: all primes of n must be smaller than sqrt(n) or...
		//   2: there's only one prime larger than sqrt(n)
		for (int i = 0; i < pNum && prime[i] <= sqr; i++) {
			if (n % prime[i] == 0) {
				fac[num].x = prime[i];
				fac[num].cnt = 0;
				while (n % prime[i] == 0) {
					fac[num].cnt++;
					n /= prime[i];
				}
				num++;
			}
			if (n == 1) break;
		}
		if (n != 1) {
			fac[num].x = n;
			fac[num++].cnt = 1;
		}
		for (int i = 0; i < num; i++) {
			if (i > 0)
				printf("*");
			printf("%d", fac[i].x);
			if (fac[i].cnt > 1)
				printf("^%d", fac[i].cnt);
		}
	}
	return 0;
}

