#include <bits/stdc++.h>

using namespace std;

int main()
{
	int array[10];

	int testcase;

	cin >> testcase;

	int i, j, k, l;

	int input;
	int temp;
	int flag;

	for(i = 1; i <= testcase; i++)
	{
		cin >> input;

		for(j = 1; j <= input; j++)
		{
			temp = j;
			while(1)
			{
				if(temp < 10)
				{
					array[temp]++;
					break;
				}
				flag = temp % 10;
				array[flag]++;
				temp = temp / 10;
			}
		}

		for(k = 0; k < 10; k++)
		{
			printf("%d ", array[k]);
		}

		printf("\n");
	}
}