#include <bits/stdc++.h>

#define scanlld(longvalue) scanf("%lld", &longvalue)
#define printlld(longvalue) printf("%lld", longvalue)

#define printnewline printf("\n")

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

using namespace std;

bool numbers[100010];
int primes[10000];
void sieve()
{
	int i, j, k;

	for(i = 2; i < 400; i++)
	{
		if(numbers[i] == 0)
		{
			for(j = i * i; j <= 100009; j = j + i)
			{
				numbers[j] = 1;
			}
		}
	}

	j = 0;
	for(i = 2; i < 100010; i++)
	{
		if(numbers[i] == 0)
		{
			primes[j] = i;
			j++;
		}
	}
}

int main()
{
	int num = 2;
	int flag;
	int i, j, k, l;

	sieve();

	while(num <= 100000)
	{
		i = 0;
		printf("%d:",num);
		int flag = num;
		while(primes[i] <= num)
		{
		    if(flag <= 1)
            {
                break;
            }
			if(flag % primes[i] == 0)
			{
				printf(" %d", primes[i]);
				flag  = flag  / primes[i];

			}
			i++;
		}
		printnewline;
		num++;
	}

	return 0;
}
