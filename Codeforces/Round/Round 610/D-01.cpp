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

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    ll inp1, inp2, inp;;

    string str = "";

    ll sz = 0;

    cout << 'a' << endl;

    cin >> inp1;

    if(inp1 == 0) exit(0);

    cout << 'b' << endl;

    cin >> inp2;

    if(inp2 == 0) exit(0);

    if(inp1 == inp2) sz = inp1;
    else
    {
        if(inp1 > inp2)
        {
            for(i = 1; i <= inp1; i++) str += 'b';
        }
        else
        {
            for(i = 1; i <= inp2; i++) str += 'a';
        }

        cout << str << endl;

        cin >> inp;

        exit(0);
    }

    for(i = 1; i <= sz; i++) str[i] += 'a';

}



