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

vector < ll > v;

void solve2(ll n)
{
    if(n & 1)
    {
        cout << 1 << " " << (n - 1) / 2 << " " << (n - 1) / 2 << " ";
    }
    else if(n % 4 == 0)
    {
        cout << n / 2 << " " << n / 4 << " " << n / 4 << " ";
    }
    else
    {
        cout << 2 << " " << (n - 2) / 2 << " " << (n - 2) / 2 << " ";
    }
}

void solve(ll n, ll m)
{

	ll tot = m / 3;
	ll div = (n / tot);
	ll rem = (n % tot);

	if(rem == 0 && m % 3)
	{
		div--;
		rem += tot;
	}

	if(rem == 1 && m % 3 == 2)
	{
		div--;
		rem += tot;
	}


	for(ll i = 1; i <= tot; i++)
	{
		solve2(div);
	}

	if(m % 3 == 2)
	{
		if(rem & 1)
		{
			v.push_back(1);
			v.push_back(rem - 1);
		}
		else
		{
			v.push_back(rem / 2);
			v.push_back(rem / 2);
		}
	}

	if(m % 3 == 1)
	{
		v.push_back(rem);
	}

	return;


}

void solve4(ll n, ll m)
{

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
		cin >> n >> m;

		v.clear();

		solve(n,m);

		for(auto it: v)
		{
			cout << it << " ";
		}

		cout << "\n";
    }


}



