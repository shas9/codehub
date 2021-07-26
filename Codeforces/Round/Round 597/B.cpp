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

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		string s, t;
		t = "";
		ll a, b, c;

		cin >> n >> a >> b >> c >> s;

		ll cnt = 0;
		for(auto it: s)
		{
			if(it == 'S')
			{
				if(a > 0)
				{
					cnt++;
					a--, t += 'R';
				}
				else
				{
					t += '#';
				}
			}
			else if(it == 'P')
			{
				if(c > 0)
				{
					cnt++;
					c--, t += 'S';
				}
				else
				{
					t += '#';
				}
			}
			else
			{

				if(b > 0)
				{
					cnt++;
					b--, t += 'P';
				}
				else
				{
					t += '#';
				}
			}
		}

		if(cnt < ((n + 1) / 2)) printf("No\n");
		else
		{
			printf("Yes\n");

			for(ll i = 0; i < t.size(); i++)
			{
				if(t[i] == '#')
				{
					if(a) t[i] = 'R', a--;
					else if(b) t[i] = 'P', b--;
					else t[i] = 'S', c--;
				}
			}

			cout << t << "\n";
		}
    }


}




