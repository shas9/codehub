#include <bits/stdc++.h>

using namespce std;

int main()
{
	int testcase;
	string line;

	vector < int > index;
	vector < double > value;

	int i, j, k, l;

	int num;
	double numd;

	cin >> testcase;

	int size;

	map < int, double > store;

	for(i = 0; i < testcase; i++)
	{
		while(getline(cin,line))
		{
			stringstream ss ( line );

			while(ss >> num)
			{
				index.push_back( num );
			}

		}

		while(getline(cin, line))
		{
			stringstream ss ( line );

			while(ss >> numd)
			{
				value.push_back( numd );
			}
		}

		size = index.size();

		for(j = 0; j < size; j++)
		{
			num = index[j];
			numd = value[j];

			store[num] = numd;
		}

		for(j = 1; j <= size; j++)
		{
			numd = store[j];

			printf("%.1lf\n", numd);
		}


	}

	return 0;
}