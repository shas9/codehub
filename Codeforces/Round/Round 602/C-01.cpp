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

string ss, tt;
vector < pll > vv;


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
		k--;
		cin >> ss;

		vv.clear();

		tt = "";

		for(i = 1; i <= k; i++)
		{
			tt += "()";
		}

		ll diff = ss.size() - tt.size();

		for(i = 1; i <= diff; i++)
		{
			if(i <= (diff/ 2)) tt += '(';
			else tt += ')';
		}

		for(i = 0; i < n; i++)
		{
			if(ss[i] == tt[i]) continue;

			string tmp = ss;

			for(j = i + 1; j < n; j++)
			{
				if(ss[j] == tt[i]) break;
			}

			vv.push_back({i + 1, j + 1});
			for(m = i; j >= i; m++, j--)
			{
				tmp[m] = ss[j];
			}

			ss = tmp;
		}

		cout << vv.size() << "\n";

		for(auto it: vv) cout << it.first << " " << it.second << "\n";

//		cout << ss << endl;
    }


}



