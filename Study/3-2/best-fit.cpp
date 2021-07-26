#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector < ll > process, block;
vector < bool > mark;
vector < ll > allocated;

int main()
{
	ll np, nb;

	cout << "Enter number of block: ";
	cin >> nb;

	cout << "Enter number of Process: ";
	cin >> np;

	process.resize(np);
	allocated.resize(np);
	block.resize(nb);

	cout << "Enter the block sizes: ";

	for(auto &it: block) cin >> it;

	cout << "Enter the process requests: ";

	for(auto &it: process) cin >> it;

	mark.assign(nb,1);

	for(ll i = 0; i < np; i++)
	{
		ll low = 1LL << 40;

		for(ll j = 0; j < nb; j++)
		{
			if(mark[j] &&  process[i] <= block[j])
			{
				low = min(low, block[j]);

				if(low == block[j])
				{
					allocated[i] = j;
				}
			}
		}

		if(low == (1LL << 40)) allocated[i] = -1;
		else mark[allocated[i]] = 0;
	}

	for(ll i = 0; i < np; i++)
	{
		if(allocated[i] != -1) cout << "Process " << i + 1 << " has assigned to the block: " << allocated[i] + 1 << endl;
		else cout << "We could not allocated the Process " << i + 1 << endl;
	}

	return 0;


}

