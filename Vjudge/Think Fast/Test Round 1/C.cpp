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

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    string str;

    while(cin >> str)
    {
		ll sz = 0;
		ans = 1;
		ll cnt = 0, sum = 0;

		for(auto it: str)
		{
			if(it == ')') sum--;
			else sum++;

			cnt++;

			if(sum < 0)
			{
				sum = 0;
				cnt = 0;
			}
			else if(sum == 0)
			{
				if(sz < cnt) sz = cnt, ans = 0;

				if(sz == cnt) ans++;
			}
		}

		reverse(str.begin(),str.end());

		ll sz1 = 0;
		ll ans1 = 1;
		ll cnt1 = 0, sum1 = 0;

		for(auto it: str)
		{
			if(it == '(') sum--;
			else sum++;

			cnt1++;

			if(sum1 < 0)
			{
				sum1 = 0;
				cnt1 = 0;
			}
			else if(sum1 == 0)
			{
				if(sz1 < cnt1) sz1 = cnt1, ans1 = 0;

				if(sz1 == cnt1) ans1++;
			}
		}

		if(sz < sz1) sz = sz1, ans = ans1;
		else if(sz == sz1) ans = max(ans,ans1);

		cout << sz << " " << ans << '\n';
    }


}



