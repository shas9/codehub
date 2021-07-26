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

#define mod 1000000007


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

void append(ll st, ll lim)
{
	string tmp = "";

	ll cnt = (str[st] - '0') - 1;

	for(ll i = st + 1; i < str.size(); i++) tmp += str[i];

	while(str.size() + 1 < lim && cnt--)
	{
		str += tmp;
	}
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
		cin >> n;
		cin >> str;

		ans = str.size();
//		cout << n << " " << str<< endl;

		for(i = 0; i < n; i++)
		{
//			cout << str << " ~~ ";

			if(ans < n) append(i,n);

//			cout << str << endl;

			ans = (ans + (str[i] - '0' - 1) * (ans - (i + 1))) % mod;

//			cout << ans << " ++ " << str.size() << endl;

		}

		cout << ans << "\n";
    }


}



