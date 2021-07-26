#include <stdio.h>
#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <vector>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <utility>
#include <queue>

using namespace std;

#define ll long long
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define pii pair <int, int>
#define pll pair <long long, long long>

map <ll, vector <ll> > ed;
map <ll, vector <ll> > :: iterator mit1;
map <ll, map <ll, ll> > cost;
map <ll, map <ll, ll> > :: iterator mit2;

ll leaf1, leaf2, vis[30010], dis[3][30010], mx;

void DFSl(ll n, ll s = 0)
{
//    cout << endl << "N = " << n << " & s = " << s << endl;
    vis[n] = 1;

    for (ll i = 0; i < ed[n].size(); i++)
    {
        ll v = ed[n][i], d = cost[n][v];

//        cout << "V: " << v << " d: " << d << endl;

        if (vis[v] == 0)
        {
            vis[v] = 1;

            if (s + d > mx)
            {
                mx = s + d;
                leaf1 = v;
            }

//            cout << "Max: " << mx << " Leaf: " << leaf1 << endl;

            DFSl(v, s + d);
        }
    }
}

void DFS(ll n, ll k, ll s = 0)
{
    vis[n] = 1;

    cout << endl << "Initialized. N: " << n << " K: " << k << " S: " << s << endl;

    for (ll i = 0; i < ed[n].size(); i++)
    {
        cout << "N: " << n << " K: " << k << " S: " << s << endl;
        ll v = ed[n][i], d = cost[n][v];

        if (vis[v] == 0)
        {
            vis[v] = 1;

            if (s + d > mx)
            {
                mx = s + d;
                leaf2 = v;
            }

            dis[k][v] = s + d;

            cout << "V: " << v << " D: " << d << " Max: " << mx << " dis[k][v]: " << dis[k][v] << endl;

            DFS(v, k, s + d);
        }
    }
}

int main ()
{
    ll cs, t, i, j, k, n, x, y, z, ans, q, m, pk = 0;

    sl(t);

    for (cs = 1; cs <= t; cs++)
    {
        sl(n);

        for (mit1 = ed.begin(); mit1 != ed.end(); mit1++)
            (mit1->second).clear();

        for (mit2 = cost.begin(); mit2 != cost.end(); mit2++)
            (mit2->second).clear();

        ed.clear();
        cost.clear();

        leaf1 = leaf2 = mx = 0;

        for (i = 0; i < n-1; i++)
        {
            sl(x);
            sl(y);
            sl(z);

            ed[x].push_back(y);
            ed[y].push_back(x);

            cost[x][y] = z;
            cost[y][x] = z;
        }

        for (i = 0; i <= 30005; i++)
        {
            vis[i] = 0;
           // dis[1][i] = dis[2][i] = 0;
        }

        DFSl(0);

        mx = 0;

        for (i = 0; i <= 30005; i++)
        {
            vis[i] = 0;
          //  dis[1][i] = dis[2][i] = 0;
        }

//        cout << leaf1 << " _ " << leaf2 << endl;
        dis[1][leaf1] = 0;
        DFS(leaf1, 1);

        for (i = 0; i <= 30005; i++)
        {
            vis[i] = 0;
           // dis[1][i] = dis[2][i] = 0;
        }

        dis[2][leaf2] = 0;
        DFS(leaf2, 2);


        printf("Case %lld:\n", cs);

        for (i = 0; i <= n-1; i++)
        {
            printf("%lld\n", max(dis[1][i], dis[2][i]));
        }
    }

    return 0;
}
