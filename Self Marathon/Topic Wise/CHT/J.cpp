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

struct CHT
{
	vector < line > vec;
	ll t, ptr;

	void init(ll x)
	{
		t = x;
		ptr = 0;
		vec.clear();
	}

	inline ll func(ll idx, ll x)
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
			return 0;
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

    ll ask1(ll x) // pointer search (linear)
    {
		if(vec.empty())
		{
			return 0;
		}

		if(ptr >= vec.size()) ptr = vec.size() - 1;

		while(ptr < (vec.size() - 1))
		{
			if(t & 1)
			{
				if(func(ptr,x) > func(ptr + 1,x))
				{
					ptr++;
				}
				else break;
			}
			else
			{
				if(func(ptr,x) < func(ptr + 1,x))
				{
					ptr++;
				}
				else break;
			}
		}

		return func(ptr,x);
    }
};

// 1 = mi > mi+1, mn
// 2 = mi > mi+1, mx
// 3 = mi < mi+1, mn
// 4 = mi < mi+1, mx

ll arr[1000006];
ll dp[1000006];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		CHT cht;

		cht.init(1);

		for(i = 1; i <= n; i++)
		{
			slld(arr[i]);
		}

		dp[0] = 0;

//		for(ll i = 1; i <= n; i++)
//		{
//			dp[i] = dp[i - 1] + m;
//
//			for(ll j = 0; j < i; j++)
//			{
//				dp[i] = min(dp[i], dp[j] + (arr[i] - arr[j + 1]) * (arr[i] - arr[j + 1]) + m);
//			}
//		}

//		cout << dp[n] << endl;

		cht.add(line(0,0));

		for(i = 0; i <= n; i++)
		{
			if(i == 1) dp[i] = m;

			if(i > 1) dp[i] = cht.ask1(arr[i]) + (arr[i] * arr[i]) + m;

//			cout << i << ": " << dp[i] << endl;

			cht.add(line(-2 * arr[i + 1], dp[i] + (arr[i + 1] * arr[i + 1])));
		}

		printf("%lld\n", dp[n]);
    }

}



