#include <bits/stdc++.h>

using namespace std;

int main()
{
	stack < int > train;
	int couch;
	int input;


	int i, j, k, l;


	while(1)
	{
		cin >> couch;
		if(couch == 0)
		{
			return 0;
		}

		while(1)
		{
			while(!train.empty())
			{
				train.pop();
			}
			j = 0;
			for(i = 0; i < couch; i++)
			{
				cin >> input;

				if(input == 0)
				{
					break;
				}

				if(j < input)
				{
					while(j < input)
					{
						j++;
						train.push( j );
					}
				}
				if(train.top() == input)
				{
					train.pop();
				}
				//cout << train.size() << endl;
			}
			if(j == 0)
            {
                break;
            }
			if(train.size() == 0)
			{
				printf("Yes\n");
			}
			else
			{
				printf("No\n");
			}
		}
		printf("\n");
	}
}

