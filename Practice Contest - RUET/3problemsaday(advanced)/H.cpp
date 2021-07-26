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

ll s[200005];

ll tree[1000005];

void init(ll node, ll b, ll e)
{
    if(b == e)
    {
        tree[node] = s[b];
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node] = min(tree[left], tree[right]);
}

ll sum(ll node, ll b, ll e, ll i, ll j)
{
    if(i > e || j < b)
    {
        return mxlld;
    }

    if(b >= i && e <= j)
    {
        return tree[node];
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    ll p1 = sum(left, b, mid, i, j);
    ll p2 = sum(right, mid + 1, e,i, j);

    return min(p1,p2);
}

const ll MAX_N = 2e5+10, mod = 2e9+63, base1 = 1e9+21, base2 = 1e9+181;
ll pw1[MAX_N], pw2[MAX_N];
ll val1, val2;

void precalc() {
    pw1[0] = pw2[0] = 1;
    for(int i = 1; i < MAX_N; i++) {
        pw1[i] = (pw1[i-1] * base1) % mod;
        pw2[i] = (pw2[i-1] * base2) % mod;
    }
}

struct Hash {
    ll h1[MAX_N], h2[MAX_N];

    void init(ll slen) {
        h1[0] = h2[0] = 0;
        for(int i = 1; i <= slen; i++) {
            h1[i] = (h1[i-1] * base1 + s[i]) % mod;
            h2[i] = (h2[i-1] * base2 + s[i]) % mod;
        }
    }

    inline ll hashVal(int l, int r, int biyog = 0) {
        ll hsh1 = (h1[r] - h1[l-1] * pw1[r-l+1]) % mod;
        if(hsh1 < 0) hsh1 += mod;
        ll hsh2 = (h2[r] - h2[l-1] * pw2[r-l+1]) % mod;
        if(hsh2 < 0) hsh2 += mod;

        hsh1 = ((hsh1 - (biyog * 1LL * val1)) % mod + mod) % mod;
        hsh2 = ((hsh2 - (biyog * 1LL * val2)) % mod + mod) % mod;
        return (hsh1 << 32) | hsh2;
    }

    inline ll hashOne(int l, int r) {
        ll hsh1 = (h1[r] - h1[l-1] * pw1[r-l+1]) % mod;
        if(hsh1 < 0) hsh1 += mod;
        return hsh1;
    }

    inline ll hashTwo(int l, int r) {
        ll hsh2 = (h2[r] - h2[l-1] * pw2[r-l+1]) % mod;
        if(hsh2 < 0) hsh2 += mod;
        return hsh2;
    }
} fw1, fw2;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	precalc();

    while(cin >> m >> n)
    {
		for(ll i = 1; i <= m; i++)
		{
			slld(s[i]);
		}

		init(1,1,m);

		fw2.init(m);

		ll mn = mxlld;

		for(ll i = 1; i <= n; i++)
		{
			slld(s[i]);

			mn = min(mn, s[i]);
		}

		for(ll i = 1; i <= n; i++)
		{
			s[i] -= (mn - 1);
		}


		fw1.init(n);

		val1 = val2 = 0;

		ll curr1 = 1, curr2 = 1;

		for(ll i = 1; i <= n; i++)
		{
			val1 = (curr1 + val1) % mod;
			val2 = (curr2 + val2) % mod;

			curr1 = (curr1 * base1) % mod;
			curr2 = (curr2 * base2) % mod;
		}

		ll seghash = fw1.hashVal(1,n);

		ans = 0;

//		cout << seghash << endl;

		for(ll i = 1; i + n - 1 <= m; i++)
		{
			ll mn = sum(1,1,m,i,i + n - 1);

//			cout << mn << " ";

			ll hsh = fw2.hashVal(i, i + n - 1, mn - 1);

//			cout << hsh << endl;

			ans += (seghash == hsh);
		}

		cout << ans << '\n';
    }



}



