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
vector < string > st, t1, t2;
bool vis[1000];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    getline(cin,str);
    {
		ll words = 1;

		for(auto it: str)
		{
			if(it == ' ') words++;
		}

		st.clear();
		t1.clear();
		t2.clear();

		memset(vis,0,sizeof vis);

		slld(n);

		for(i = 1; i <= n; i++)
		{
			cin >> str;
			st.push_back(str);
		}

		ll idx = -1;
		bool one = 0;

		while(t1.size() + t2.size() < n)
		{
			ll cnt = 0;

			while(cnt < words)
			{
				idx = (idx + 1) % n;

				if(vis[idx] == 0) cnt++;
			}

			vis[idx] = 1;

			if(one == 0) t1.push_back(st[idx]);
			else t2.push_back(st[idx]);

			one ^= 1;

		}

		cout << t1.size() << "\n";

		for(auto it: t1) cout << it << "\n";

		cout << t2.size() << "\n";

		for(auto it: t2) cout << it << "\n";
    }



}



