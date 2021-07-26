// God put a smile upon your face <3

#include <bits/stdc++.h>

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

map < ll, ll > mp;
ll arr[100005];
bool vis[100005];
ll col[100005];
ll a, b;

bool solve(ll n)
{
    mp.clear();

    for(ll i = 1; i <= n; i++) mp[arr[i]] = i;

    memset(vis,0,sizeof vis);
    memset(col,0,sizeof col);

    vis[0] = 1;

    ll on = 500;

    while(on--)
    {
        for(ll i = 1; i <= n; i++)
        {
            if(arr[i] >= a && arr[i] >= b) return 0;

            if(vis[i] == 1) continue;

            bool p1 = 0, p2 = 0;

            if(arr[i] <= a)
            {
                if(vis[mp[a - arr[i]]] == 0) p1 = 1;
            }

            if(arr[i] <= b)
            {
                if(vis[mp[b - arr[i]]] == 0) p2 = 1;
            }

//            cout << i << ": " << p1 << " " << p2 << endl;

            if(p1 && p2);
            else if(p1)
            {
                col[i] = 0;
                col[mp[a - arr[i]]] = 0;

                vis[i] = 1;
                vis[mp[a - arr[i]]] = 1;
            }
            else if(p2)
            {
                col[i] = 1;
                col[mp[b - arr[i]]] = 1;

                vis[i] = 1;
                vis[mp[b - arr[i]]] = 1;
            }
            else
            {
                return 0;
            }

        }
    }

    for(ll i = 1; i <= n; i++)
    {
        if(arr[i] >= a && arr[i] >= b) return 0;

        if(vis[i] == 1) continue;

        bool p1 = 0, p2 = 0;

        if(arr[i] <= a)
        {
            if(vis[mp[a - arr[i]]] == 0) p1 = 1;
        }

        if(arr[i] <= b)
        {
            if(vis[mp[b - arr[i]]] == 0) p2 = 1;
        }

        if(p1 && p2)
        {
            ll y = a - b + arr[i];

//            if(mp[y] == 69)
//            {
//				cout << mp[b - arr[i]] << endl;
//            }
//
//            if(mp[a - arr[i]] == 69)
//            {
//				cout << i << " " << mp[b - arr[i]] << " " << mp[a - arr[i]] << " " << mp[y] << endl;
//
//            }
//
//            if(mp[b - arr[i]] == 69)
//            {
//				cout << i << " " << mp[b - arr[i]] << " " << mp[a - arr[i]] << " " << mp[y] << endl;
//            }

            if(vis[mp[y]] == 0)
            {
                col[i] = 0;
                col[mp[a - arr[i]]] = 0;
                col[mp[b - arr[i]]] = 0;
                col[mp[y]] = 0;

                vis[i] = 1;
                vis[mp[a - arr[i]]] = 1;
                vis[mp[b - arr[i]]] = 1;
                vis[mp[y]] = 1;
            }
            else
            {
                ll y = b - a + arr[i];

//                if(mp[y] == 69)
//				{
//					cout << mp[b - arr[i]] << endl;
//				}

                if(vis[mp[y]] == 0)
                {
                    col[i] = 1;
                    col[mp[a - arr[i]]] = 1;
                    col[mp[b - arr[i]]] = 1;
                    col[mp[y]] = 1;

                    vis[i] = 1;
                    vis[mp[a - arr[i]]] = 1;
                    vis[mp[b - arr[i]]] = 1;
                    vis[mp[y]] = 1;
                }
            }
        }
        else if(p1)
        {
            col[i] = 0;
            col[mp[a - arr[i]]] = 0;

            vis[i] = 1;
            vis[mp[a - arr[i]]] = 1;
        }
        else if(p2)
        {
            col[i] = 1;
            col[mp[b - arr[i]]] = 1;

            vis[i] = 1;
            vis[mp[b - arr[i]]] = 1;
        }
        else
        {
//			cout << i << " = " << mp[a - arr[i]] << " " << mp[b - arr[i]] << " " << vis[mp[b - arr[i]]] << endl;
            return 0;
        }

    }

    for(ll i = 1; i <= n; i++)
    {
        if(vis[i] == 0)
        {
            if(arr[i] * 2 == a) col[i] = 0;
            else if(arr[i] * 2 == b) col[i] = 1;
            else return 0;
        }
    }

    return 1;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> a >> b)
    {
        for(ll i = 1; i <= n; i++) cin >> arr[i];

        if(solve(n))
        {
            cout << "YES\n";

            for(ll i = 1; i <= n; i++) cout << col[i] << " ";

            cout << "\n";
        }
        else
        {
            cout << "NO\n";
        }
    }


}


