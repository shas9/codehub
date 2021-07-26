#include <bits/stdc++.h>

using namespace std;

int main()
{
	set < string > dic;

	char input[200];
	char temp[200];

	int lntemp;

	int ln;
	int i, j, k, l, m, n, o, p;

	int flag;

	set < string > :: iterator it;

	while(scanf("%s", input) != EOF)
	{
		flag = 0;
		for(ln = 0; input[ln] != '\0'; ln++);

		for(i = ln - 1; i >= 0; i--)
		{
			if(input[i] >= 'A' && input[i] <= 'Z')
			{
				input[i] = input[i] + (97 - 65);
			}
			else if(input[i] >= 'a' && input[i] <= 'z');
			else
			{
				for(m = i + 1, n = 0; input[m] != '\0'; m++, n++)
				{
					temp[n] = input[m];
				}
				
				temp[n] = '\0';
				if(temp[0] != ' ' && temp[0] != '\0')
				{
					dic.insert(temp);
				}
					input[i] = '\0';
					temp[0] = '\0';
			}
		}
		dic.insert(input);
	}

	for(it = dic.begin(); it != dic.end(); it++)
	{
		cout << *it << endl;
	}

	return 0;
}
