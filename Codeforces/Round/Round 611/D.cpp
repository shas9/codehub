#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009

#define pll pair < long long, long long >

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

map < ll, bool > vis;
deque < pll > dq;
ll xx[200005];
ll yy[200005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
        vis.clear();
        dq.clear();

        for(i = 1; i <= n; i++)
        {
            slld(xx[i]);

            vis[xx[i]] = 1;

            dq.push_back(make_pair(xx[i],xx[i]));
        }

        // node, top parent node;

        ll idx = 1;

        ans = 0;
        while(idx <= m)
        {
            i = 0;
            ll sz = dq.size();

            while(sz)
            {
                pll top = dq[0];
                ll lft = top.first - 1;
                ll rgt = top.first + 1;

                if(vis.find(lft) == vis.end())
                {
                    yy[idx] = lft;

                    ans += abs(lft - top.second);

                    vis[lft] = 1;
                    idx++;

                    dq.push_back(make_pair(lft,top.second));
                    sz++;
                }

                if(idx > m) break;

                if(vis.find(rgt) == vis.end())
                {
                    yy[idx] = rgt;

                    ans += abs(rgt - top.second);
                    vis[rgt] = 1;
                    idx++;

                    dq.push_back(make_pair(rgt,top.second));
                    sz++;
                }

                if(idx > m) break;

                dq.pop_front();
                sz--;
            }
        }

        cout << ans << endl;
        for(i = 1; i <= m; i++)
        {
            cout << yy[i] << " ";
        }

        cout << endl;
    }




}



