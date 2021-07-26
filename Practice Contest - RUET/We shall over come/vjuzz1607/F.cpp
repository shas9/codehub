#include <bits/stdc++.h>

#define scanlld(longvalue) scanf("%lld", &longvalue)
#define printlld(longvalue) printf("%lld", longvalue)

#define printnewline printf("\n")

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

using namespace std;
long long int Mod = 10000007;
long long int expo(long long int num, long long int power)
{
	long long int flag;
	if(power == 0)
	{
		return 1;
	}
	else if(power % 2 == 0)
	{
		flag  = expo(num, power / 2);
		return (((flag % Mod) * (flag % Mod)) % Mod)
	}
	else
	{
		return (((num % Mod) * (expo(num, power - 1) % Mod)) % Mod);
	}
}

int main()
{
	long long int n, k, ans;

	while(1)
	{
		scanlld(n);
		scanlld(k);

		if(n == 0 && k == 0)
		{
			break;
		}

		if(n == 2)
		{
			ans = 8;
			printnewline(ans);
			printnewline;
		}
		else
		{
			ans = (((expo(n,k) % Mod) + ((2 * expo(n-1,k)) % Mod)) % Mod);
			ans = (((ans % Mod) + (expo(n,n) % Mod)) % Mod);
			ans = (((ans % Mod) + ((2 * expo(n-1,n - 1)) % Mod)) % Mod);

			printlld(ans);
			printnewline;
		}
	}

	return 0;
}