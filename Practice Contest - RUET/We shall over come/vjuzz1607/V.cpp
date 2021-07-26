#include <bits/stdc++.h>

#define scanlld(longvalue) scanf("%lld", &longvalue)
#define printlld(longvalue) printf("%lld", longvalue)

#define printnewline printf("\n")

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

using namespace std;

int main()
{
	long long int sizeofarray, queries, input;
	long long int i, j, k, l, m, n;
	long long int low, high, mid;

	scanlld(sizeofarray);
	scanlld(queries);

	std::vector<long long int> array;

	for(i = 1; i <= sizeofarray; i++)
	{
		scanlld(input);
		array.push_back( input );
	}

	sort(array.begin(),array.end());

	for(i = 1; i <= queries; i++)
	{
		scanlld(input);
		low = 0;
		high = sizeofarray - 1;
		mid = (low + high) / 2;

		while(1)
		{
			if(mid == input)
			{
				break;
			}
			if(mid > input)
			{
				low = mid + 1;
				mid = (high + low) / 2;
			}
			else
			{
				high = mid - 1;
				mid = (high + low) / 2;
			}
		}

		printlld(mid)
	}

	return 0
}