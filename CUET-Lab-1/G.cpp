#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long int expon;

	long long int case;

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

		while(1)
		{
			ans = 0;

			expon = pow(2,ans);

			if(expon >= input)
			{
				break;
			}
			ans++;
		}

		ans++;

		printf("Case %lldd: %lld\n", case, ans);
	}

	return 0;
}