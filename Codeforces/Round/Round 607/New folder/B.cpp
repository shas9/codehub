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

string a, b;

bool solve()
{
    if(a.size() < b.size())
    {
        ll i;

        for(i = 0; i < a.size(); i++)
        {
			if(a[i] < b[i]) return 1;
            if(a[i] != b[i]) break;
        }

        if(i == a.size()) return 1;
    }


    for(ll i = 0; i < min(a.size(),b.size()); i++)
    {
        for(ll j = a.size() - 1; j > i ; j--)
        {
            if(a[j] < b[i])
            {
                swap(a[j],a[i]);
                return 1;
            }
        }

        if(a[i] > b[i]) break;
    }

    for(ll i = 0; i < min(a.size(),b.size()); i++)
    {
        if(a[i] < b[i]) return 1;

        for(ll j = i + 1; j < a.size(); j++)
        {
            if(j < b.size() && a[j] == b[i] && b[j] > a[i])
            {
                swap(a[j],a[i]);
                return 1;
            }
        }

        if(a[i] > b[i]) break;
    }

    for(ll i = 0; i < min(a.size(),b.size()); i++)
    {
        if(a[i] < b[i]) return 1;

        if(a[i] > b[i])
        {
            for(ll j = a.size() - 1; j > i; j--)
            {
                if(a[j] == b[i])
                {
					swap(a[j],a[i]);
					break;
                }
            }

            break;
        }
    }

    if(a.size() < b.size())
    {
        ll i;
        for(i = 0; i < a.size(); i++)
        {
			if(a[i] < b[i]) return 1;
            if(a[i] != b[i]) break;
        }

        if(i == a.size()) return 1;
    }
    else
    {
		for(ll i = 0; i < min(a.size(),b.size()); i++)
		{
			if(a[i] < b[i]) return 1;
		}
    }

    return 0;
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
        cin >> a >> b;

        if(solve()) cout << a << "\n";
        else cout << "---" << "\n";
    }


}


