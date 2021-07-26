// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)

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

const ll N = (2e5) + 3;

struct paltree
{
    ll tree[N][26];
    ll len[N];
    ll link[N];
    char s[N]; // 1 indexed;
    ll depth[N];
    ll cnt[N];

    ll idx = 0, t = 0;

    inline void init()
    {
        while(idx)
        {
            for(ll i = 0; i < 26; i++) tree[idx][i] = 0;

            len[idx] = link[idx] = depth[idx] = cnt[idx] = 0;

            idx--;
        }

        len[1] = -1, link[1] = 1;
        len[2] = 0, link[2] = 1;
        idx = t = 2;
    }

    inline void extend(ll p)
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

        cnt[t]++;
    }

    void dfs(ll node)
    {
		depth[node] = 1;

		for(ll i = 0; i < 26; i++)
		{
			if(tree[node][i])
			{
				dfs(tree[node][i]);
				depth[node] += depth[tree[node][i]];
			}
		}
    }

    inline void calc()
    {
		scanf("%s", s + 1);

		for(ll i = 1; s[i] != '\0'; i++) extend(i);

		dfs(1);
		dfs(2);

		for(ll i = idx; i > 2; i--)
		{
			cnt[link[i]] += cnt[i];
		}
    }

} tree1, tree2;

ll a, b, c;

void solve(ll node1, ll node2)
{
	if(node1 == 0)
	{
		 c += tree2.depth[node2];
		 return;
	}

	if(node2 == 0)
	{
		a += tree1.depth[node1];
		return;
	}

	if(node1 > 2)
	{
		if(tree1.cnt[node1] > tree2.cnt[node2]) a++;
		else if(tree1.cnt[node1] < tree2.cnt[node2]) c++;
		else b++;
	}

	for(ll i = 0; i < 26; i++)
	{
		if((tree1.tree[node1][i] || tree2.tree[node2][i]))
		{
			solve(tree1.tree[node1][i], tree2.tree[node2][i]);
		}
	}

	return;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		tree1.calc();
		tree2.calc();

		a = b = c = 0;

		solve(1,1);
		solve(2,2);

		printf("Case #%d: %d %d %d\n", cs, a, b, c);
    }

	return 0;

}



