#include <bits/stdc++.h>

using namespace std;

int main()
{
	string input;

	long long int num;
	long long int ammount = 0;

	long long int operation;

	long long int i;

	cin >> operation;

	for(i = 0; i < operation; i++)
	{
		cin >> input;

		if(input == "donate")
		{
			cin >> num;
			ammount = ammount + num;
		}
		else
		{
			printf("%lld\n", ammount);
		}
	}

	return 0;
}