#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long int testcase, prime, number, ans;

	scanf("%lld", &testcase);

	long long int i, j, k, l;

	for(i = 1; i <= testcase; i++)
	{
		scanf("%lld %lld", &number, &prime);
		ans = 1;
		j = 2;
		while(j <= number)
        {
            ans = (((ans % prime) * (j % prime)) % prime);
            j++;
        }

		printf("%lld\n", ans);
	}

	return 0;
}
