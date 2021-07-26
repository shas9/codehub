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

#define mod 1000000009


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

vector < ll > vec;
ll ans_i[1000006];
ll realans[1000006];
bool allsame[1000006];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	while(cin >> n)
    {
		vec.clear();
		for(i = 0; i < n; i++) ans_i[i] = realans[i] = 0, allsame[i] = 0;

		ll t, s;
		ll sz = 0;

		for(i = 0; i < n; i++)
		{
			slld(t);

			if(sz && t == 2) vec.pop_back(), sz--;
			else
			{
				slld(s);

				vec.push_back(s);

				sz++;

				if(sz > 1 && ans[sz - 2] == realans[sz - 2])
				{
					ll x = ans[sz - 2];

					ll lpos = sz - 2 - x + 1;

					if(lpos > 0)
					{
						if(vec[lpos - 1] == vec[sz - 1])
						{
							ans[sz - 1] = ans[sz - 2] + 2;
							realans[sz - 1] = max(realans[sz - 2], ans[sz - 1]);
							continue;
						}
					}
				}
			}
		}
    }


}


