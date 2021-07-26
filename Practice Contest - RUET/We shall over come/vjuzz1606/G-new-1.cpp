#include <bits/stdc++.h>

using namespace std;

long long int max(long long int x, long long int y)
{
    if(x >= y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

int main()
{
	map < long long int, long long int > snow;
	long long int count;
	//long long int max;

	long long int flag;
	long long int testcase;
	long long int snowflakes;

	long long int tag;
	long long int i, j, k, l, m;

	long long int input;
	long long int result;
	long long int ans;

	cin >> testcase;

	for(i = 0; i < testcase; i++)
	{

        cin >> snowflakes;
		count = 0;
		flag = 0;
		result = 0;
		ans = 0;
		tag = 0;

		snow.clear();


		for(j = 1; j <= snowflakes; j++)
		{
			cin >> input;

			tag = snow[input];

			if(tag != 0)
            {
                flag = max(flag,tag);
                count = j - flag - 1;
            }

            count++;
            snow[input] = j;
            ans = max(count, ans);

		}

		cout << ans << endl;
	}

	return 0;
}
