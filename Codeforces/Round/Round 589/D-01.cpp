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

vector < ll > g[200005];
vector < ll > v[4];
bool vis[200005];
ll col[200005];

bool check(vector < ll > &v)
{
	map < ll, bool > mp;

	for(auto it: v)
	{
		if(mp.find(it) != mp.end())
		{
//			cout << it << endl;
			return 1;
		}

		mp[it] = 1;

		for(auto jt: g[it])
		{
//			if(mp.find(jt) != mp.end())
//			{
//				cout << jt << endl;
//				return 1;
//			}

			mp[jt] = 1;
		}
	}

	return 0;

}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
        for(ll i = 0; i <= n + 1000; i++)
        {
            g[i].clear();
            if(i < 4) v[i].clear();
            vis[i] = 0;
            col[i] = -1;
        }

        for(ll i = 1; i <= m; i++)
        {
            ll u, v;

            slld(u);
            slld(v);

            g[u].pb(v);
            g[v].pb(u);
        }

        bool no = 0;
        ll cnt = 0;

        for(ll i = 1; i <= n; i++)
        {
            if(vis[i]) continue;

            if(cnt == 3)
            {
                no = 1;
                break;
            }

            sort(g[i].begin(),g[i].end());

            ll now = 1;

            for(auto it: g[i])
            {
                while(now < it)
                {
                    if(vis[now])
                    {
                        no = 1;
                        break;
                    }

                    vis[now] = 1;

                    v[cnt].push_back(now);

                    now++;
                }
                now++;

                if(no) break;
            }

            if(no) break;

            while(now <= n)
            {
                if(vis[now])
                {
                    no = 1;
                    break;
                }

                vis[now] = 1;

                v[cnt].push_back(now);

                now++;
            }

            if(no) break;

            cnt++;
        }

//        if(n == 21491 && m == 128919) cout << v[0].size() << " " << v[1].size() << " " << v[2].size() << endl;
//        if(n == 21491 && m == 128919)
//        {
//			for(auto it: v[1]) cout << it << " ";
//			cout << endl;
//
//			for(auto it: v[2]) cout << it << " ";
//			cout << endl;
//
//        }

		flag = v[0].size() * v[1].size() + v[0].size() * v[2].size() + v[1].size() * v[2].size();

		for(ll i = 0; i < 3; i++)
		{
			no |= check(v[i]);
		}

        if(cnt != 3 || no || (flag != m))
        {
            printf("-1\n");
        }
        else
        {
            for(ll i = 0; i < 3; i++)
            {
                for(auto it: v[i])
                {
                    assert(col[it] == -1);
                    col[it] = i + 1;
                }
            }

            for(ll i = 1; i <= n; i++)
            {
                printf("%lld ", col[i]);
                assert(col[i] != -1);
            }

            cout << '\n';
        }
    }

}



