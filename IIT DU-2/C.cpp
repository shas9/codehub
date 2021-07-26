#include <bits/stc++.h>

using namespace std;

int main()
{
	long long int a, b;
	long long int ans, flag;

	int i, j, k, l;

	int testcase;

	cin >> testcase;

	for(i = 0; i < testcase; i++)
	{
		cin >> a;
		cin >> b;

		if(a % b == 0)
		{
			ans = a / b;
			cout << ans << endl;
		}
		else
		{
			if(b == 0)
			{
				cout << "( "<< a << " / " << b << " ) " << endl;
			}
			else if(a == 0)
			{
				cout << "0" << endl;
			}
			else
			{
				if(a < b)
				{
					cout << "( "<< a << " / " << b << " ) " << endl;
				}
				else
				{
					ans = a / b;
					flag = a % b;

					cout << ans << " ( " << flag << " / " << b << " ) " << endl;
				}
			}
		}
	}
	return 0;
}