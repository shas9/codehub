#include <bits/stdc++.h>

using namespace std;
int numbers[10000];
int primes [1500];

int main()
{
	int testcases;
	int input;

	int i, j, k, l, m;

	for(i = 0; i < 10000; i++)
	{
		numbers[i] = 1;
	}

	for(i = 2; i <= 100; i++)
	{
		if(numbers[i])
		for(j = i + i; j < 10000; j = j + i)
		{
			if(numbers[j])
			{
				numbers[j] = 0;
			}
		}
	}

	for(i = 0, j = 0; i < 1500 && j < 10000; i++, j++)
	{
		if(numbers[j])
		{
			primes[i] = j;
		}
	}

	for(i = 0; i < 1500; i++)
	{
		cout << primes[i] << endl;
	}
}