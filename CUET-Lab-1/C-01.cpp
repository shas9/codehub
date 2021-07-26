#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long int low, high;
	long long int max;
	long long int temp1, temp2;
	long long int div2, div3, div5, div7;

	cin >> low >> high;

	if(low == high)
    {
        printf("%d\n", low);
        return 0;
    }

	temp1 = low / 2;
	temp2 = high / 2;
	div2 = temp2 - temp1;

	if(low % 2 == 0)
    {
        div2++;
    }
    if(high % 2 == 0)
    {
        div2++;
    }

	temp1 = low / 3;
	temp2 = high / 3;

	div3 = temp2 - temp1;
	if(low % 3 == 0)
    {
        div3++;
    }
    if(high % 3 == 0)
    {
        div3++;
    }

	temp1 = low / 5;
	temp2 = high / 5;

	div5 = temp2 - temp1;
	if(low % 5 == 0)
    {
        div5++;
    }
    if(high % 5 == 0)
    {
        div5++;
    }

	temp1 = low / 7;
	temp2 = high / 7;

	div7 = temp2 - temp1;
	if(low % 7 == 0)
    {
        div7++;
    }
    if(high % 7 == 0)
    {
        div7++;
    }
    //printf("DBUG: div2= %lld, div3 = %lld, div5 = %lld, div7 = %lld\n", div2, div3, div5, div7);

	max = 2;

	if(div2 < div3)
	{
		max = 3;
	}
	if((div5 > div2) && (div5 > div3))
	{
		max = 5;
	}
	if((div7 > div2) && (div7 > div5) && (div7 > div3))
	{
		max = 7;
	}

	printf("%lld\n", max);

}


