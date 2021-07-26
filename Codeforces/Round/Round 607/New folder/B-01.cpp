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

string s, sorteds, c;

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
		cin >> s >> c;

		sorteds = s;

		sort(sorteds.begin(),sorteds.end());

		for(i = 0; i < s.size(); i++)
		{
			if(s[i] == sorteds[i]) continue;

			for(j = s.size() - 1; j > i; j--)
			{
				if(s[j] == sorteds[i])
				{
					swap(s[i],s[j]);
					break;
				}
			}

			if(j > i) break;
		}

		if(s < c)
		{
			cout << s << "\n";
		}
		else
		{
			cout << "---" << "\n";
		}
    }


}



