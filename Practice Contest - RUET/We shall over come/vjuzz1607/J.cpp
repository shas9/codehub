#include <bits/stdc++.h>

#define scanlld(longvalue) scanf("%lld", &longvalue)
#define printlld(longvalue) printf("%lld", longvalue)

#define printnewline printf("\n")

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

using namespace std;

bool numbers[9000010];
long long int primes[500010]
void sieve()
{
	long long int i, j, k, l;

	for(i = 2; i <= 3000; i++)
	{
		for(j = i * i; j <= 9000000; j = j + i)
		{
			numbers[j] = 1;
		}
	}

	for(i = 2, j = 1; i < 9000000 && j < 500010; i++)
	{
		if(numbers[i] == 0)
		{
			primes[j] = i;
			j++;
		}
	}

	return;
}

int main()
{
	sieve();

	long long int input, testcase, i, j;

	scanlld(testcase);

	for(i = 0; i < testcase; i++)
	{
		scanlld(input);

		printlld(primes[input]);
		printnewline;
	}

	return 0;
}