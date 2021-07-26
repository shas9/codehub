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


// 1 = mi > mi+1, mn
// 2 = mi > mi+1, mx
// 3 = mi < mi+1, mn
// 4 = mi < mi+1, mx

struct CHT
{
	vector < line > vec;
	ll t;

	void init(ll x)
	{
		t = x;
		vec.clear();
	}

	ll func(ll idx, ll x)
	{
		ll ret = vec[idx].m * x + vec[idx].c;

		return ret;
	}

    bool bad(line f1, line f2, line f3)
    {
        __int128 a = (f3.c - f1.c);
        a = a * (f1.m - f2.m);

        __int128 b = (f2.c - f1.c);
        b = b * (f1.m - f3.m);

        if(t == 1) return a <= b;
        if(t == 2) return a >= b;
        if(t == 3) return a >= b;
        if(t == 4) return a <= b;

        assert(0);
    }

    void add(line x)
    {
        ll sz = vec.size();

        while(sz >= 2 && bad(vec[sz - 2], vec[sz - 1], x))
        {
            vec.pop_back();
            sz--;
        }

        vec.push_back(x);
    }

    ll ask(ll x) // ternary search
    {
		if(vec.empty())
		{
			add(line(0,0));
		}

        ll lo = 0;
        ll hi = vec.size() - 1;

        ll ret = (t & 1)? mxlld : mnlld;

        while(lo <= hi)
        {
            ll mid1 = (lo + (hi - lo) / 3);
            ll mid2 = (hi - (hi - lo) / 3);

            ll ans1 = func(mid1,x);
            ll ans2 = func(mid2,x);

            if(ans1 > ans2)
            {
                if(t & 1)
                {
					ret = min(ret, ans2);
					lo = mid1 + 1;
                }
                else
                {
					ret = max(ret, ans1);
					hi = mid2 - 1;
                }
            }
            else
            {
                if(t & 1)
                {
					ret =  min(ret,ans1);
					hi = mid2 - 1;
                }
                else
                {
					ret = max(ret,ans2);
					lo = mid1 + 1;
                }
            }
        }

        return ret;
    }
};

ll arr[200005];
ll xx[200005];
ll yy[200005];


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	while(cin >> n)
	{
		for(ll i = 1; i <= n; i++) slld(arr[i]);

		for(ll i = 1; i <= n; i++)
		{
			xx[i] = arr[i] + xx[i - 1];
			yy[i] = (i * arr[i]) + yy[i - 1];
		}

		CHT cht;

		cht.init(2);

		ans = 0;

		for(ll i = 1; i <= n; i++)
		{
			ans = max(ans, cht.ask(xx[i]) + yy[i]);

			cht.add(line(-i, i * xx[i] - yy[i]));
		}

		printf("%lld\n", ans);
	}


}


