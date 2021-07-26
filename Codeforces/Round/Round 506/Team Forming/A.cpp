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

ll paldig[50];
ll cumsum[50];
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    paldig[0] = 1;
    paldig[1] = paldig[2] = 10;

    for(i = 3; i <= 20; i++)
    {
        paldig[i] = paldig[i - 2] * 10;
    }

    cumsum[1] = cumsum[2] = 9;

    for(i = 3; i <= 20; i++)
    {
        cumsum[i] = cumsum[i - 2] * 10;
    }

    for(i = 1; i <= 20; i++)
    {
        cumsum[i] += cumsum[i - 1];
    }

//    cout << cumsum[20] << endl;


    while(scanf("%lld", &n) != EOF)
    {
        string x = "";

        flag = n;

        while(n > 9)
        {
            ll digit = 0;
            for(i = 1; i <= 20; i++)
            {
                if(cumsum[i] > n)
                {
                    digit = i - 1;
                    n -= cumsum[digit];
                    break;
                }
            }

//            cout << n << "-&& " << endl;
//            cout << digit << endl;

            digit = max(digit - 2, 1LL);

            ll temp = n / paldig[digit];

            x += temp + '0';
        }

        ll dig = 0;

        for(i = 1; i <= 20; i++)
        {
            if(flag < cumsum[i])
            {
                dig = i;
                break;
            }
        }

        cout << x;

        if(dig % 2 == 0) cout << n << n;
        else cout << n;

        reverse(x.begin(),x.end());

        cout << x << endl;
    }


}


