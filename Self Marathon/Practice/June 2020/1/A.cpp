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

vector < pll > vec;

ll ask(ll n)
{
	ll r;

	cout << n << endl;

	cin >> r;

	assert(r != -1);

	if(r == 0)
	{
		exit(0);
	}

	return r;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    vec.clear();

    vec.resize(3);

    for(ll i = 0; i < 3; i++)
    {
		cin >> vec[i].first;
		vec[i].second = i + 1;
    }

    cout << "First" << endl;

    ll last = -1;

    ans = 0;

    while(++ans)
    {
		sort(vec.begin(),vec.end());

//		for(ll i = 0; i < 3; i++)
//		{
//			cout << vec[i].first << " " << vec[i].second << '\n';
//		}

		if(vec[2].first - vec[1].first == vec[1].first - vec[0].first && last == vec[2].second)
		{
//			bug;
			ask(vec[2].first - vec[1].first);

			assert(0); // game ends;
		}

		ll c = 2 * vec[2].first - (vec[1].first + vec[0].first);

		last = ask(c);

		for(ll i = 0; i < 3; i++)
		{
			if(vec[i].second == last)
			{
				vec[i].first += c;
			}
		}

		assert(ans <= 1000);
    }



}


