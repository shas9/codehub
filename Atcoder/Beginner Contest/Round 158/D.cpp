// God put a smile upon your face <3

#include <bits/stdc++.h>

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

deque < char > dq;
string s;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> s)
    {
		dq.clear();

		for(auto it: s) dq.push_back(it);

		bool rev = 0;

		cin >> m;

		for(ll i = 1; i <= m; i++)
		{
			ll t;

			cin >> t;

			if(t == 1) rev ^= 1;
			else
			{
				ll f;
				char c;
				cin >> f >> c;

				if(rev)
				{
					if(f == 2) dq.push_front(c);
					else dq.push_back(c);
				}
				else
				{
					if(f == 1) dq.push_front(c);
					else dq.push_back(c);
				}
			}
		}

		if(rev) reverse(dq.begin(),dq.end());

		for(auto it: dq) cout << it;

		cout << "\n";
    }


}


