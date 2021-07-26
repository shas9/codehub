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

pll arr[10];

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
		for(i = 1; i <= 3; i++)
		{
			slld(arr[i].first);
			slld(arr[i].second);
		}

		ans = mxlld;

		for(i = 2; i <= 7; i++)
		{
			for(j = 2; j <= 7; j++)
			{
				for(k = 2; k <= 7; k++)
				{
					ll n1 = i / 2;
					ll n2 = j / 2;
					ll n3 = k / 2;

					if(n1 == n2 || n1 == n3 || n2 == n3) continue;

					pll x = arr[n1];
					pll y = arr[n2];
					pll z = arr[n3];

					if(i % 2) swap(x.first,x.second);
					if(j % 2) swap(y.first,y.second);
					if(k % 2) swap(z.first,z.second);

					ll area1 = max(x.first,max(y.first, z.first)) * (x.second + y.second + z.second);
					ll area2 = (max(x.first,y.first) + z.first) * max(z.second, (x.second + y.second));
//					ll area3 = max(x.first , y.first+z.first) * (x.second + max(y.second, z.second));

					ans = min(ans, min(area1,area2));
				}
			}
		}

		printf("%lld\n", ans);
    }


}



