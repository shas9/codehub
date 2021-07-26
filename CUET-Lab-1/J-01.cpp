#include <bits/stdc++.h>

using namespace std;

int main()
{
	int input;
	int res;

	while(1)
	{
		cin >> input;
		if(input == 0)
		{
			return 0;
		}

		if(input <= 100)
		{
			res = 91;
		}
		else
		{
			res = input - 10;
		}

		printf("f91(%d) = %d\n", input, res);
	}

}
