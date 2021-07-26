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

string s, t;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    fastio;

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> n;
		cin >> s >> t;

		vector < ll > op;
		op.clear();

		for(ll i = n - 1; i >= 0; i--)
		{
			if(s[i] == t[i]) continue;

			if(i)
			{
				if(s[0] == t[i]) op.push_back(1);
				if(s[0] == t[i]) s[0] = ((s[0] - '0') ^ 1) + '0';
			}
			else
			{
				s[0] = ((s[0] - '0') ^ 1) + '0';
			}

			op.push_back(i + 1);

			if(i == 0) break;

			string ss = "";

			for(ll j = i; j >= 0; j--)
			{
				ss.pb(((s[j] - '0') ^ 1) + '0');
			}

			cout << ss;

			for(ll j = i + 1; j < n; j++)
			{
				ss.pb(s[j]);
			}

			s = ss;

			cout << " @@ " << s << endl;
		}

		assert(op.size() <= (3 * n));

		cout << op.size() << " ";

		for(auto it: op) cout << it << " ";

		cout << endl;

		cout << s << " ~~ " << t << endl;
    }


}




