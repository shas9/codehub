#include <bits/stdc++.h>

using namespace std;

int main()
{
	string input;

	int i = 0;

	while(1)
	{
		cin >> input;
		i++;

		if(input == "*")
		{
			return 0;
		}

		if(input == "Hajj")
		{
			printf("Case %d: Hajj-e-Akbar\n", i);
		}
		else
		{
			printf("Case %d: Hajj-e-Asghar\n", i);
		}
	}

	return 0;
}
