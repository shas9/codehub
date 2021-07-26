#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

string input;

ll vagfol;
ll vagsesh;

void solve()
{
    vagfol = 0;
    vagsesh = 0;
    ll sz = input.size();

    for(ll i = 0; i < sz; i++)
    {

        if(input[i] == '9')
        {
            vagfol *= 10;
            vagfol += 1;
            continue;
        }

        if(input[i] == '0')
        {
            vagfol *= 10;
            continue;
        }

        if(i == sz - 1)
        {
            if(input[i] != '9')
            vagsesh = input[i] - '0';
            break;

        }

        ll temp = (input[i] - '0') * 10 + (input[i+1] - '0');

        ll rem = temp % 9;
        ll res = temp / 9;

        vagfol *= 10;
        vagfol += res;

        if(rem == 0) i++;
        else
        {
            input[i+1] = rem + '0';
        }
    }
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll flag, tag, ans;

    // freopen("in.txt", "r", stdin);


    while(1)
    {
        cin >> input;
        //cout << " " << input << endl;

        if(input[0] == '-') exit(0);
        if(input[0] == '0')
        {
            cout << 1 << endl;
            continue;
        }

        solve();

        if(vagsesh == 0) ans = vagfol;
        else ans = vagfol + 1;


        cout << ans << endl;
    }


}


