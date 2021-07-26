#include <bits/stdc++.h>

#define scanlld(longvalue) scanf("%lld", &longvalue)
#define printlld(longvalue) printf("%lld", longvalue)

#define printnewline printf("\n")

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

using namespace std;

long long int factorial(long long int num, long long int mod)
{
	long long int flag;
	if(num == 1)
	{
		return 1;
	}
	else
	{
		flag = factorial(num -1, tag);

		return (((num % mod) * (flag % mod)) % mod);
	}
}

int main()
{
	long long int testcase, prime, number, ans;

	scanlld(testcase);

	long long int i, j, k, l;

	for(i = 1; i <= testcase; i++)
	{
		scanlld(number);
		scanlld(prime);

		ans = factorial(number, prime);

		printlld(ans);
		printnewline;
	}

	return 0;
}