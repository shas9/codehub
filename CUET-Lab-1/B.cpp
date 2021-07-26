#include <bits/stdc++.h>

using namespace std;

int main()
{
	int size;

	int temp;

	vector < int > array;
	vector < int > sorted;

	int i, j, k, l;

	int input;

	int flip;

	while(cin >> size)
	{
		flip = 0;
		for(i = 0; i < size; i++)
		{
			cin >> input;
			array.push_back( input );
		}

		sorted = array;

		sort(sorted.begin(), sorted.end());

		if(sorted == array)
		{
			flip = 0;
		}
		else
		{
			for(j = 0; j < array.size(); j++)
			{
				if(array[j] != (j + 1))
				{
					flip++;
					l = array[j];
					temp = array[l - 1];

					array[j] = temp;
					array[l - 1] = l;
				}
			}
		}

		printf("Minimum exchange operations : %d\n", flip);
	}

}

