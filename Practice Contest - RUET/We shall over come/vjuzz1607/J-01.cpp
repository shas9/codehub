#include <bits/stdc++.h>

#define scanlld(longvalue) scanf("%lld", &longvalue)
#define printlld(longvalue) printf("%lld", longvalue)

#define printnewline printf("\n")

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

using namespace std;

bool numbers[90000010];
long long int primes[5000010];

void sieve()
{
	long long int i, j, k, l;

	for(i = 2; i <= 10000; i++)
	{
		if(numbers[i] == 0)
        {
            for(j = i * i; j <= 90000000; j = j + i)
            {
                numbers[j] = 1;
            }
        }
	}

	for(i = 2, j = 1; i < 90000000 && j < 5000010; i++)
	{
		if(numbers[i] == 0)
		{
			primes[j] = i;
			j++;
		}
	}

	//return;
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
