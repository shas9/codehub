// God put a smile upon your face <3

#include <bits/stdc++.h>

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

ll a[100005];
ll b[100005];
ll mp[100005];

ll x;

ll getNextX()
{
    x = (x * 37 + 10007) % 1000000007;
    return x;
}

vector < ll > one;

void initAB(ll n, ll d)
{
    for(ll i = 0; i < n; i = i + 1)
    {
        a[i] = i + 1;
    }
    for(ll i = 0; i < n; i = i + 1)
    {
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(ll i = 0; i < n; i = i + 1)
    {
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(ll i = 0; i < n; i = i + 1)
    {
        swap(b[i], b[getNextX() % (i + 1)]);
    }

    for(ll i = 0; i < n; i++)
    {
		mp[a[i]] = i;
    }

    one.clear();

    for(ll i = 0; i < n; i++) if(b[i]) one.push_back(i);
}

bool is(ll x, ll i)
{
	ll pos = mp[x];

	if(pos > i) return 0;

	ll dist = i - pos;

	assert(dist >= 0);

	return b[dist];
}

ll cnt;
ll cnt2;
ll solve(ll pos, ll n)
{
	ll ret = 0;

	for(auto it: one)
	{
		cnt++;
		if(it > pos) break;

		ret = max(ret, a[pos - it]);
	}

	return ret;

}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> x)
    {
		cnt2 = cnt = 0;
		initAB(n,m);

		for(ll i = 0; i < n; i++)
		{
			ans = solve(i, n);

			printf("%lld\n", ans);
		}

//		cout << " ~~ " << cnt << " " << cnt2 << endl;
    }


}



