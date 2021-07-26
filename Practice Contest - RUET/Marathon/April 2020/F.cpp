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

#define mod 1000000009


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll ww[103];
ll pp[103];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);
    ll sum = 0;
    ll totp = 0;
    for(i = 1; i <= n; i++)
    {
		ll lo = sum + 1;
		ll hi = 10000;

		cout << 1 << " " << i << " " << 10000 << endl;
		cin >> input;

		pp[i] = input - totp;

		ll xx = lo;

		while(lo <= hi)
		{
			ll mid = (lo + hi) / 2;

			cout << 1 << " " << i << " " << mid << endl;

			cin >> flag;

			if(flag == input)
			{
				xx = mid;
				hi = mid - 1;
			}
			else
			{
				lo = mid + 1;
			}
		}

		ww[i] = xx - sum;

		sum = xx;
		totp = input;
    }

    cout << 2 << endl;

    for(i = 1; i <= n; i++) cout << ww[i] << " ";
    cout << endl;

    for(i = 1; i <= n; i++) cout << pp[i] << " ";
    cout << endl;


}



