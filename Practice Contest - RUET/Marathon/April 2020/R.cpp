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


#define maxn 1000002

using namespace std;

vector < ll > primes;
bool vis[maxn+10];

vector < ll > graph[100005];

map < ll, ll > mp;

void sieve()
{
    vis[0] = 1;
    vis[1] = 1;

    for(ll i = 4; i <= maxn; i += 2)
    {
        vis[i] = 1;
    }

    for(ll i = 3; i * i <= maxn; i += 2)
    {
        if(vis[i] == 0)
        for(ll j = i * i; j <= maxn; j += i)
        {
            vis[j] = 1;
        }
    }

    ll cnt = 0;

    primes.push_back(0);
    for(ll i = 2; i <= maxn; i++)
    {
        if(vis[i] == false)
        {
			primes.pb(i);
			mp[i] = ++cnt;
        }
    }

//    cout << cnt << endl;

}

bool vis2[100005];
set < ll > tmp;

void dfs(ll node)
{
	vis2[node] = 1;

	for(ll it: graph[node])
	{
		if(vis2[it]) continue;

		dfs(it);
	}
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);
//
//    freopen("output.txt", "w", stdout);

	sieve();

//	cout << primes.size() << " " << mp.size() << endl;
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);

		for(i = 0; i <= 100000; i++)
		{
			vis2[i] = 0;
			graph[i].clear();
		}

		tmp.clear();

		ans = 0;

		while(n--)
		{
			slld(input);

			if(input == 1)
			{
				ans++;
				continue;
			}

			ll prv = -1;
			ll first = -1;

			for(i = 1; primes[i] * primes[i] <= input; i++)
			{
				if(input % primes[i]) continue;

				if(prv != -1)
				{

					graph[prv].pb(i);
					graph[i].pb(prv);
				}
				else first = i;
				prv = i;

				tmp.insert(i);

				while(input % primes[i] == 0) input /= primes[i];
			}

			if(input > 1)
			{
				i = mp[input];

				if(prv != -1)
				{
					graph[prv].pb(i);
					graph[i].pb(prv);
				}

				prv = i;

				tmp.insert(i);
			}

			if(prv != first && first != -1)
			{
				i = first;
				if(prv != -1)
				{
					graph[prv].pb(i);
					graph[i].pb(prv);
				}

				prv = i;

				tmp.insert(i);
			}
		}
//		bug;
		for(ll it: tmp)
		{
//			cout << it << " " << vis2[it] << endl;

			if(!vis2[it])
			{
				dfs(it);
				ans++;
			}
		}

		printf("Case %lld: %lld\n",cs,ans);
    }


}



