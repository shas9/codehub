#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long int expon;

	long long int testcase;

	long long int input, i, match, ans;

	i = 0;

	while(1)
	{
		cin >> input;

		i++;

		if(input < 0)
		{
			return 0;
		}

		ans = 0;

		while(1)
		{

			expon = pow(2,ans);

			//printf("DBUG = %lld\n", expon);

			if(expon >= input)
			{
				break;
			}
			ans++;
		}

		ans;

		printf("Case %lld: %lld\n", i, ans);
	}

	return 0;
}
