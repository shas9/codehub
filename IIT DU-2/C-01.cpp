#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long int a, b;
	long long int ans, flag;

	int i, j, k, l;

	int testcase;

	scanf("%d", &testcase);

	for(i = 0; i < testcase; i++)
	{
		scanf("%lld%lld", &a, &b);

        if(b == 0)
        {
            printf("Impossible\n");
        }
		else
		{
		    if(a % b == 0)
            {
                ans = a / b;
                printf("%lld\n", ans);
            }
			else
			{
			    if(a == 0)
                {
                    printf("0\n");
                }

				else
				{
				    if(a < b)
                    {
                        printf("( %lld / %lld )\n", a, b);
                    }
					else
                    {
                        ans = a / b;
                        flag = a % b;

                         printf("%lld ( %lld / %lld )\n", ans, flag, b);
                    }
				}
			}
		}
	}
	return 0;
}
