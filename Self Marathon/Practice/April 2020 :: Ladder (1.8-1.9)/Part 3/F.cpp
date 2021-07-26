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

#define mod 1000000007

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

ll fact[300];

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}


ll _nCr(ll n, ll r)
{
    if(r > n) return 0;

    ll z = ((power(fact[r], mod - 2, mod)) * (power(fact[n - r], mod - 2, mod))) % mod;
    return (fact[n] * z) % mod;
}

void precalc()
{
    fact[0] = 1;

    for(ll i = 1; i <= 300; i++)
    {
        fact[i] = (i * fact[i - 1]) % mod;
    }
}

struct node
{
	ll w1, w2, st, cnt, trav;

	node(ll a, ll b, ll c, ll d, ll e)
	{
		w1 = a;
		w2 = b;
		st = c;
		cnt = d;
		trav = e;
	}


};



ll small, big, k;

bool vis[55][55][2];

pll bfs()
{
	set < node > qq;

	qq.insert(	node(small,big,0,1,0));

	memset(vis,0,sizeof vis);

	vis[small][big][0] = 1;

	pll ret = {mxlld,0};

	while(!qq.empty())
	{
		node top = qq.front();
		qq.pop();

		for(ll i = 0; i <= top.w1; i++)
		{
			for(ll j = 0; j <= top.w2; j++)
			{
				ll ww = (i * 50) + (j * 100);

				if(i + j == 0) continue;
				if(ww > k) continue;

				node psh = node(0,0,0,0,0);
				psh.w1 = (small - (top.w1 - i));
				psh.w2 = (big - (top.w2 - j));
				psh.st = top.st ^ 1;
				psh.trav = top.trav + 1;
				psh.cnt = (top.cnt * (_nCr(top.w1,i) * _nCr(top.w2,j)) % mod) % mod;

				if(psh.w1 == small && psh.w2 == big && psh.st == 1)
				{
					if(ret.first == psh.trav) ret.second += psh.cnt;
					else if(ret.first > psh.trav) ret = {psh.trav, psh.cnt};
				}

				if(vis[psh.w1][psh.w2][psh.st]) continue;

				vis[psh.w1][psh.w2][psh.st] = 1;
				qq.push(psh);
			}
		}
	}

	if(ret.first == mxlld) ret.first = -1;
	return ret;
}

int main()
{
    ll i, j, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	precalc();

	while(cin >> n >> k)
	{
		small = 0;
		big = 0;

		for(i = 1; i <= n; i++)
		{
			slld(input);

			if(input == 50)small++;
			else big++;
		}

		pll ans = bfs();

		printf("%lld\n%lld\n",ans.first, ans.second);
	}

}



