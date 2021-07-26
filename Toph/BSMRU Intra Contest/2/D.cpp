// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

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

vector < vector < ll > > grid[2];

ll query(ll st, ll tt, ll idx)
{
       ll sum=0;
       while(idx>0){
             sum+=	grid[st][tt][idx];
             idx -= idx & (-idx);
       }
       return sum;
}

void update(ll st, ll tt, ll idx, ll x, ll n) //n is the size of the array, x is the number to add
{
       while(idx<=n)
       {
             grid[st][tt][idx]+=x;
             idx += idx & (-idx);
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
    slld(q);

    for(i = 0; i <= n; i++)
    {
		grid[0].push_back({0});

		for(j = 1; j <= m * 5; j++)
		{
			grid[0].back().push_back(0);
		}
    }

    for(i = 0; i <= m; i++)
    {
		grid[1].push_back({0});

		for(j = 1; j <= n * 5; j++)
		{
			grid[1].back().push_back(0);
		}
    }

    ll cx, cy;

    slld(cx);
    slld(cy);

    for(i = 1; i <= q; i++)
    {
		ll t, u, v;
		slld(t);
		slld(u);
		slld(v);

		if(t == 2)
		{
			slld(r);

			ll stl = max(1LL,u - r);
			ll str = min(n,u + r);

			update(1,v,stl,1,n);
			if(str < n) update(1,v,str + 1, -1, n);

			ll ttl = max(1LL, v - r);
			ll ttr = min(m, v + r);
//
//			cout << stl << " ~~ " << str << endl;
//			cout << ttl << " !! " << ttr << endl;

			update(0,u,ttl,1,m);

			if(ttr < m) update(0,u,ttr + 1, -1, m);

			u = cx;
			v = cy;
		}
//
//		cout << "grid of x: " << endl;
//		for(j = 1; j <= n; j++)
//		{
//			for(k = 1; k <= m; k++)
//			{
//				cout << query(0,j,k) << " ";
//			}
//
//			cout << endl;
//		}
//
//		cout << "grid of y: " << endl;
//
//		for(j = 1; j <= m; j++)
//		{
//			for(k = 1; k <= n; k++)
//			{
//				cout << query(1,j,k) << " ";
//			}
//
//			cout << endl;
//		}

//			cout << u << " && " << v <<endl;  /// checked

			ll a = query(0,u,v);

//			cout << a << " %% ";
//			if(v > 1) a -= query(0,u,v - 1);

			ll b = query(1,v,u);

//			cout << b << endl;

//			if(u > 1) b -= query(1,v,u - 1);

//			cout << a << " " << b << endl;

			if(a | b) printf("Opps! I’m dead\n");
			else printf("I can’t be defeated\n");

			cx = u;
			cy = v;
    }


}



