#include <bits/stdc++.h>

using namespace std;
int numbers[10000];
int primes [1200];

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
		for(j = i + i; j < 10000; j = j + i)
		{
			if(numbers[j] == 1)
			{
				numbers[j] = 0;
			}
		}
	}

	for(i = 0, j = 1; i < 1200 && j < 10000; j++)
	{
		if(numbers[j] == 1)
		{
			primes[i] = j;
			i++;
			//cout << j << endl;
		}
	}

	/*for(i = 0; i < 1200; i++)
	{
		cout << primes[i] << endl;
	}*/

	cin >> testcases;

	for(i = 0; i < testcases; i++)
    {
        if(i != 0)
        {
            printf("\n");
        }
        cin >> input;

        for(j = 0; primes[j] <= input; j++)
        {
            cout << primes[j] << endl;
        }
    }

    return 0;
}
