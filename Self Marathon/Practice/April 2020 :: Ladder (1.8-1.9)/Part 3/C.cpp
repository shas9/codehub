// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 958585860497

#define base 2001487

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

char grid[1003][1003];

void conn(ll i, ll j)
{
	grid[i][j] = 'Y';
	grid[j][i] = 'Y';
}

ll point[100];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> k)
    {
		for(i = 1; i <= 1000; i++) for(j = 1; j <= 1000; j++) grid[i][j] = 'N';

		ll mxbit = 0;

		for(i = 0; i <= 30; i++) point[i] = 0;

		conn(1,3);

		ll node = 2;

		for(i = 30; i >= 0; i--)
		{
			if(check(k,i) == 0) continue;

			mxbit = max(mxbit, i);

			node++;

			if(i == mxbit)
			{
				for(j = 0; j < i; j++)
				{
					conn(node,node + 1);
					conn(node,node + 2);
					conn(node + 2,node + 3);
					conn(node + 1, node + 3);

					point[j] = node + 1;

					node += 3;
				}

				conn(node,2);
			}
			else
			{
				conn(node, point[i]);
				for(j = i + 1; j < mxbit; j++)
				{
					conn(node, node + 1);
					conn(node + 1, node + 2);
					node += 2;
				}

				conn(node, 2);
			}
		}

		assert(1 <= node && node <= 870);
		cout << node << "\n";

		for(i = 1; i <= node; i++)
		{
			for(j = 1; j <= node; j++)
			{
//				if(grid[i][j] == 'Y') cout << i << " " << j << endl;

				printf("%c", grid[i][j]);
			}

			printf("\n");
		}
    }


}


