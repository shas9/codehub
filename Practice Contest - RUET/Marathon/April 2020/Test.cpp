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

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		vector < ll > vec(n + 100000);

		for(i = 0; i < n; i++)
		{
			slld(vec[i]);
		}

		bool on = 1;

		for(i = n; i <= 10000; i++)
		{
			ll sum = 0;
			for(j = i - 1, k = 1; k <= n; j--, k++)
			{
				sum += vec[j];
			}

			vec[i] = sum / n;
		}

		for(i = 10000; i > 0; i--)
		{
			if(vec[i] != vec[i - 1])
			{
				cout << "Sequence starts from: " << i + 1 << endl;
				break;
			}
		}

		for(i = 0; i < 100; i++)
		{
			cout << vec[i] << " ";
		}

		cout << endl;
    }


}



