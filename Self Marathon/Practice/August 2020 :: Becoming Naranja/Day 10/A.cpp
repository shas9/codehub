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

const ll maxn = 1e6 + 2;
char str[maxn];
bool done[maxn];
ll jump[maxn];
vector < ll > g[maxn];
ll ans[maxn];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	fastio;
    while(cin >> n >> str + 1)
    {
		memset(done,0,sizeof done);
		memset(jump,-1,sizeof jump);
		memset(ans,0,sizeof ans);

		for(ll i = 1; i <= n; i++) g[i].clear();

		ll z = n + 1, o = n + 1;

		for(ll i = n; i >= 1; i--)
		{
			if(str[i] == '1') o = i;
			else if(str[i] == '0') z = i;

			g[max(z,o) - i].pb(i);
		}

		for(ll i = n; i >= 1; i--)
		{
//			cout << i << endl;

			for(auto it: g[i])
			{
				for(ll j = it; j >= 1 && done[j] == 0; j--) jump[j] = it;
				done[it] = 1;
			}

//			for(ll j = 1; j <= n; j++) cout << done[j] << " ";
//			cout << endl;
//
//			for(ll j = 1; j <= n; j++) cout << jump[j] << " ";
//			cout << endl;

			ll now = 1;

			while(now <= n)
			{
				now = jump[now];

				if(now == -1) break;

				ans[i]++;

				now += i;
			}
		}

		for(ll i = 1; i <= n; i++) cout << ans[i] << " ";
		cout << "\n";
    }


}



