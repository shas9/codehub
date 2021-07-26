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
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll cnt[1000006];
ll num[1000006];
ll arr[1000006];
ll dis[1000006];

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
        ll tot;

        slld(tot);

        ll indd = 1;

        for(i = 1; i <= tot; i++)
        {
            slld(arr[i]);

            if(i == 1 || arr[i - 1] != arr[i])
            {
                dis[indd] = arr[i];
                indd++;

                cnt[arr[i]] = 0;
            }

            cnt[arr[i]]++;
        }

        ll g, s, b;

        g = s = b = 0;

        g = cnt[dis[1]];

        for(i = 2; i < indd; i++)
        {
            if(s + cnt[dis[i]] > g)
            {
                s += cnt[dis[i]];
                i++;
                break;
            }

            s += cnt[dis[i]];
        }

        for(; i < indd; i++)
        {
            if(b + g + s + cnt[dis[i]] > (tot / 2))
                break;

            {
                b += cnt[dis[i]];
            }
        }

//        cout << g << " -- " << s << " " << b << endl;


        if(g + s + b > (tot / 2))
        {
            cout << "0 0 0" << endl;
        }
        else if(g >= s || g >= b)
        {
            cout << "0 0 0" << endl;
        }
        else
        {
            cout << g << " " << s << " " << b << endl;
        }
    }


}


