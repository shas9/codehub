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

ll nr[100005];
ll ng[100005];
ll nb[100005];
ll r, g, b;

ll lb1(ll x)
{
    ll lo = 1;
    ll hi = g;
    ll ret = -1;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if(ng[mid] <= x)
        {
            ret = ng[mid];
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    return ret;
}

ll ub1(ll x)
{
    ll lo = 1;
    ll hi = g;
    ll ret = -1;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if(ng[mid] >= x)
        {
            ret = ng[mid];
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    return ret;
}

ll lb2(ll x)
{
    ll lo = 1;
    ll hi = b;
    ll ret = -1;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if(nb[mid] <= x)
        {
            ret = nb[mid];
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    return ret;
}

ll ub2(ll x)
{
    ll lo = 1;
    ll hi = b;
    ll ret = -1;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if(nb[mid] >= x)
        {
            ret = nb[mid];
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    return ret;
}

ll lb0(ll x)
{
    ll lo = 1;
    ll hi = r;
    ll ret = -1;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if(nr[mid] <= x)
        {
            ret = nr[mid];
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    return ret;
}

ll ub0(ll x)
{
    ll lo = 1;
    ll hi = r;
    ll ret = -1;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if(nr[mid] >= x)
        {
            ret = nr[mid];
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    return ret;
}

ll rgb()
{
    ll ans = mxlld;
    ll i, j, k;

    for(i = 1; i <= r; i++)
    {
        ll x = nr[i];

        for(j = 1; j <= 2; j++)
        {
            ll y;

            if(j == 1) y = lb1(x);
            else y = ub1(x);

            if(y == -1) continue;

            for(k = 1; k <= 2; k++)
            {
                ll z;

                if(k == 1) z = lb2(y);
                else z = ub2(y);

                if(z == -1) continue;

                ll res = (x - y) * (x - y) + (y - z) * (y - z)  + (z - x) * (z - x);

                ans = min(ans, res);
            }
        }
    }

    return ans;

}

ll rbg()
{
    ll ans = mxlld;
    ll i, j, k;

    for(i = 1; i <= r; i++)
    {
        ll x = nr[i];

        for(j = 1; j <= 2; j++)
        {
            ll y;

            if(j == 1) y = lb2(x);
            else y = ub2(x);

            if(y == -1) continue;

            for(k = 1; k <= 2; k++)
            {
                ll z;

                if(k == 1) z = lb1(y);
                else z = ub1(y);

                if(z == -1) continue;

                ll res = (x - y) * (x - y) + (y - z) * (y - z)  + (z - x) * (z - x);

                ans = min(ans, res);
            }
        }
    }

    return ans;

}

ll grb()
{
    ll ans = mxlld;
    ll i, j, k;

    for(i = 1; i <= g; i++)
    {
        ll x = ng[i];

        for(j = 1; j <= 2; j++)
        {
            ll y;

            if(j == 1) y = lb0(x);
            else y = ub0(x);

            if(y == -1) continue;

            for(k = 1; k <= 2; k++)
            {
                ll z;

                if(k == 1) z = lb2(y);
                else z = ub2(y);

                if(z == -1) continue;

                ll res = (x - y) * (x - y) + (y - z) * (y - z)  + (z - x) * (z - x);

                ans = min(ans, res);
            }
        }
    }

    return ans;

}

ll gbr()
{
    ll ans = mxlld;
    ll i, j, k;

    for(i = 1; i <= g; i++)
    {
        ll x = ng[i];

        for(j = 1; j <= 2; j++)
        {
            ll y;

            if(j == 1) y = lb2(x);
            else y = ub2(x);

            if(y == -1) continue;

            for(k = 1; k <= 2; k++)
            {
                ll z;

                if(k == 1) z = lb0(y);
                else z = ub0(y);

                if(z == -1) continue;

                ll res = (x - y) * (x - y) + (y - z) * (y - z)  + (z - x) * (z - x);

                ans = min(ans, res);
            }
        }
    }

    return ans;

}

ll brg()
{
    ll ans = mxlld;
    ll i, j, k;

    for(i = 1; i <= b; i++)
    {
        ll x = nb[i];

        for(j = 1; j <= 2; j++)
        {
            ll y;

            if(j == 1) y = lb0(x);
            else y = ub0(x);

            if(y == -1) continue;

            for(k = 1; k <= 2; k++)
            {
                ll z;

                if(k == 1) z = lb1(y);
                else z = ub1(y);

                if(z == -1) continue;

                ll res = (x - y) * (x - y) + (y - z) * (y - z)  + (z - x) * (z - x);

                ans = min(ans, res);
            }
        }
    }

    return ans;

}

ll bgr()
{
    ll ans = mxlld;
    ll i, j, k;

    for(i = 1; i <= b; i++)
    {
        ll x = nb[i];

        for(j = 1; j <= 2; j++)
        {
            ll y;

            if(j == 1) y = lb1(x);
            else y = ub1(x);

            if(y == -1) continue;

            for(k = 1; k <= 2; k++)
            {
                ll z;

                if(k == 1) z = lb0(y);
                else z = ub0(y);

                if(z == -1) continue;

                ll res = (x - y) * (x - y) + (y - z) * (y - z)  + (z - x) * (z - x);

                ans = min(ans, res);
            }
        }
    }

    return ans;

}

int main()
{
    ll i, j, k, l, m, n, o, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(r);
        slld(g);
        slld(b);

        for(i = 1; i <= r; i++)
        {
            slld(nr[i]);
        }

        for(i = 1; i <= g; i++)
        {
            slld(ng[i]);
        }

        for(i = 1; i <= b; i++)
        {
            slld(nb[i]);
        }

        sort(nr + 1, nr + 1 + r);
        sort(ng + 1, ng + 1 + g);
        sort(nb + 1, nb + 1 + b);

		ans = min(rgb(), min(rbg(),min(grb(),min(gbr(),min(brg(),bgr())))));
        printf("%lld\n", ans);


    }


}



