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


vector < ll > row[100005];
vector < ll > col[100005];

ll fr(ll idx, ll fnd, ll flag = 0)
{
	ll ret = lower_bound(row[idx].begin(), row[idx].end(), fnd) - row[idx].begin();

	if(flag)ret--;
	return row[idx][ret];
}

ll fc(ll idx, ll fnd, ll flag = 0)
{
	ll ret = lower_bound(col[idx].begin(), col[idx].end(), fnd) - col[idx].begin();

	if(flag)ret--;

	return col[idx][ret];
}

bool solve(ll n, ll m, ll k)
{
	for(ll i = 1; i <= n; i++) row[i].pb(0);
	for(ll i = 1; i <= m; i++) col[i].pb(0);

	for(ll i = 1; i <= n; i++) sort(row[i].begin(),row[i].end());
	for(ll i = 1; i <= m; i++) sort(col[i].begin(),col[i].end());

	for(ll i = 1; i <= n; i++) row[i].pb(m+1);
	for(ll i = 1; i <= m; i++) col[i].pb(n+1);

	ll covered = 1;

	ll curx = 1,cury = 1, curd = 0;
	ll maxc = m + 1, maxr = n + 1;
	ll minc = 0, minr = 0;

	bool ok = 1;

	while(1)
	{
//		cout << curx << " " << cury << " " << curd << endl;
		ll nx = -1, ny = -1;

		if(curd == 0) nx = curx, ny = min(maxc,fr(nx,cury)) - 1, minr = curx;
		else if(curd == 1) ny = cury, nx = min(maxr,fc(ny,curx)) - 1, maxc = cury;
		else if(curd == 2) nx = curx, ny = max(minc,fr(nx,cury,1)) + 1, maxr = curx;
		else ny = cury, nx = max(minr,fc(ny,curx,1)) + 1, minc = cury;

		if(nx == curx && ny == cury)
		{
			 break;
		}

		covered += abs(nx-curx) + abs(ny-cury);
		curx = nx;
		cury = ny;
		curd = (curd + 1) % 4;
		ok = 0;
	}

	return covered == (n*m - k);

}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//    slld(testcase);
//
//    for(ll cs = 1; cs <= testcase; cs++)

	while(cin >> n >> m >> k)
    {
		for(ll i = 1; i <= n; i++) if(!row[i].empty()) row[i].clear();
		for(ll i = 1; i <= m; i++) if(!col[i].empty()) col[i].clear();

		for(i = 1; i <= k; i++)
		{
			ll u, v;

			slld(u);
			slld(v);

			row[u].pb(v);
			col[v].pb(u);
		}

		if(solve(n,m,k)) printf("Yes\n");
		else printf("No\n");
    }


}



