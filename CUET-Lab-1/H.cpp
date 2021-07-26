#include <bits/stdc++.h>

using namespace std;

int main()
{
	int bottle;

	cin >> bottle;

	int ans;
	int temp;
	int flag;

	ans = bottle;
	flag = 0;

	while(1)
	{
		temp = bottle % 3;

		if(temp == 0)
		{
			ans++;
		}
		else
		{
			flag = flag + temp;
			if(flag >= 3)
			{
				ans++;
				flag = flag - 3;
			}
		}

		bottle = bottle / 3;
		ans = ans + bottle;
		if(bottle < 3)
		{
			break;
		}
		else
		{
			ans++;
		}
	}
	if (flag == 2)
	{
		ans++;
	}

	printf("%d\n", ans);

	return 0;
}
