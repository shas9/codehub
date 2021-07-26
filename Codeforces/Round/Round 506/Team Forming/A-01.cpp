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
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

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
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

ll cumsum[50];
ll pow10[50];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
//    slld(testcase);

    pow10[1] = pow10[2] = 1;

    for(i = 3; i <= 22; i++)
    {
        pow10[i] = pow10[i - 2] * 10;
    }

    cumsum[1] = cumsum[2] = 9;

    for(i = 3; i <= 22; i++)
    {
        cumsum[i] = cumsum[i - 2] * 10;
    }


    while(scanf("%lld", &n) != EOF)
    {
        ll flag = 0;
        ll digit = 0;

        string x = "";

        for(i = 1; i <= 22; i++)
        {
            if(flag + cumsum[i] >= n)
            {
                digit = i;
                break;;
            }
            flag += cumsum[i];
        }

        ll temp = (n - flag) / pow10[digit];


        if(temp == 0) temp++;
        x += (temp + '0');

        n %= pow10[digit];


        while(n > 0)
        {
            ll d = 0;
            flag = 0;

            for(i = 1; i <= 22; i++)
            {
                if(flag + cumsum[i] >= n)
                {
                    d = i;
                    break;
                }
                flag += cumsum[i];
            }

            temp = (n - flag) / pow10[d];
            temp++;
            temp %= 10;
            x += (temp + '0');

            n %= pow10[d];
        }

        cout << x;
        reverse(x.begin(),x.end());
        if(digit % 2 == 0) cout << x << endl;
        else
        {
            ll sz = x.size();

            for(i = 1; i < sz; i++) cout << x[i];

            cout << endl;
        }




    }



}

//

