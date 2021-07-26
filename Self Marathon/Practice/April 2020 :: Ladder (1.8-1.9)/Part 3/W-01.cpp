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

multiset < ll > st;
ll arr[100005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		ll sum = 0;

		for(i = 1; i <= n; ++i)
		{
			slld(arr[i]);
			sum += arr[i];
		}

		st.clear();

		for(i = 1; i <= n; i++) st.insert(sum - arr[i]);

//		for(auto it: st) cout << it << " !! ";
//
//		cout << endl;

		ll x;
		while(!st.empty())
		{
			x = *(st.begin());
			ll cnt = 0;

			for(multiset < ll > :: iterator it = st.begin(); it != st.end(); it = st.erase(it))
			{
				if(x != *it) break;
				cnt++;
			}

//			cout << x << " ~~ " << cnt << endl;

			if(cnt % m) break;

			for(i = 1; i <= (cnt / m); i++) st.insert(x + 1);
		}

		ans = min(x,sum);

//		cout << *st.begin() << " " << sum << endl;

		printf("%lld\n", power(m,ans,mod));
    }


}


