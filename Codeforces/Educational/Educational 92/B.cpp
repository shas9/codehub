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

ll arr[100005];
vector < ll > vec;
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> n >> k >> m;

		for(ll i = 1; i <= n; i++) cin >> arr[i];

		ll sum = 0;

		for(ll i = 1; i <= k + 1; i++) sum += arr[i];

		ll now = k + 1;

		ll mx = 0;
		ll pos = 0;

		for(ll i = 1; i <= k; i++)
		{
			if(mx < arr[i] + arr[i + 1])
			{
				pos = i + 1;
				mx = arr[i] + arr[i + 1];
			}
		}

//		cout << pos << " " << mx << endl;

		for(ll i = 1; i <= m && now > pos; i++)
		{
//			cout << sum << " ~ ";
			sum -= arr[now] + arr[now - 1];
			sum += mx;

//			cout << sum << endl;

			now -= 2;
		}

		cout << sum << "\n";
    }


}



