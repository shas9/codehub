#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long int size;
	cin >> size;
	long long int array[size];
	long long int query;
	long long int low, high;
	long long int sum;

	long long int i, j, k, l, m;

	for(i = 0; i < size; i++)
	{
		cin >> array[i];
	}

	cin >> query;

	for(i = 1; i < size; i++)
	{
		array[i] = array[i - 1] + array[i];
	}

	for(i = 0; i < query; i++)
	{
		cin >> i;
		cin >> j;

		if(i == j)
		{
			if(i != 0)
			{
				sum = array[i] - array[i - 1];
			}
			else
			{
				sum = array[0];
			}
		}
		else if(i == 0)
		{
			sum = array[j];
		}
		else
		{
			sum = array[j] - array[i - 1];
		}

		cout << sum;
	}

	return 0;

}