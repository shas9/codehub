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

#define mod 958585860497

#define base 2001487

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}


vector < ll > graph[200005];
vector < pll > qq[200005];
ll tree[200005];
ll mp[200005];
ll arr[200005];

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

ll ans[200005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);
    slld(m);

    for(i = 1; i <= n; i++)
    {
		slld(arr[i]);
		mp[arr[i]] = i;
    }

    for(i = 1; i <= m; i++)
    {
		slld(l);
		slld(r);

		qq[r].pb({l,i});
    }

    for(i = 1; i <= n; i++)
    {
		for(j = i; j <= n; j += i)
		{
			ll x = max(mp[i],mp[j]);
			ll y = min(mp[i],mp[j]);

			graph[x].push_back(y);
		}
    }

    for(i = 1; i <= n; i++)
    {
		for(auto it: graph[i])
		{
			update(it,1,n);
		}

		for(pll it: qq[i])
		{
			ans[it.second] = query(n) - query(it.first - 1);
		}
    }

    for(i = 1; i <= m; i++)
    {
		printf("%lld\n", ans[i]);
    }


}




