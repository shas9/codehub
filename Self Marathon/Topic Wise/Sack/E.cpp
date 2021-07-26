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

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

const ll maxn = 100005;
const ll base = 1000002431;
//const ll base = 10;
const ll mod = 1000004119;

ll dohash(string &s)
{
	ll ret = 0;

	for(auto it: s)
	{
		ret = (ret * base) % mod;

		ret = (ret + it - 'a' + 1) % mod;
	}

	return ret;
}

string str[maxn];
string tt;
ll tthash;

vector < ll > g[maxn];
vector < ll > hasht;

ll ibase[maxn * 5];

void process()
{
	ibase[0] = 1;

	for(ll i = 1; i <= 300000; i++)
	{
		ibase[i] = (ibase[i - 1] * base) % mod;
	}
}

bool subhash(ll node, char c)
{
	if(ibase[0] != 1) process();

	ll sz = hasht.size() - 1;

	if(sz < tt.size()) return 0;

	ll hashsh = ((hasht[sz] - (hasht[sz - tt.size()] * ibase[tt.size()]) % mod) % mod + mod) % mod;

	ll cmphash = tthash;

//	cout << node << " " << c << ": " << hasht.back() << " " << hashsh << " " << cmphash << " " << sz << endl;

	return hashsh == cmphash;
}

ll ans;
void dfs(ll node, ll par)
{
	for(auto it: g[node])
	{
		if(it == par) continue;

		for(auto jt: str[it])
		{
			ll nhash = (((hasht.back() * base) % mod) + jt - 'a' + 1) % mod;

			hasht.push_back(nhash);

			if(subhash(it, jt))
			{
				ans++;
			}
		}

		dfs(it,node);

		for(auto jt: str[it])
		{
			hasht.pop_back();
		}
	}
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    ans = 0;

    for(i = 2; i <= n; i++)
    {
		cin >> input >> str[i];

		g[input].pb(i);
		g[i].pb(input);
    }

    cin >> tt;

    hasht.pb(0);

    tthash = dohash(tt);

    dfs(1,-1);

    printf("%lld\n", ans);

}


