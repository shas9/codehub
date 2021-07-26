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

	for(i = 4; i <= 100009; i = i + 2)
	{
	    numbers[i] = 1;
	}
	for(i = 3; i < 400; i = i + 2)
	{
		if(numbers[i] == 0)
		{
			for(j = i * i; j <= 100009; j = j + i + i)
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
			//printf("primes[j] = %d, j = %d\n", primes[j], j);
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
		while(primes[i] * primes[i] <= num)
		{
		    //printf("flag = %d, prime = %d\n", flag, primes[i]);
		    if(flag <= 1)
            {
                break;
            }
			if(flag % primes[i] == 0)
			{
				printf(" %d", primes[i]);
				while(flag % primes[i] == 0)
                {
                    flag  = flag  / primes[i];
                    if(flag <= 1)
                    {
                        break;
                    }
                }

			}
			i++;
		}
		if(flag > 1)
        {
            printf(" %d", flag);
        }
		printnewline;
		num++;
	}

	return 0;
}
