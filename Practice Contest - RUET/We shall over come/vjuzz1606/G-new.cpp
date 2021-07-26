#include <bits/stdc++.h>

using namespace std;

int main()
{
	map < int, int > snow;
	int count;
	int max;

	int flag;
	int testcase;
	int snowflakes;

	int tag;
	int i, j, k, l, m;

	int input;
	int vsize;

	cin >> testcase;

	for(i = 0; i < testcase; i++)
	{
		cin >> snowflakes;
		max  = 0;
		count = 0;

		for(j = 0; j < snowflakes; j++)
		{
			cin >> input;
			if(snow[input] == 1)
			{
				if(max < count)
				{
					max = count;
				}
				count = 0;
				snow.clear();
				snow[input]++;
			}
			else
			{
				snow[input]++;
				count++;
			}
		}
		if(max < count)
		{
			max = count;
		}
		snow.clear();
		cout << max << endl;
	}

	return 0;
}