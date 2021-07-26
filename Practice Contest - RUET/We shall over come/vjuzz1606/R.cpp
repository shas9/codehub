#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector < int > array;

	int testcase, i;

	cin >> testcase;

	int input;

	for(i = 0; i < testcase; i++)
	{
		cin >> input;
		array.push_back (input);
	}

	sort(array.begin(), array.end());

	for(int i=0; i<v.size(); i++) 
	{
		cout << v[i] << endl;
	}

	return 0;
}