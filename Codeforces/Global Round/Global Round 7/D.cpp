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

#define mod 999995713


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

string str;
string str1, str2;

ll h[1000006];
ll rh[1000006];
ll pw[1000006];

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}


ll solve()
{

    ll base = 811;

    for(ll i = 0; i < str2.size(); i++)
    {
        if(i)
        {
            h[i] = h[i - 1];
        }
        else
        {
            h[i] = 0;
        }

        h[i] += str2[i] * pw[i];

        h[i] %= mod;

//        cout << h[i] << " ";
    }

//    cout << endl;

    for(ll i = str2.size() - 1, j = 0; i >= 0; i--, j++)
    {
        if(i < str2.size() - 1)
        {
            rh[i] = rh[i + 1];
        }
        else
        {
            rh[i] = 0;
        }

        rh[i] += str2[i] * pw[j];

        rh[i] %= mod;
    }

    ll ret = 0;

    for(ll i = 0; i < str2.size(); i++)
    {

        ll xx = rh[0];

        if(i < str.size() - 1)
        {
            xx = ((rh[0] - rh[i + 1] + mod) % mod) * power(pw[str2.size() - i - 1],mod - 2, mod);

            xx %= mod;

//            cout << ((rh[0] - rh[i + 1] + mod) % mod) << " ~~ " << power(pw[str2.size() - i - 1],mod - 2, mod) <<  " ~~ " << pw[str2.size() - i - 1] <<endl;
//            cout << xx << " " << h[i] << endl;

        }
        if(xx == h[i])
        {
            ret = max(ret, i + 1);
        }
    }

    return ret;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    pw[0] = 1;

    for(i = 1; i <= 1000000; i++)
    {
        pw[i] = pw[i - 1] * 811;
        pw[i] %= mod;
    }

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> str;
//        cout << str << " ";

        i = 0;
        j = str.size() - 1;

        str1 = "";
        while(i <= j && str[i] == str[j])
        {
            str1 += str[i];
            i++;
            j--;
        }

        if(i > j)
        {
            cout << str << endl;
            continue;
        }

        str2 = "";

        for(; i <= j; i++)
        {
            str2 += str[i];
        }
//        cout << str2 << endl;

        ans = 0;

//        memset(h,0,sizeof h);
//        memset(rh,0,sizeof rh);

//        cout << str2 << endl;
        ll ans1 = solve();

        reverse(str2.begin(),str2.end());

//        cout << str2 << endl;
        ll ans2 = solve();

//        cout << ans1 << " " << ans2 << endl;
        if(ans2 > ans1)
        {
            cout << str1;

            for(i = 0; i < ans2; i++)
            {
                cout << str2[i];
            }

            reverse(str1.begin(),str1.end());

            cout << str1 << endl;
        }
        else
        {
            cout << str1;

            reverse(str2.begin(),str2.end());

            for(i = 0; i < ans1; i++)
            {
                cout << str2[i];
            }

            reverse(str1.begin(),str1.end());

            cout << str1 << endl;
        }

    }


}



