#include <bits/stdc++.h>

using namespace std;

int main()
{
	set < long long int > snowflakes;

	long long int testcase;
	long long int counts;
	long long int input;
	long long int size;

	int i, j, k, l;

	cin >> testcase;

	for(i = 0; i < testcase; i++)
	{
		cin >> counts;
		for(j = 0; j < counts; j++)
		{
			cin >> input;
			snowflakes.insert( input );
		}

		size = snowflakes.size();

		cout << "out: " << size << endl;

		snowflakes.clear();
	}

	return 0;
}
