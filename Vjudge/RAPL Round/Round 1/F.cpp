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


char grid[503][503];
ll mark[503][503];
ll par[503 * 503];

ll fnd(ll node)
{
	if(par[node] == node) return node;

	return par[node] = fnd(par[node]);
}

ll n, m;

ll dx[] = {1,-1,0,0};
ll dy[] = {0,0,1,-1};

void dfs(ll i, ll j, ll num)
{

	if(i > n || i <= 0) return;
	if(j > m || j <= 0) return;

	if(grid[i][j] == '0') return;
	if(mark[i][j]) return;

	mark[i][j] = num;

	for(ll ii = 0; ii < 4; ii++) dfs(i + dx[ii], j + dy[ii], num);
}

vector < pair < ll, pll > > vec;

int main()
{
    ll i, j, k, l, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    slld(m);

    memset(mark,0,sizeof mark);

    for(i = 1; i <= n; i++) scanf("%s", grid[i] + 1);

	ll num = 0;

    for(i = 1; i <= n; i++)
    {
		for(j = 1; j <= m; j++)
		{
			if(mark[i][j]) continue;

			if(grid[i][j] == '1')
			{
				dfs(i,j,++num);
				par[num] = num;
			}
		}
    }

//    bug;
    for(i = 1; i <= n; i++)
    {
		ll last = -1;
		ll jj = -1;

		for(j = 1; j <= m; j++)
		{
//			cout << mark[i][j];
			if(mark[i][j])
			{
				if(last == -1) last = mark[i][j], jj = j;
				else
				{
					if(last != mark[i][j])vec.push_back({j - jj - 1, {last,mark[i][j]}});

					last = mark[i][j];
					jj = j;
				}
			}
		}

//		cout << endl;
    }

    for(i = 1; i <= m; i++)
    {
		ll last = -1;
		ll jj = -1;

		for(j = 1; j <= n; j++)
		{
//			cout << mark[i][j];
			if(mark[j][i])
			{
				if(last == -1) last = mark[j][i], jj = j;
				else
				{
					if(last != mark[j][i])vec.push_back({j - jj - 1, {last,mark[j][i]}});

					last = mark[j][i];
					jj = j;
				}
			}
		}

//		cout << endl;
    }

    sort(vec.begin(),vec.end());

    ans = 0;

    for(auto it: vec)
    {
		ll u = it.second.first;
		ll v = it.second.second;

//		cout << it.first << " " << u << " " << v << endl;

		ll pu = fnd(u);
		ll pv = fnd(v);

		if(pu == pv) continue;

		ans += it.first;

		par[pu] = pv;
    }

    set < ll > st;

    st.clear();
    for(ll i = 1; i <= num; i++) st.insert(fnd(i));

    ll mxrow = 0;
    ll mnrow = n + n;
    ll mxcol = 0;
    ll mncol = m + m;

    for(ll i = 1; i <= n; i++) for(ll j = 1; j <= m; j++) if(mark[i][j]) mxrow = max(mxrow,i), mnrow = min(mnrow,i), mxcol = max(mxcol,j), mncol = min(mncol,j);

    if(st.size() > 1)
    {
		ans += abs(mxcol - mncol) + abs(mxrow - mnrow);
    }

    cout << ans << '\n';


}



