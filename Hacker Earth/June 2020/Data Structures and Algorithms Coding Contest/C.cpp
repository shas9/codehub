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

void test()
{
	vector < ll > cnt[1001];
//	memset(cnt,0,sizeof cnt);

	for(ll i = 1; i <= 1000; i++)
	{
		for(ll j = i; j >= 1; j--)
		{
			if(i % j == 0 && (j & 1))
			{
				cout << i << ": " << j << endl;
				cnt[j].pb(i);
				break;
			}
		}
	}

	for(ll i = 1; i <= 1000; i += 2)
	{
		cout << i << ": " << cnt[i].size() << ": ";

		for(auto it: cnt[i])
		{
			cout << it << " ";
		}

		cout << endl;
	}
}

ll tot(ll mid, ll n)
{
	ll cnt = 1;

	while(mid * 2 <= n)
	{
		cnt++;

		mid *= 2;
	}

	return cnt;
}

ll fnd(ll n, ll cnt)
{
	ll ret = 0;

	ll lo = 1;
	ll hi = n;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		if(tot(mid, n) >= cnt)
		{
			ret = mid;
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}

	if(!(ret & 1)) ret--;

	return ret;
}
ll solve(ll n, ll m)
{
	ll ret = 0;
	for(ll cnt = 1; cnt <= 70; cnt++)
	{
		ll idx = fnd(n,cnt);

		idx = (idx + 1) / 2;

		idx = ((idx % m) * (idx % m)) % m;

		ret = (ret + idx) % m;
	}

	return ret;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//	test();

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);
		slld(m);

		ans = solve(n, m);

		printf("%lld\n", ans);
    }


}



