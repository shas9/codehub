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
		assert(x == 1);
		t = x;
		ptr = 0;
		vec.clear();
	}

//	ll func(ll idx, ll x)
//	{
//		ll ret = vec[idx].m * x + vec[idx].c;
//	}

	ll f(int i, ll x) { return vec[i].m * x + vec[i].c; }

    bool bad(int f1, int f2, int f3)
    {
        return __int128(vec[f3].c - vec[f1].c) * (vec[f1].m - vec[f2].m) <=
        __int128(vec[f2].c - vec[f1].c) * (vec[f1].m - vec[f3].m);  // only for gnu g++
        // or compare by taking the answer in double :D
        // as double can *store* at most 10^300 (with precision error :p)
//        return 1.0 * (b[f3] - b[f1]) * (m[f1] - m[f2]) <=
//        1.0 * (b[f2] - b[f1]) * (m[f1] - m[f3]);
    }

    void add(line x)
    {
        vec.push_back(x); // push in CHT
        int sz = vec.size();
        // notice that f1 from discussion is in position sz - 3
        // f2 is in sz - 2, new line is in sz - 1
        while(sz >= 3 && bad(sz - 3, sz - 2, sz - 1))
        {
            vec.erase(vec.end() - 2); // remove f2's m
//            b.erase(b.end() - 2); // remove f2's b
            sz--; // size is decreased by 1
        } // we remove f2's while we can
    }

//    bool bad(line f1, line f2, line f3)
//    {
//        __int128 a = (f3.c - f1.c);
//        a = a * (f1.m - f2.m);
//
//        __int128 b = (f2.c - f1.c);
//        b = b * (f1.m - f3.m);
//
//        if(t == 1) return a <= b;
//        if(t == 2) return a >= b;
//        if(t == 3) return a >= b;
//        if(t == 4) return a <= b;
//
//        assert(0);
//    }
//
//    void add(line x)
//    {
//		if(!vec.empty()&& vec.back().m == x.m) return;
//
//		vec.push_back(x);
//
//        ll sz = vec.size();
//
//        while(sz >= 3 && bad(vec[sz - 3], vec[sz - 2], vec[sz - 1]))
//        {
//            vec.erase(vec.end() - 2);
//            sz--;
//        }
//    }

    ll ask(ll x) // ternary search
    {
		if(vec.empty()) return 0;

        ll lo = 0;
        ll hi = vec.size() - 1;

        ll ret = (t & 1)? mxlld : mnlld;

        while(lo <= hi)
        {
            ll mid1 = (lo + (hi - lo) / 3);
            ll mid2 = (hi - (hi - lo) / 3);

//            ll ans1 = func(mid1,x);
//            ll ans2 = func(mid2,x);

            ll ans1 = f(mid1,x);
            ll ans2 = f(mid2,x);

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

//    ll ask1(ll x) // pointer search (linear)
//    {
//		if(vec.empty()) return 0;
//
//		if(ptr >= vec.size()) ptr = vec.size() - 1;
//
//		while(ptr < (vec.size() - 1))
//		{
//			if(t & 1)
//			{
//				if(func(ptr,x) > func(ptr + 1,x))
//				{
//					ptr++;
//				}
//				else break;
//			}
//			else
//			{
//				if(func(ptr,x) < func(ptr + 1,x))
//				{
//					ptr++;
//				}
//				else break;
//			}
//		}
//
//		return func(ptr,x);
//    }
};



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

        cht.init(m);

        for(ll i = 1; i <= n; i++)
        {
			ll a, b, c;

			slld(a);

			if(a == 1)
			{
				slld(b);
				slld(c);

				cht.add(line(b,c));
			}
			else
			{
				slld(b);

				ans = cht.ask(b);

				printf("%lld\n", ans);
			}
        }
    }


}


