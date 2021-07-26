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

const ll mx = 300005;

ll cenpar[mx];
ll sz[mx];
bool done[mx];
ll dist[mx];
ll n, ans[mx];
ll arr[mx];

vector < pll > g[mx];

struct info
{
	ll m, c, id;
};

vector < info > lines;

bool comp(info a, info b)
{
	return a.m > b.m;
}

struct line
{
    ll m, c;

    line(ll x, ll y)
    {
        m = x;
        c = y;
    }
};

struct CHT
{
	vector < line > vec;
	ll t, ptr;

	void init(ll x)
	{
		t = x;
		ptr = 0;
		vec.clear();
	}

	inline ll func(ll idx, ll x)
	{
		ll ret = vec[idx].m * x + vec[idx].c;

		return ret;
	}

    bool bad(line f1, line f2, line f3)
    {
        __int128 a = (f3.c - f1.c);
        a = a * (f1.m - f2.m);

        __int128 b = (f2.c - f1.c);
        b = b * (f1.m - f3.m);

        if(t == 1) return a <= b;
        if(t == 2) return a >= b;
        if(t == 3) return a >= b;
        if(t == 4) return a <= b;

        assert(0);
    }

    void add(line x)
    {
        ll sz = vec.size();

        while(sz >= 2 && bad(vec[sz - 2], vec[sz - 1], x))
        {
            vec.pop_back();
            sz--;
        }

        vec.push_back(x);
    }

    ll ask(ll x) // ternary search
    {
		if(vec.empty())
		{
			return 0;
		}

        ll lo = 0;
        ll hi = vec.size() - 1;

        ll ret = (t & 1)? mxlld : mnlld;

        while(lo <= hi)
        {
            ll mid1 = (lo + (hi - lo) / 3);
            ll mid2 = (hi - (hi - lo) / 3);

            ll ans1 = func(mid1,x);
            ll ans2 = func(mid2,x);

            if(ans1 > ans2)
            {
                if(t & 1)
                {
					ret = min(ret, ans2);
					lo = mid1 + 1;
                }
                else
                {
					ret = max(ret, ans1);
					hi = mid2 - 1;
                }
            }
            else
            {
                if(t & 1)
                {
					ret =  min(ret,ans1);
					hi = mid2 - 1;
                }
                else
                {
					ret = max(ret,ans2);
					lo = mid1 + 1;
                }
            }
        }

        return ret;
    }

    ll ask1(ll x) // pointer search (linear)
    {
		if(vec.empty())
		{
			return 0;
		}

		if(ptr >= vec.size()) ptr = vec.size() - 1;

		while(ptr < (vec.size() - 1))
		{
			if(t & 1)
			{
				if(func(ptr,x) > func(ptr + 1,x))
				{
					ptr++;
				}
				else break;
			}
			else
			{
				if(func(ptr,x) < func(ptr + 1,x))
				{
					ptr++;
				}
				else break;
			}
		}

		return func(ptr,x);
    }
};

// 1 = mi > mi+1, mn
// 2 = mi > mi+1, mx
// 3 = mi < mi+1, mn
// 4 = mi < mi+1, mx

void dfs(ll node, ll par)
{
	sz[node] = 1;

	for(auto it: g[node])
	{
		if(it.first != par && done[it.first] == false)
		{
			dfs(it.first,node);
			sz[node] += sz[it.first];
		}
	}
}

void update(ll node, ll par, ll d)
{
	lines.push_back({arr[node], d, node});

	for(auto it: g[node])
	{
		if(it.first != par && done[it.first] == false)
		{
			update(it.first,node,d + it.second);
		}
	}
}

ll decompose(ll cen)
{
	dfs(cen,-1);

	ll target = sz[cen] / 2;
	ll p = -1;
	bool ok = false;

	while(!ok)
	{
		ok = true;

		for(auto it: g[cen])
		{
			if(it.first != p && done[it.first] == false && sz[it.first] > target)
			{
				ok = false;
				p = cen;
				cen = it.first;
				break;
			}
		}
	}

	done[cen] = true;

	lines.clear();

	update(cen, - 1, 0);

	sort(lines.begin(),lines.end(), comp);

//	cout << cen << ": ";
//
//	for(auto it: lines) cout << it.first << " " << it.second << endl;

	CHT cht;

	cht.init(1);

	for(auto it: lines)
	{
		cht.add({it.m, it.c});
	}

	reverse(lines.begin(),lines.end());

	for(auto it: lines)
	{
		ans[it.id] = min(ans[it.id], cht.ask1(it.m) + it.c);
	}

//	cout << cen << ": " << endl;
//
//	for(info it: lines)
//	{
//		cout << it.id << " = " << it.m << " " << it.c << endl;
//	}
//
//	for(ll i = 1; i <= n; i++)
//	{
//		cout << i << ": " << ans[i] << endl;
//	}

	for(auto it: g[cen])
	{
		if(done[it.first] == false)
		{
			cenpar[decompose(it.first)] = cen;
		}
	}

	return cen;
}


int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    for(ll i = 1; i <= n; i++) slld(arr[i]);

    for(ll i = 1; i < n; i++)
    {
		ll u, v, w;

		slld(u);
		slld(v);
		slld(w);

		g[u].pb({v,w});
		g[v].pb({u,w});
    }

    for(ll i = 1; i <= n; i++) ans[i] = mxlld;

	decompose(1);

	ll sum = 0;

	for(ll i = 1; i <= n; i++) sum += ans[i];

    printf("%lld\n", sum);

    return 0;

}



