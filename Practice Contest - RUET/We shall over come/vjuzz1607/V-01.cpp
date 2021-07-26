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

	//sort(array.begin(),array.end());

	for(i = 1; i <= queries; i++)
	{
		scanlld(input);
		low = 0;
		high = sizeofarray - 1;
		mid = (low + high) / 2;

		while(1)
		{
		    if(low > high)
            {
                printf("-1\n");
                break;
            }
			if(array[mid] == input)
			{
			    while(array[mid - 1] == input)
                {
                    mid--;
                }
                printlld(mid);
                printnewline;
                break;
			}
			if(array[mid] < input)
			{
				low = mid + 1;
				mid = (low + high) / 2;
			}
			else
			{
				high = mid - 1;
				mid = (low + high) / 2;
			}
		}
	}

	return 0;
}
