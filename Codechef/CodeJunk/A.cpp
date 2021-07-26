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

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

vector < ll > vec;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		vec.clear();

		for(ll i = 0; i < n; i++)
		{
			slld(input);

			vec.push_back(input);
		}

		sort(vec.rbegin(),vec.rend());

		ll a = -1, b, c;

		for(ll i = 0; i + 2 < n; i++)
		{
			if(vec[i] < (vec[i + 1] + vec[i + 2]))
			{
				a = vec[i];
				b = vec[i + 1];
				c = vec[i + 2];
				break;
			}
		}

		if(a == -1) cout << "NO\n";
		else cout << "YES\n" << a << " " << b << " " << c << endl;
    }


}



