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


pll seg[1000006];
ll tree[1000006];
ll par[1000006];
ll endpoint[1000006];

ll query(ll idx)
{
       ll sum=0;
       while(idx>0){
             sum+=tree[idx];
             idx -= idx & (-idx);
       }
       return sum;
}

void update(ll idx, ll x, ll n) //n is the size of the array, x is the number to add
{
       while(idx<=n)
       {
             tree[idx]+=x;
             idx += idx & (-idx);
       }
}

ll bs(ll lo, ll hi, ll sum)
{
    ll ret = 0;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if(query(mid) >= sum)
        {
            ret = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    return ret;
}

ll fnd(ll idx)
{
    if(par[idx] == idx) return idx;

    return par[idx] = fnd(par[idx]);
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        for(i = 1; i <= (2 * n); i++)
        {
            tree[i] = 0;
            par[i] = i;
        }

        for(i = 1; i <= n; i++)
        {
            slld(seg[i].first);
            slld(seg[i].second);

            endpoint[seg[i].second] = i;
        }

        sort(seg + 1, seg + 1 + n);

        bool loop = 0;

        for(i = 1; i <= n; i++)
        {
            ll cnt = query(seg[i].second) - query(seg[i].first);
            ll lo = seg[i].first;
            ll hi = seg[i].second;
            ll sum = query(seg[i].first);

//            cout << i << " ~~ " << cnt << endl;

            for(j = 1; j <= cnt; j++)
            {
                ll pu = fnd(seg[i].second);

                lo = bs(lo,hi,sum + j);

                ll node = endpoint[lo];

                ll pv = fnd(lo);

//                cout << node << " " << pu << " " << pv << endl;

                if(pu == pv)
                {
                    loop = 1;
                    break;
                }

                par[pu] = pv;
                par[pv] = pv;
            }

            if(loop) break;

            update(seg[i].second,1,2*n);
        }

        if(loop)
        {
            cout << "NO" << endl;
            continue;
        }

        ll pu = fnd(seg[1].second);

        bool dcon = 0;

        for(i = 2; i <= n; i++)
        {
            ll pv = fnd(seg[i].second);

            if(pv != pu)
            {
                dcon = 1;
                break;
            }
        }

        if(dcon) cout << "NO"<< endl;
        else cout << "YES" << endl;

    }


}


