#include <bits/stdc++.h>

using namespace std;

int main()
{
	int i, j, k, l, m;

	int input;

	int temp;

	queue < int > value;
	int size;

	while(1)
	{
		cin >> input;

		if(input == 0)
		{
			return 0;
		}
		if(input == 1)
		{
			printf("Discarded cards:\n");
			printf("Remaining card: 1\n");
		}
		else
		{
			for(i = 1; i <= input; i++)
			{
				value.push( i );
			}

			size = value.size();

			printf("Discarded cards:");

			cout << " " << value.front();
			value.pop();
			size = value.size();
			if(size == 1)
			{
				cout << "\nRemaining card: " << value.front() << endl;
				value.pop();
			}
			else
			{
				while(size != 1)
				{
					temp = value.front();
					value.pop();

					value.push( temp );

					cout << ", " << value.front();
					value.pop();

					size = value.size();

					if(size == 1)
					{
						break;
					}

					
				}

				cout << "\nRemaining card: " << value.front() << endl;
				value.pop();
			}

		}
		
	}

	return 0;
}
