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

char str[100000];

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
        scanf("%s", str + 1);
        ll len = strlen(str + 1);

        str[0] = '0';
        str[len + 1] = '0';

        len++;

        printf("Case #%lld: ", cs);
        for(i = 1; i <= len; i++)
        {
            ll pr = str[i - 1] - '0';
            ll nw = str[i] - '0';

            ll diff = abs(nw - pr);

            if(nw > pr)
            {
                while(diff--) cout << '(';
            }
            else if(pr > nw)
            {
                while(diff--) cout << ')';
            }

            if(i < len) cout << str[i];
        }

        cout << endl;
    }




}



