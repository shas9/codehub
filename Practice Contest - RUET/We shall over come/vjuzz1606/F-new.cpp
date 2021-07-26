#include <bits/stdc++.h>

using namespace std;

int main()
{
	int testcase;
	string course;
	int max;
	string garb;

	int i, j k, l;
	int num;
	int count;
	int multi;
	int ans;

	while(1)
	{
		cin >> testcase;
		max = 0;
		multi = 1;

		if(testcase == 0)
		{
			return 0;
		}

		vector < int > data[testcase];

		for(i = 0; i < testcase; i++)
		{
			getline(cin, garb);

			getline(cin, course);

			stringstream ss ( course );

			while( ss >> num)
			{
				data[i].push_back( num );
			}

			sort(data[i].begin(), data[i].end());
		}

		for(i = 0; i < testcase - 1; i++)
		{
			count = 0;
			for(j = i + 1; j < testcase; j++)
			{
				if(data[i] == data[j])
				{
					count++
				}
			}

			if(max == count)
			{
				multi++:
			}

			if(max < count)
			{
				max = count;
				multi = 1;
			}
			
		}

		if(max = 1)
		{
			ans = testcase;
		}
		else
		{
			ans = multi * max;
		}

		cout << ans << endl;
	}

	return 0;
}