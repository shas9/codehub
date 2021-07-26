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

ll dp[1000006];
ll arr[1000006];
ll p[1000006];

struct line
{
    ll m, c;

//    line(ll x, ll y)
//    {
//        m = x;
//        c = y;
//    }
};

struct CHT
{
    vector < line > vec;
    ll t, ptr;
    ll sz;

    void init(ll x, ll n)
    {
        t = x;
        ptr = 0;
        sz = 0;
        vec.resize(n);

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

    void add(ll a, ll b)
    {
		line x;
		x.m = a;
		x.c = b;

        while(sz >= 2 && bad(vec[sz - 2], vec[sz - 1], x))
        {
            sz--;
        }

        vec[sz] = x;
        sz++;
    }

    ll ask(ll x) // ternary search
    {
        if(sz == 0)
        {
            return 0;
        }

        ll lo = 0;
        ll hi = sz - 1;

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
        if(sz == 0)
        {
            return 0;
        }

        if(ptr >= sz) ptr = sz - 1;

        while(ptr < (sz - 1))
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


void brute(ll n, ll a, ll b, ll c)
{
    p[0] = 0;
    dp[0] = 0;

    for(ll i = 1; i <= n; i++)
    {
        dp[i] = mnlld;

//			cout << "Single: " << i << " = " << a * (arr[i] * arr[i]) + b * arr[i] + c << endl;

        for(ll j = 0; j < i; j++)
        {
            ll score = (-2 * p[i] * p[j] * a) + dp[j] + (p[j] * p[j] * a) - (b * p[j]);

            dp[i] = max(dp[i], score);

            if(score == dp[i])
            {
//					cout << "Sub: " << i << " = " << " " << j << " " << score << endl;
            }
        }

        if(dp[i] == mnlld) dp[i] = 0;

        dp[i] += (p[i] * a * p[i]) + c + (b * p[i]);

//			cout << i << ": " << dp[i] << endl;
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

        ll a, b, c;

        slld(a);
        slld(b);
        slld(c);

        for(ll i = 1; i <= n; i++)
        {
            slld(arr[i]);
            p[i] = arr[i] + p[i - 1];
        }


        CHT cht;

        cht.init(4,n); // mi <= mi+1

        cht.add(0,0);

        for(ll i = 1; i <= n; i++)
        {
            dp[i] = cht.ask1(p[i]) + (a * p[i] * p[i]) + (b * p[i]) + c;

            cht.add(-2 * a * p[i], (a * p[i] * p[i]) + dp[i] + - (b * p[i]));
        }

        ans = dp[n];

        printf("%lld\n", ans);
    }


}
