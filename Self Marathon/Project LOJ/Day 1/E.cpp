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

ll arr[100];
vector < ll > part[2];

void gen(ll st, ll pos, ll lim, ll sum)
{
	if(pos > lim)
	{
		part[st].push_back(sum);

		return;
	}

	for(ll i = 0; i <= 2; i++)
	{
		gen(st,pos + 1, lim, sum + (arr[pos] * i));
	}
}
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
		slld(m);

		for(i = 1; i <= n; i++)
		{
			slld(arr[i]);
		}

		ll half = n / 2;

		part[1].clear();
		part[0].clear();

		part[1].push_back(0);
		part[0].push_back(0);

		gen(0,1,half,0);
		gen(1,half + 1, n,0);

		sort(part[0].begin(), part[0].end());

		bool yes = 0;

//		for(auto it: part[0]) cout << it << " ";
//		cout << endl;
//
//		for(auto it: part[1]) cout << it << " ";
//		cout << endl;

		for(auto it: part[1])
		{
			ll lo = 0;
			ll hi = part[0].size() - 1;
			ll need = m - it;

//			cout << need << " " << it << endl;

			while(lo <= hi && yes == 0)
			{
				ll mid = (lo + hi) / 2;

				if(part[0][mid] == need)
				{
					yes = 1;
					break;
				}

				if(part[0][mid] > need)
				{
					hi = mid - 1;
				}
				else
				{
					lo = mid + 1;
				}
			}

			if(yes == 1) break;
		}

		if(yes) printf("Case %lld: Yes\n", cs);
		else printf("Case %lld: No\n", cs);
    }


}


