// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

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

ll arr[103];
bool swapped[103];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);
		memset(swapped,0,sizeof swapped);

		for(i = 1; i <= n; i++) slld(arr[i]);

		for(i = 1; i <= n; i++)
		{
			bool on = 1;
			for(j = 1; j <= n && on; j++)
			{
				for(k = 1; k <= n; k++)
				{
					if(arr[k] == i)
					{
						if(k == 1 || arr[k - 1] < arr[k] || swapped[k - 1])
						{
							on = 0;
							break;
						}

						swapped[k - 1] = 1;
						swap(arr[k], arr[k - 1]);
						break;
					}
				}
			}
		}

		for(i = 1; i <= n; i++) printf("%lld ", arr[i]);

		printf("\n");
    }


}



