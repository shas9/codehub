#include <bits/stdc++.h>

using namespace std;

int binarysearch(int array[], int size, int number)
{
	int position;
	int high, mid, low;

	high = size;
	low = 0;
	mid = (high + low) / 2;

	while(low < high)
	{
		if(number == array[mid])
		{
			position = mid;
			break;
		}
		else if(number > array[mid])
		{
			low = mid + 1;
			mid = (high + low) / 2
		}
		else if(number < array[mid])
		{
			high = mid - 1;
			mid = (low + high) / 2;
		}
	}

	if(low >= high)
	{
		position == 0;
	}

	return position;
}