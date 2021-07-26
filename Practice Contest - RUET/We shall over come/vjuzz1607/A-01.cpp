#include <bits/stdc++.h>

using namespace std;

int main()
{
	int size = 10;
	int testcase = 10;

	set < int > resultset;
	int result;
	int distinct;

	int i, j, k, l;
	int input;

	set < int > :: iterator it;

	for(i = 0; i < testcase; i++)
	{
	    resultset.clear();
		for(j = 0; j < size; j++)
		{
			cin >> input;
			result = input % 42;

			resultset.insert( result );
		}
		distinct = resultset.size();
		cout << distinct << endl;
	}

	return 0;
}
