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


void solve(ll n, ll m)
{
//	cout << n << " " << m << "\n";
    if(m == 1)
    {
        v.push_back(n);
        return;
    }

    if(m == 2)
    {
        if(n & 1)
        {
            v.push_back(n - 1);
            v.push_back(1);
        }
        else
        {
            v.push_back(n / 2);
            v.push_back(n / 2);
        }

        return;
    }

    if(n & 1)
    {
        v.push_back(1);
        m--;
        n--;
    }


    solve(n / 2, m / 2);
    solve(n / 2, m - (m / 2));
}

void solve2(ll n, ll m)
{
	for(ll i = 0; i < m; i++)
	{
		if(n & 1) v.push_back(1), n--;
		else v.push_back(n / 2), n /= 2;
	}

	return;
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

        solve2(n,m);

        for(auto it: v)
        {
            cout << it << " ";
        }

        cout << "\n";
    }


}



