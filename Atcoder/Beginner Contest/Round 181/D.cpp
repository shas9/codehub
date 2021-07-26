// God put a smile upon your face <3

#include <bits/stdc++.h>

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

using namespace std;

bool check(ll n, ll pos)
{
    return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
    return n = n | (1LL << pos);
}

string s;
ll cnt[15];

bool solve()
{
	if(s.size() == 1)
	{
		if(s == "8") return 1;

		return 0;
	}

	memset(cnt,0,sizeof cnt);

    for(auto it: s) cnt[it - '0']++;

	if(s.size() == 2)
	{
		for(ll i = 1; i < 100; i++)
		{
			if(i % 8 == 0)
			{
				ll cntt = 2;
				ll x = i;
				bool ok = 1;

				while(cntt--)
				{
					ll t = x % 10;
					x /= 10;

					cnt[t]--;

					if(cnt[t] < 0) ok = 0;
				}

				x = i;
				cntt = 2;

				while(cntt--)
				{
					ll t = x % 10;
					x /= 10;

					cnt[t]++;
				}

				if(ok == 1) return 1;
			}
		}

		return 0;
	}

    for(ll i = 1; i < 1000; i++)
    {
        if(i % 8 == 0)
        {
            ll cntt = 3;
            ll x = i;
            bool ok = 1;

            while(cntt--)
            {
                ll t = x % 10;
                x /= 10;

                cnt[t]--;

                if(cnt[t] < 0) ok = 0;
            }

            x = i;
            cntt = 3;

            while(cntt--)
            {
                ll t = x % 10;
                x /= 10;

                cnt[t]++;
            }

            if(ok == 1) return 1;
        }
    }

    return 0;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> s)
    {
        if(solve()) cout << "Yes\n";
        else cout << "No\n";
    }


}



