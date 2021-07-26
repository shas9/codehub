#include <bits/stdc++.h>

using namespace std;

int main()
{
	string i, j, k, l, m, n;

	map < string, int > store;
	string name;

	string input;
	string sorted;

	int count = 0;
	for(j = "a"; j <= "z"; j[0]++)
	{
		count++;
		name = j;
		store[name] = count;
	}
	for(i = "a"; i <= "y"; i[0]++)
	{
		for(j = i[0] + 1; j <= "z"; j[0]++)
		{
			count++;
			name = i+j;
			//cout << name << endl;
			store[name] = count;
		}
	}
	for(i = "a"; i <= "x"; i[0]++)
	{
		for(j = i[0] + 1; j <= "y"; j[0]++)
		{
			for(k = j[0] + 1; k <= "z";k[0]++)
			{
				count++;
				name = i+j+k;
				store[name] = count;
			}
		}
	}
	for(i = "a"; i <= "w"; i[0]++)
	{
		for(j = i[0] + 1; j <= "x"; j[0]++)
		{
			for(k = j[0] + 1; k <= "y";k[0]++)
			{
				for(l = k[0] + 1; l <= "z"; l[0]++)
				{
					count++;
					name = i+j+k+l;
					store[name] = count;
				}
			}
		}
	}
	for(i = "a"; i <= "v"; i[0]++)
	{
		for(j = i[0] + 1; j <= "w"; j[0]++)
		{
			for(k = j[0] + 1; k <= "x";k[0]++)
			{
				for(l = k[0] + 1; l <= "y"; l[0]++)
				{
					for(m = l[0] + 1; m <= "z"; m[0]++)
					{
						count++;
						name = i+j+k+l+m;
						store[name] = count;
					}
				}
			}
		}
	}

	//cin >> input;

	while(cin >> input)
    {
        name = input;
        cout << store[name] << endl;
    }

    return 0;


}
