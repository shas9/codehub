#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long int low, high;
	long long int max;
	long long int temp1, temp2;
	long long int div2, div3, div5, div7;

	cin >> low >> high;

	temp1 = low / 2;
	temp2 = high / 2;

	div2 = temp2 - temp1;

	temp1 = low / 3;
	temp2 = high / 3;

	div3 = temp2 - temp1;

	temp1 = low / 5;
	temp2 = high / 5;

	div5 = temp2 - temp1;

	temp1 = low / 7;
	temp2 = high / 7;

	div7 = temp2 - temp1;

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

