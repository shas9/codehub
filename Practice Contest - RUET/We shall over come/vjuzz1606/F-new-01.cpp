#include <bits/stdc++.h>

using namespace std;

int main()
{
	int testcase;
	string course;
	int max;
	string garb;

	int i, j, k, l;
	string num;
	int count;
	int multi;
	int ans;
	vector < string > data;
	map < string, int > popular;

	string store;

	while(1)
	{
		cin >> testcase;
		max = 0;
		multi = 1;

		if(testcase == 0)
		{
			return 0;
		}
		getline(cin, garb);
		popular.clear();
		data.clear();
		max  = 0;
		multi = 1;

		for(i = 0; i < testcase; i++)
		{
		    data.clear();
			getline(cin, course);

			stringstream ss ( course );

			while( ss >> num)
			{
				data.push_back( num );
			}

			sort(data.begin(), data.end());

			store = data[0];

			for(j = 1; j < 5; j++)
            {
                store = store + data[j];
            }

            popular[store]++;

            count = popular[store];


            //cout << "string is: " << store << "count: " << count << endl;

            if(max == count)
            {
                multi++;
            }
            //cout << "multi: " << multi << endl;
            if(max < count)
            {
                max = count;
                multi = 1;
            }
            //cout << "max: " << max << endl;
		}
		//cout << "multi: " << multi << endl;
            if(max == 1)
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
