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

pll bt[11];

ll ask(ll i, ll j)
{
	ll ret;

	cout << "? " << i << " " << j << endl;

	cin >> ret;

	assert(ret != -1);

	return ret;
}

ll magic(ll idx)
{
	ll ret = (1 << 11) - 1;

	for(ll i = 0; i < 11; i++)
	{
		if(bt[i].first != idx) ret = (ret & ask(idx,bt[i].first));
		else ret = (ret & ask(idx,bt[i].second));
	}

	return ret;
}

ll arr[3000];

void ans(ll n)
{
	cout << "! ";

	for(ll i = 1; i <= n; i++) cout << arr[i] << " ";

	cout << endl;
}

bool nope()
{
	for(ll i = 0; i < 11; i++) if(bt[i].first == -1) return 1;

	return 0;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    memset(bt,-1,sizeof bt);

    slld(n);

    while(nope())
    {
		ll x = rand() % n;
		ll y = rand() % n;

		if(x == y) continue;

		x++;
		y++;

		ll vv = ask(x,y);

		for(ll i = 0; i < 11; i++)
		{
			if(check(vv,i) == 0)
			{
				bt[i] = {x,y};
			}
		}
    }

//    bug;

    ll val = magic(1);
    ll idx = 1;

//    bug;

    for(ll i = 2; i <= n; i++)
    {
		if(ask(idx,i) == val)
		{
			val = magic(i);
			idx = i;
		}
    }

//    bug;

    for(ll i = 1; i <= n; i++)
    {
		if(i != idx) arr[i] = ask(idx,i);
    }

//    bug;

    ans(n);

}



