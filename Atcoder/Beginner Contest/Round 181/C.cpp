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

pll arr[103];

bool solve(ll n)
{
    for(ll i = 1; i <= n; i++)
    {
		for(ll j = i + 1; j <= n; j++)
		{
			for(ll k = j + 1; k <= n; k++)
			{
				if(arr[i].first == arr[j].first)
				{
					if(arr[i].first == arr[k].first)
					{
						return 1;
					}

					continue;
				}

				if(arr[i].first == arr[k].first)
				{
					continue;
				}

				if(arr[j].first == arr[k].first)
				{
					continue;
				}


				long double m1 = (arr[i].second - arr[j].second) * 1.0 / (arr[i].first - arr[j].first);
				long double m2 = (arr[i].second - arr[k].second) * 1.0 / (arr[i].first - arr[k].first);
				long double m3 = (arr[k].second - arr[j].second) * 1.0 / (arr[k].first - arr[j].first);

				if(abs(m1 - m2) <= 0.00000000001 && abs(m1 - m3) <= 0.00000000001)
				{
//					cout << setprecision(10) << fixed << m1 << " " << m2 << " " << m3 << endl;
//					cout << i << " " << j << " " << k << endl;
					return 1;
				}
			}
		}
    }

    return 0;
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
        for(ll i = 1; i <= n; i++) cin >> arr[i].first >> arr[i].second;

        if(solve(n)) cout << "Yes" << "\n";
        else cout << "No\n";
    }

}



