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

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);
		vec.clear();

		for(ll i = 0; i < n; i++)
		{
			slld(input);
			vec.push_back(input);
		}

		ll cnt = 0;

		while(!vec.empty() && vec.back() == n) vec.pop_back(), n--;

		bool on = 0;

		for(ll i = 0; i < n; i++)
		{
			if(vec[i] == i + 1)
			{
				if(on == 0) continue;
				else cnt++;
			}
			else on = 1;
		}

		if(cnt == n) printf("0\n");
		else if(cnt == 0) printf("1\n");
		else printf("2\n");
    }


}



