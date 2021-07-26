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

const ll N = (2e5) + 10;

ll tree[N][26];
ll len[N];
ll link[N];
char s[N]; // 1 indexed;
ll suffix[N];
ll hsh[5][N];

const ll base[] = {1000001491, 1000001501, 1000001531, 1000001537, 1000001539};
const ll mod[] = {1000004059,	1000004099,	1000004119,	1000004123,	1000004207};

ll ibase[5][N];
ll indexing[N];

ll idx = 0, t = 0;

void init()
{
    while(idx)
    {
        for(ll i = 0; i < 26; i++) tree[idx][i] = 0;
        len[idx] = link[idx] = 0;
        suffix[idx] = 0;
        idx--;
    }

    len[1] = -1, link[1] = 1;
    len[2] = 0, link[2] = 1;
    idx = t = 2;
}

void extend(ll p)
{
    if(p == 1) init();
    while(s[p - len[t] - 1] != s[p]) t = link[t];

    ll x = link[t];
    ll c = s[p] - 'a';

    while(s[p - len[x] - 1] != s[p]) x = link[x];

    if(!tree[t][c])
    {
        tree[t][c] = ++idx;
        len[idx] = len[t] + 2;
        link[idx] = (len[idx] == 1) ? 2 : tree[x][c];
    }

    t = tree[t][c];

    suffix[t]++;
    indexing[p] = t;
}

unordered_map < ll, ll > mp[3][5];

void solve(ll indx)
{
	for(ll i = 0; i < 5; i++) mp[indx][i].clear();

    scanf("%s", s + 1);

    ll n = strlen(s + 1);

    for(ll i = 1; i <= n; i++)
    {
        extend(i);
    }

    for(ll j = 0; j < 5; j++)
    {
		hsh[j][0] = 0;
		for(ll i = 1; i <= n; i++)
		{
			ll x = s[i] - 'a' + 1;
			hsh[j][i] = ((ibase[j][200000 - i] * 1LL * x) % mod[j] + hsh[j][i - 1]) % mod[j];
		}
    }

    for(ll i = idx; i >= 2; i--)
    {
        suffix[link[i]] += suffix[i];
    }

    for(ll j = 0; j < 5; j++)
    {
		for(ll i = 1; i <= n; i++)
		{
			ll ln = len[indexing[i]];

			ll hshval = ((hsh[j][i] - hsh[j][i - ln]) % mod[j] + mod[j]) % mod[j];

			hshval = (hshval * 1LL * ibase[j][i - ln]) % mod[j];

			mp[indx][j][hshval] = suffix[indexing[i]];
		}
    }

    return;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;
    ll ans;
//
//    freopen("input1.txt", "r", stdin);
////
//    freopen("output.txt", "w", stdout);

    for(ll j = 0; j < 5; j++)
    {
		ibase[j][0] = 1;
		for(ll i = 1; i < N; i++)
		{
			ibase[j][i] = (ibase[j][i - 1] * 1LL * base[j]) % mod[j];
		}
    }

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        solve(1);

        solve(2);

        map < ll, ll > ff;
        ff.clear();

        for(ll i = 0; i < 5; i++)
        {
			ans = 0;

			for(auto it: mp[1][i])
			{
				ans += it.second * mp[2][i][it.first];
			}

//			cout << ans << endl;

			ff[ans]++;
        }

        ll mx = 0;

        for(auto it: ff)
        {
			if(it.second > mx)
			{
				ans = it.first;
				mx = it.second;
			}
        }

        printf("Case #%lld: %lld\n", cs, ans);
    }
}

