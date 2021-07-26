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

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    ll a, b;

    while(cin >> n >> k >> a >> b)
    {
        ans = (n - 1) * a;

        if(k == 1)
        {
            cout << ans << endl;
            continue;
        }

        flag = 0;
        while(n > 1)
        {
            if(n < k)
            {
                flag += ((n - 1) * a);
                break;
            }
            if(n % k == 0)
            {
                ll temp = (n - (n / k));

                if(temp * a < b)
                {
                    flag += (temp * a);
                }
                else
                {
                    flag += b;
                }

                n /= k;
            }
            else
            {
                tag = n % k;

                flag += (tag * a);

                n -= tag;
            }

//            cout << n << " " << flag << endl;
        }

        ans = min(ans,flag);
        cout << ans << endl;
    }


}


