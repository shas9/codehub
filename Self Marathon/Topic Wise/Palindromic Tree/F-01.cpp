// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll int
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

const ll MAXN = 2e6 + 666;

struct palindromic_tree
{
    ll len[MAXN], link[MAXN], cnt[MAXN];
    char S[MAXN];
    vector<pair<char, ll>> to[MAXN];

    ll n, last, sz;

    void clear()
    {
        fill(to, to + MAXN, vector<pair<char, ll>>());
        memset(len , 0, sizeof(len ));
        memset(link, 0, sizeof(link));
        memset(cnt , 0, sizeof(cnt ));
        memset(S   , 0, sizeof(S   ));
        n = last = 0;
        link[0] = 1;
        len[1] = -1;
        S[n++] = 27;
        sz = 2;
    }

    palindromic_tree()
    {
		clear();
    }

    ll get_link(ll v)
    {
        while(S[n - len[v] - 2] != S[n - 1]) v = link[v];
        return v;
    }

    ll tr(ll v, ll c)
    {
        for(auto it: to[v])
            if(it.first == c) return it.second;
        return 0;
    }

    ll add_letter(char cc)
    {
		ll c = cc - 'a';
        S[n++] = c;
        ll cur = get_link(last);
        if(!tr(cur, c))
        {
            len [sz] = len[cur] + 2;
            link[sz] = tr(get_link(link[cur]), c);
            to[cur].push_back({c, sz++});
        }
        last = tr(cur, c);

        return cnt[last] = cnt[link[last]] + 1;
    }
} tree;

string str;

long long finish[MAXN];
ll start[MAXN];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;
    long long ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> str)
    {
		ans = 0;

		for(ll i = 0; i < n; i++) finish[i] = tree.add_letter(str[i]), finish[i] += i ? finish[i - 1] : 0;

		tree.clear();

		for(ll i = n - 1; i >= 0; i--) start[i] = tree.add_letter(str[i]), ans += start[i];

//		for(ll i = 0; i < n; i++) cout << i << ": " << start[i + 1] << " " << finish[i] << endl;

		const ll mod = 51123987;
		ans %= mod;
		ans = (ans * (ans - 1)) / 2;
		ans %= mod;

		for(ll i = 1; i < n; i++)
		{
			ans -= finish[i - 1] * start[i];
			ans %= mod;
		}

		ans %= mod;
		if(ans < 0) ans += mod;

		printf("%lld\n", ans);

    }


}



