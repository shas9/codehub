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

ll func(string x)
{
    cout << x << endl;

    ll ret;

    cin >> ret;

    if(ret == 0) exit(0);

    return ret;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    const ll mx = 300;

    ll alla = func(string(mx,'a'));

    ll allb = func(string(mx,'b'));

    ll sz = (2 * mx) - (alla + allb);

    string str = string(sz,'a');

    ll prv = 300 - allb;

    if(alla == 300) func(string(sz,'b'));
    else if(allb == 300) func(string(sz,'a'));

    for(i = 0; i < (sz - 1); i++)
    {
        str[i] = 'b';
        ll x = func(str);

        if(x > prv)
        {
            str[i] = 'a';
        }
        else
        {
            prv = x;
        }
    }

    if(sz > 1)
    {
        str[(sz - 1)] = 'b';
        func(str);
    }
    else
    {
        if(alla > allb) func(string(sz,'b'));
        else func(string(sz,'a'));
    }


}


