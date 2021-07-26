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

void sim()
{
	ll n;

	cin >> n;

	map < pll, ll > mp;

	ll x, y;
	cin >> x >> y;

	ll ans = 0;

	for(ll i = 0; i < n; i++)
	{
		for(ll j = 0; j < n; j++)
		{
			if(mp[{i,j}] != 0) continue;

			ans++;

			ll ni = i, nj = j;

			cout << ni << " !! " << nj << endl;

			while(mp[{ni,nj}] == 0)
			{
				mp[{ni,nj}] = ans;

				ni = (ni + x) % n;
				nj = (nj + y) % n;

//				cout << ni << " " << nj << endl;
			}

			if(ans != mp[{ni,nj}]) assert(0);
		}
	}

	cout << ans << endl;
}

ll mp[1000006];
ll group[1000006];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);



    ll dx, dy;

    fastio;
    while(cin >> n >> m >> dx >> dy)
    {
		ll nx = dx;
		ll ny = dy;

		mp[0] = 0;

		while(nx)
		{
			mp[nx] = ny;

			nx = (nx + dx) % n;
			ny = (ny + dy) % n;
		}

		memset(group,0,sizeof group);

		ans = 0;
		ll pos = 0;

		for(ll i = 0; i < m; i++)
		{
			ll x, y;

			cin >> x >> y;

			ll k = (y - mp[x] + n) % n;

			group[k]++;

			ans = max(ans, group[k]);

			if(ans == group[k]) pos = k;
		}

		cout << 0 << " " << pos << "\n";
    }


}


