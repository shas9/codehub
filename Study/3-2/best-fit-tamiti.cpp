#include <bits/stdc++.h>

using namespace std;

int process[1005];
int blocks[1005];
bool mark[1005];
int position[1005];

int main()
{
	int np, nb, i, j;

	cout << "Enter number of block: ";
	cin >> nb;

	cout << "Enter number of Process: ";
	cin >> np;

	cout << "Enter the block sizes: ";

	for(i = 1; i <= nb; i++) cin >> blocks[i];

	cout << "Enter the process requests: ";

	for(i = 1; i <= np; i++) cin >> process[i];

	for(i = 1; i <= nb; i++) mark[i] = 1;

	for(i = 1; i <= np; i++)
	{
		int minimum = 1000000;

		for(j = 1; j <= nb; j++)
		{
			if(mark[j] == 1 &&  process[i] <= blocks[j])
			{
				minimum = min(minimum, blocks[j]);

				if(minimum == blocks[j])
				{
					position[i] = j;
				}
			}
		}

		mark[position[i]] = 0;
	}

	for(i = 1; i <= np; i++)
	{
		cout << "Process " << i << " has assigned to the block: ";

		if(position[i] == 0) cout << "NULL" << endl;
		else cout << position[i] << endl;
	}

	return 0;


}


