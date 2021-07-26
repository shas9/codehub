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

string s, t;
vector < ll > missed;


ll solve()
{
	ll one = 0;

	for(auto it: s) one += (it == '1');
	for(auto it: t) one -= (it == '1');

	if(one != 0) return -1;

	missed.clear();

	for(ll i = 0; i < s.size(); i++)
	{
		if(s[i] != t[i]) missed.push_back(s[i] - '0');
	}

	ll ret = 0;

	ll hand[2]= {0,0};

	for(auto it: missed)
	{
		ll need = it ^ 1;

		if(hand[need] == 0) ret++;
		else hand[need]--;

		hand[it]++;
	}

	return ret;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> s >> t)
    {
		ans = solve();

		printf("%lld\n", ans);
	}


}




