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

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

struct line
{
	ll m, c;

	line(ll x, ll y)
	{
		m = x;
		c = y;
	}
};

vector < line > vec[4];

ll func(ll idx, ll idx1, ll x)
{
	ll ret = vec[idx][idx1].m * x + vec[idx][idx1].c;

	return ret;
}

bool bad1(line f1, line f2, line f3)
{
	__int128 a = (f3.c - f1.c);
	a = a * (f1.m - f3.m);

	__int128 b = (f2.c - f1.c);
	b = b * (f1.m - f2.m);

	return a <= b;
}

void add1(line x) //mi <= mi+1 && min(x)
{
	ll sz = vec[0].size() - 1;

	while(sz >= 1 && bad1(vec[0][sz - 1], vec[0][sz], x))
	{
		vec[0].pop_back();
		sz--;
	}

	vec[0].push_back(x);
}

ll ask1(ll x)
{
//	assert(0);
	ll lo = 0;
	ll hi = vec[0].size() - 1;

	ll ret = mxlld;

	while(lo <= hi)
	{
		ll mid1 = (lo + (hi - lo) / 3);
		ll mid2 = (hi - (hi - lo) / 3);

		ll ans1 = func(0,mid1,x);
		ll ans2 = func(0,mid2,x);

		if(ans1 < ans2)
		{
			ret = min(ret, ans1);
			hi = mid2 - 1;
		}
		else
		{
			ret = min(ret,ans2);
			lo = mid1 + 1;
		}
	}

	return ret;
}

bool bad2(line f1, line f2, line f3)
{
	__int128 a = (f3.c - f1.c);
	a = a * (f1.m - f3.m);

	__int128 b = (f2.c - f1.c);
	b = b * (f1.m - f2.m);

	return a >= b;
}

void add2(line x) //mi <= mi+1 && max(x)
{
	ll sz = vec[1].size() - 1;

	while(sz >= 1 && bad2(vec[1][sz - 1], vec[1][sz], x))
	{
		vec[1].pop_back();
		sz--;
	}

	vec[1].push_back(x);
}

ll ask2(ll x)
{
//	assert(0);
	ll lo = 0;
	ll hi = vec[1].size() - 1;

	ll ret = mnlld;

	while(lo <= hi)
	{
		ll mid1 = (lo + (hi - lo) / 3);
		ll mid2 = (hi - (hi - lo) / 3);

		ll ans1 = func(1,mid1,x);
		ll ans2 = func(1,mid2,x);

		if(ans1 > ans2)
		{
			ret = max(ret, ans1);
			hi = mid2 - 1;
		}
		else
		{
			ret = max(ret,ans2);
			lo = mid1 + 1;
		}
	}

	return ret;
}

bool bad3(line f1, line f2, line f3)
{
	__int128 a = (f3.c - f1.c);
	a = a * (f1.m - f3.m);

	__int128 b = (f2.c - f1.c);
	b = b * (f1.m - f2.m);

	return a >= b;
}

void add3(line x) //mi >= mi+1 && min(x)
{
	ll sz = vec[2].size() - 1;

	while(sz >= 1 && bad3(vec[2][sz - 1], vec[2][sz], x))
	{
		vec[2].pop_back();
		sz--;
	}

	vec[2].push_back(x);
}

ll ask3(ll x)
{
//	assert(0);
	ll lo = 0;
	ll hi = vec[2].size() - 1;

	ll ret = mxlld;

	while(lo <= hi)
	{
		ll mid1 = (lo + (hi - lo) / 3);
		ll mid2 = (hi - (hi - lo) / 3);

		ll ans1 = func(2,mid1,x);
		ll ans2 = func(2,mid2,x);

		if(ans1 < ans2)
		{
			ret = min(ret, ans1);
			hi = mid2 - 1;
		}
		else
		{
			ret = min(ret,ans2);
			lo = mid1 + 1;
		}
	}

	return ret;
}

bool bad4(line f1, line f2, line f3)
{
	__int128 a = (f3.c - f1.c);
	a = a * (f1.m - f3.m);

	__int128 b = (f2.c - f1.c);
	b = b * (f1.m - f2.m);

	return a <= b;
}

void add4(line x) //mi >= mi+1 && max(x)
{
	ll sz = vec[3].size() - 1;

	while(sz >= 1 && bad4(vec[3][sz - 1], vec[3][sz], x))
	{
		vec[3].pop_back();
		sz--;
	}

	vec[3].push_back(x);
}

ll ask4(ll x)
{
//	assert(0);
	ll lo = 0;
	ll hi = vec[3].size() - 1;

	ll ret = mnlld;

	while(lo <= hi)
	{
		ll mid1 = (lo + (hi - lo) / 3);
		ll mid2 = (hi - (hi - lo) / 3);

		ll ans1 = func(3,mid1,x);
		ll ans2 = func(3,mid2,x);

		if(ans1 > ans2)
		{
			ret = max(ret, ans1);
			hi = mid2 - 1;
		}
		else
		{
			ret = max(ret,ans2);
			lo = mid1 + 1;
		}
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

    while(cin >> n >> m)
    {
		for(ll i = 0; i < 4; i++) vec[i].clear();

		for(ll i = 1; i <= n; i++)
		{
			ll t, x, c;

			slld(t);

			if(t == 1)
			{
				slld(x);
				slld(c);

				if(m == 1) add1(line(x,c));
				else if(m == 2) add2(line(x,c));
				else if(m == 3) add3(line(x,c));
				else if(m == 4) add4(line(x,c));
				else assert(0);
			}
			else
			{
				slld(x);

				if(m == 1) ans = ask1(x);
				else if(m == 2) ans = ask2(x);
				else if(m == 3) ans = ask3(x);
				else if(m == 4) ans = ask4(x);
				else assert(0);

				printf("%lld\n", ans);
			}
		}
    }


}

