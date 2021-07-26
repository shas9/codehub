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


bool solve(ll a, ll b)
{
	if(a > b) return 0;

	if(a % 2 == 0 && b % 2 == 1) return 0;

	ll ret1 = 0, ret2 = 0;
	ll last1 = -1;
	ll last2 = -1;

	for(ll i = 40; i >= 0; i--)
	{
		if(check(a,i))
		{
			ret1++;
			last1 = i;
		}
	}

	for(ll i = 40; i >= 0; i--)
	{
		if(check(b,i))
		{
			ret2++;
			last2 = i;
		}
	}

	return ret1 >= ret2 && last2 >= last1;
}

bool solve1(ll a, ll b)
{
	if(a > b) return 0;

	ll ret1 = 0, ret2 = 0;

	for(ll i = 0; i <= 40; i++)
	{
		if(check(a,i))
		{
			ret1++;
		}

		if(check(b,i))
		{
			ret2++;
		}

		if(ret2 > ret1) return 0;
	}

	return 1;
}


void test(ll x, ll y)
{
	set < ll > st;

	map < ll, bool > vis;

	queue < ll > qq;

	qq.push(x);
	vis[x] = 1;

	while(!qq.empty())
	{
		ll top = qq.front();
		qq.pop();
		st.insert(top);

		for(ll i = 1; i <= top; i++)
		{
			if((top & i) != i) continue;
			if(vis.find(i + top) != vis.end() || i + top > y) continue;

			vis[i + top] = 1;
			qq.push(i + top);
		}
	}

	for(auto it: st)
	{
		cout << x << " " << it << " ";

		for(ll i = 5; i >= 0; i--) cout << check(it,i);

		cout << endl;
	}

	for(ll i = 1; i <= y; i++)
	{
		cout << x << " " << i << " ";

		cout << vis[i] << " " << solve1(x,i) << endl;

		if(vis[i] != solve1(x,i))
		{
			cout << x << " " << i << endl;
			cout << vis[i] << " " << solve1(x,i) << endl;

			assert(0);
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

//		for(ll i = 1; i <= 13; i++)
//		{
//			test(i,63);
//
//			cout << endl;
//		}

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> n >> m;

		if(solve1(n,m)) cout << "Yes\n";
		else cout << "No\n";
    }


}



