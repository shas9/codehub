#include <bits/stdc++.h>

using namespace std;

int main()
{
	int testcase;
	string line;

	vector < int > index;
	vector < string > value;

	int i, j, k, l;

	int num;
	string numd;

	cin >> testcase;

	int size;
	string garb;
	map < int, string > store;

	getline(cin, garb);

	for(i = 0; i < testcase; i++)
	{

	    if(i != 0)
        {
            printf("\n");
        }
        getline(cin, garb);
            getline(cin, line);
			stringstream ss ( line );

			while(ss >> num)
			{
				index.push_back( num );
			}



            getline(cin, line);
			stringstream tt ( line );

			while(tt >> numd)
			{
				value.push_back( numd );
			}

		//printf(".......\n");

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

			cout << numd << endl;
		}

		store.clear();
		index.clear();
		value.clear();


	}

	return 0;
}
