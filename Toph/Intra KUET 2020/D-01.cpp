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

const ll mod = 1000001677;
const ll base = 1000001351;
ll ibase[2000006];

string s;

string solve(string &t1, string &t2)
{
	ibase[0] = 1;

	for(ll i = 1; i <= (t1.size() + t2.size()); i++) ibase[i] = (ibase[i - 1] * base) % mod;

	ll len1 = 0, len2 = 0;

 	string ret1 = "";
 	string ret2 = "";

	for(ll i = 0, fwd = 0, rev = 0; i < t1.size(); i++)
	{
		fwd = ((fwd * base) % mod + t1[i]) % mod;
		rev = (((ibase[i] * t1[i]) % mod) + rev) % mod;

//		cout << fwd << " " << rev << endl;

		if(fwd == rev) len1 = i + 1;
 	}

 	for(ll i = 0; i < len1; i++) ret1.pb(t1[i]);

 	for(ll i = 0, fwd = 0, rev = 0; i < t2.size(); i++)
	{
		fwd = ((fwd * base) % mod + t2[i]) % mod;
		rev = (((ibase[i] * t2[i]) % mod) + rev) % mod;

		if(fwd == rev) len2 = i + 1;
 	}

 	for(ll i = 0; i < len2; i++) ret2.pb(t2[i]);

 	if(len1 < len2) return ret2;

 	if(len2 < len1) return ret1;

 	return min(ret1,ret2);
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    string a, b;

    while(cin >> a >> b)
    {
		string ans = "";

		ll idx1 = 0;
		ll idx2 = b.size() - 1;

		bool shesh = 0;

		while(idx1 < a.size() && idx2 >= 0)
		{
			if(a[idx1] == b[idx2])
			{
				ans.pb(a[idx1]);
				idx1++;
				idx2--;
			}
			else
			{
				break;
			}
		}

		string tans = ans;

		reverse(tans.begin(),tans.end());

		string t1 = "", t2 = "";

		while(idx1 < a.size()) t1.pb(a[idx1]), idx1++;
		while(idx2 >= 0) t2.pb(b[idx2]), idx2--;

//		cout << ans << " " << t1 << " " << t2 << endl;

		ans += solve(t1,t2);

		ans += tans;

		cout << ans << '\n';
    }


}



