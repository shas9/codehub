// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)

#define ll int
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

ll arr[200005];
ll wat[200005];
set < ll > st;

void update(ll idx, ll x)
{
	if(st.empty()) return;

 	set < ll > :: iterator it = lower_bound(st.begin(),st.end(),idx);

	while(x)
	{
		if(it == st.end()) return;
		ll s = *it;

		if(wat[s] + x < arr[s])
		{
			wat[s] += x;
			return;
		}

		x -= abs(arr[s] - wat[s]);
		wat[s] = arr[s];

		it = st.erase(it);
	}
}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		st.clear();
		for(i = 1; i <= n; i++) slld(arr[i]), st.insert(i), wat[i] = 0;

		slld(m);

		for(i = 1; i <= m; i++)
		{
			ll t;
			slld(t);
			slld(k);

			if(t == 1)
			{
				ll x;
				slld(x);

				update(k, x);
			}
			else
			{
				printf("%d\n", wat[k]);
			}
		}

    }


}

