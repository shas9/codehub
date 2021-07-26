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

map < pll, bool > mp;
ll par[100005];
set < ll > st;

ll fnd(ll node)
{
	if(par[node] == node) return par[node];

	return par[node] = fnd(par[node]);
}

void bfs(ll x)
{
	if(st.empty()) return;
	st.erase(x);

	queue < ll > q;
	q.push(x);

	while(!q.empty())
	{
		ll top = q.front();
		q.pop();

		if(st.empty()) return;

		for(set < ll > :: iterator it = st.begin(); it != st.end(); )
		{
			if(mp.find({top,*it}) == mp.end())
			{
				par[fnd(*it)] = fnd(x);
				q.push(*it);
				it = st.erase(it);
			}
			else
			{
				it++;
			}
		}
	}
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);
    slld(m);

    for(i = 1; i <= m; i++)
    {
		ll u, v;
		slld(u);
		slld(v);

		mp[{u,v}] = 1;
		mp[{v,u}] = 1;
    }

    for(i = 1; i <= n; i++) par[i] = i;

    for(i = 1; i <= n; i++) st.insert(i);

    for(i = 1; i <= n; i++)
    {
		if(st.empty()) break;
		if(st.find(i) != st.end())
		{
			bfs(i);
		}
    }

    st.clear();

    for(i = 1; i <= n; i++) st.insert(fnd(i));

    cout << st.size() - 1 << "\n";
}



