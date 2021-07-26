// God put a smile upon your face <3

#include <stdio.h>

#define slld(longvalue) scanf("%d", &longvalue)

#define ll int

const ll N = (2e5) + 10;

struct paltree
{
    ll tree[200010][26];
    ll len[200010];
    ll link[200010];
    char s[200010]; // 1 indexed;
    ll depth[200010];
    ll cnt[200010];

    ll idx;
    ll t;

    void init()
    {
        while(idx)
        {
            memset(tree[idx],0,sizeof tree[idx]);
            len[idx] = link[idx] = depth[idx] = cnt[idx] = 0;
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

    void calc()
    {
		scanf("%s", s + 1);
		ll ln = strlen(s + 1);

		for(ll i = 1; i <= ln; i++) extend(i);

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
	if(node1 == 0 && node2 == 0) assert(0);

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
			solve(tree1.tree[node1][i], tree2.tree[node2][i]);
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


}




