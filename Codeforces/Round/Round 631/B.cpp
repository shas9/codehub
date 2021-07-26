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

set < pll > vec;
bool vis[200005];
ll arr[200005];
bool vis2[200005];

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

        vec.clear();

        for(i = 1; i <= n; i++)
        {
            slld(arr[i]);
        }

        for(i = 1; i <= n; i++)
        {
            vis[i] = vis2[i] = 0;
        }

        for(i = 1; i <= n; i++)
        {
            if(vis[arr[i]])
            {
                for(j = i; j <= n; j++)
                {
                    if(vis2[arr[j]]) break;

                    vis2[arr[j]] = 1;

                }
                break;
            }

            vis[arr[i]] = 1;
        }

        ll cnt1 = 0;
        ll cnt2 = 0;

        for(i = 1; vis[i]; i++) cnt1++;

        for(i = 1; vis2[i]; i++) cnt2++;

        if(cnt1 + cnt2 == n)
        {
            vec.insert(make_pair(cnt1,cnt2));
        }

        for(i = 1; i <= n; i++)
        {
            vis[i] = vis2[i] = 0;
        }

        for(i = n; i >= 1; i--)
        {
            if(vis[arr[i]])
            {
                for(j = i; j >= 1; j--)
                {
                    if(vis2[arr[j]]) break;

                    vis2[arr[j]] = 1;

                }
                break;
            }

            vis[arr[i]] = 1;
        }

        cnt1 = 0;
        cnt2 = 0;

        for(i = 1; vis2[i]; i++) cnt1++;

        for(i = 1; vis[i]; i++) cnt2++;

        if(cnt1 + cnt2 == n)
        {
            vec.insert(make_pair(cnt1,cnt2));
        }

        cout << vec.size() << endl;

        for(auto it:vec)
        {
            cout << it.first << " " << it.second << endl;
        }
    }


}


