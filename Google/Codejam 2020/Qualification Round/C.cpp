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

struct interval
{
    ll s, e, id;
} arr[1003];

bool comp(interval a, interval b)
{
    if(a.s == b.s)
        return a.e < b.e;

    return a.s < b.s;
}

vector < pll > v1, v2;

char str[1003];

ll solve(ll n)
{
    v1.clear();
    v2.clear();

    ll i;

    for(i = 1; i <= n; i++)
    {
        if(v1.size() == 0)
        {
            v1.push_back(make_pair(arr[i].e, arr[i].id));
        }
        else if(v2.size() == 0)
        {
            v2.push_back(make_pair(arr[i].e, arr[i].id));
        }
        else
        {
            if(v1[v1.size() - 1].first <= arr[i].s)
            {
                v1.push_back(make_pair(arr[i].e, arr[i].id));
            }
            else if(v2[v2.size() - 1].first <= arr[i].s)
            {
                v2.push_back(make_pair(arr[i].e, arr[i].id));
            }
            else
            {
                return -1;
            }
        }
    }

    for(i = 0; i < v1.size(); i++)
    {
        str[v1[i].second] = 'C';
    }

    for(i = 0; i < v2.size(); i++)
    {
        str[v2[i].second] = 'J';
    }

    str[n + 1] = '\0';
    return 1;


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
        slld(n);

        for(i = 1; i <= n; i++)
        {
            slld(arr[i].s);
            slld(arr[i].e);

            arr[i].id = i;
        }

        sort(arr + 1, arr + 1 + n, comp);

        ans = solve(n);

        printf("Case #%lld: ", cs);

        if(ans == -1) cout << "IMPOSSIBLE" << endl;
        else cout << str + 1 << endl;
    }


}

