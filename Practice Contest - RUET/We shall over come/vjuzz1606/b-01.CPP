#include <bits/stdc++.h>

using namespace std;

int main()
{
	int size;

	int i, j, k, l, m;

	int input;
	int low;
	int flag;
	int templow;

	queue < int > store;

	while(1)
	{
		cin >> size;

		if(size == 0)
		{
			return 0;
		}

		while(1)
		{
			cin >> input;
			if(input == 0)
			{
			    printf("\n");
				break;
			}
			store.push ( input );
			if(size > 1)
			{
				for(i = 1; i < size; i++)
				{
					cin >> input;
					store.push ( input );
				}
			}
			low = 1;
			int tag = 1;

			while(!store.empty())
			{
				flag = store.front();
				templow = flag + 1;
				while(1)
				{
					if(flag == low)
					{
						if(store.front() != flag)
						{
							break;
							tag = 0;
						}
						else
						{
							store.pop();
							break;
						}
					}
					store.pop();
					flag--;
					//cout << "flag = " << flag << " store = " << store.front() << endl;
					if(store.front() != flag)
					{
						tag = 0;
						//cout << "tag = " << tag << endl;
						break;
					}
				}
				low = templow;
			    if(tag == 0)
			    {
			    	printf("No\n");
			    	break;
			    }
			}
			if(tag == 1)
			{
				printf("Yes\n");
			}
			while( !store.empty())
			{
				store.pop();
			}
		}


	}
}
