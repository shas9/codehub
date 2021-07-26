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

string str;

vector < ll > one;

bool free(ll idx, ll k)
{
	if(str[idx] == '1') return 0;

	for(ll i = idx - 1; i >= max(0LL,idx - k); i--) if(str[i] == '1') return 0;
	for(ll i = idx + 1; i <= min((long long) str.size() - 1,idx + k); i++) if(str[i] == '1') return 0;

	str[idx] = '1';
	return 1;
}

bool freee(ll idx, ll k)
{
	auto it = lower_bound(one.begin(),one.end(),idx);

	if(it != one.end())	if(*it <= (idx + k)) return 0;

	if(it == one.begin()) return 1;

	it--;
	if(*it >= (idx - k)) return 0;

	return 1;
}

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
		slld(k);

		cin >> str;

		one.clear();

		for(i = 0; i < n; i++) if(str[i] == '1') one.push_back(i);

		ans = 0;

		for(i = 0; i < n; i++)
		{
			if(freee(i,k)) ans++, i += k;
		}

		printf("%lld\n", ans);
    }


}



