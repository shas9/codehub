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

void brute()
{
	ll cnt = 1000;

	vector < ll > v, sv, rsv;

	while(cnt--)
	{
		v.clear();
//		sv.clear();
//		rsv.clear();

		ll a = rand() % 100000;
		ll b = rand() % 100000;
		ll c = rand() % 100000;
		ll d = rand() % 1000;

		if(rand() % 17 == 0) a = 0;
		if(rand() % 13 == 0) b = 0;
		if(rand() % 29 == 0) c = 0;
		if(rand() % 37 == 0) d = 0;

		ll sq = sqrt(a) + 1;

		cout << "Processing " << a << " " << b << " " << c << " " << d << endl;
		ll diff = -1;

		for(ll i = 350; i <= 100000; i++)
		{
			ll ans = a + b * i + c * i * i + d * i * i * i;

			if(!v.empty())
			{
				ll x = ans - i;

				assert(x == diff);
			}
			else diff = ans - i;

			v.push_back(ans);
		}

//		sv = v;
//		rsv = v;

//		sort(sv.begin(),sv.end());
//		sort(rsv.rbegin(),rsv.rend());


//		assert(v == sv);
	}

	cout << "DONE" << endl;
}

struct Line
{
    ll a0, a1, a2, a3;
};

struct Lichao
{
    vector < Line > tree;
    vector < ll > pnt;
    ll n;
    ll type;

    Lichao (): pnt(0,0) {}

    void init()
    {
        n = pnt.size();

        tree.clear();
        tree.resize(4 * (n + 5));

		for(ll i = 0; i < tree.size(); i++) tree[i] = {mxlld,0,0,0};
    }

    inline ll f(Line &line, ll &x)
    {
        return line.a0 + line.a1 * x + line.a2 * x * x + line.a3 * x * x * x;
    }

    void add2(ll lo, ll hi, Line line, ll node)
    {
        if(lo == hi)
        {
            if(f(line, pnt[lo]) < f(tree[node], pnt[lo]))
                tree[node] = line;
            return;
        }

        ll mid = lo+hi >> 1;

        bool left = f(line, pnt[lo]) < f(tree[node], pnt[lo]);
        bool m = f(line, pnt[mid]) < f(tree[node], pnt[mid]);

        if(m) swap(line, tree[node]);

        if(left != m) add2(lo, mid, line, node<<1);
        else add2(mid+1, hi, line, node<<1|1);
    }

    void update(Line x)
    {
       add2(0,n,x,1);
    }

    ll query2(ll lo, ll hi, ll idx, ll node)
    {
        if(lo == hi)
            return f(tree[node], pnt[idx]);

        ll mid = (lo+hi) >> 1, ret = f(tree[node], pnt[idx]);

        if(idx <= mid) return min(ret, query2(lo, mid, idx, node<<1));
        else return min(ret, query2(mid+1, hi, idx, node<<1 | 1));
    }

    ll ask(ll x)
    {
		ll pos = lower_bound(pnt.begin(),pnt.end(),x) - pnt.begin();

		return query2(0,n,pos,1);
    }
};

ll ans[1000];
Line line[100005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		Lichao tree;

		for(ll i = 350; i <= 100000; i++)
		{
			tree.pnt.push_back(i);
		}

		tree.init();

		slld(n);

		for(ll i = 0; i <= 350; i++) ans[i] = mxlld;

		for(ll i = 1; i <= n; i++)
		{
			slld(line[i].a0);
			slld(line[i].a1);
			slld(line[i].a2);
			slld(line[i].a3);

			for(ll j = 0; j <= 350; j++)
			{
				ans[j] = min(ans[j], tree.f(line[i],j));
			}

			tree.update(line[i]);
		}

		slld(m);

		for(ll i = 1; i <= m; i++)
		{
			slld(input);

			if(input <= 350)
			{
				printf("%lld\n", ans[input]);
			}
			else
			{
				printf("%lld\n", tree.ask(input));
			}
		}
    }
}

/*

1
5
516 13216 5132 125
13126 511 515 13
258 0 6895 258
3 0 3 0
100000 100000 100000 1000
5
400
500
800
1000
10000


*/



