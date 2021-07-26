// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)

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

const ll N = (3e5) + 10;

ll tree[N][26];
ll len[N];
ll link[N];
char s[N]; // 1 indexed;
ll suffix[N];
ll prefix[N];
ll suftrack[N];
ll preftrack[N];

ll idx = 0, t = 0;

void init()
{
    while(idx)
    {
        for(ll i = 0; i < 26; i++) tree[idx][i] = 0;
        len[idx] = link[idx] = 0;
        idx--;
    }

    len[1] = -1, link[1] = 1;
    len[2] = 0, link[2] = 1;
    idx = t = 2;
}

void extend(ll p, bool state)
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

	if(state == 0) suffix[t] = 1 + suffix[link[t]], suftrack[p] = suffix[t];
	else prefix[t] = 1 + prefix[link[t]], preftrack[p] = prefix[t];
}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;
    long long ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);



    while(scanf("%s", s + 1) != EOF)
    {
        n = strlen(s + 1);

        for(ll i = 1; i <= n; i++)
        {
            extend(i,0);
        }

        reverse(s + 1, s + 1 + n);

        for(ll i = 1; i <= n; i++)
        {
            extend(i,1);
        }

        reverse(preftrack + 1, preftrack + 1 + n);

		ans = 0;

		for(ll i = n - 1; i >= 1; i--)
		{
			preftrack[i] += preftrack[i + 1];
		}

        for(ll i = 1; i < n; i++)
        {
            ans += suftrack[i] * 1LL * preftrack[i + 1];
        }

        cout << ans << '\n';
    }
}




