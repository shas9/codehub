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

#define maxn 200005
using namespace std;

bool check(ll n, ll pos)
{
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

ll arr[maxn];
ll lft[maxn], rgt[maxn];
ll nxt1[maxn];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    while(cin >> n >> k)
    {
        ans = 0;
        nxt1[n + 1] = n + 1;
        for(i = 1; i <= n; i++)
        {
            lft[i] = 0;
            rgt[i] = 0;
            nxt1[i] = 0;

            slld(arr[i]);
        }

        for(i = 1; i <= n; i++)
        {
            if(arr[i] == 1)
            {
                lft[i] = lft[i - 1] + 1;
            }
        }

        for(i = n; i >= 1; i--)
        {
            if(arr[i] == 1)
            {
                rgt[i] = rgt[i + 1] + 1;

                nxt1[i] = nxt1[i + 1];
            }
            else
            {
                nxt1[i] = i + 1;
            }
        }

        for(i = 1; i <= n; i++)
        {
            ll one = lft[i - 1];
            ll p = 1, x = 0, y;

            for(j = i; j <= n;)
            {
                if(p > 2000000000000000000)
                {
                    break;
                }

                one = rgt[j + 1];

                p *= arr[j];
                x += arr[j];

                if(p == k * x)
                {
                    ans++;
                    one -= rgt[j + 1];

                    cout << i << " && " << j << endl;
                    continue;
                }





               if(p > (k * x) )
               {
                   y = p - (k * x);

//                   cout << y << endl;
                   if(y % k == 0)
                    {
                        y /= k;

                        if(y <= one)
                        {
                            cout << i << " " << j << endl;
                            ans++;

                        }

                    }
               }


                one -= rgt[j + 1];


                if(arr[j] == 1)
                {
                    x += rgt[j + 1];
                }

                cout << j << " -- ";
                j = nxt1[j];

                cout << j << endl;


            }
        }

        plld(ans);
    }


}


