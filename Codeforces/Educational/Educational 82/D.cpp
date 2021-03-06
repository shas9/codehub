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

ll arr[100005];
vector < ll > vec;
ll pw[100];

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
        slld(n);
        slld(m);
        memset(pw,0,sizeof pw);

        for(i = 1; i <= m; i++)
        {
            slld(input);

            for(j = 0; j < 40; j++)
                if(check(input,j))
                {
                    pw[j]++;
                    break;
                }
        }

        ans = 0;

        for(i = 0; i < 62; i++)
        {
            if(check(n,i))
            {
                ll sum = (1LL << i);

//                cout << "SUM: " << sum << endl;

                for(j = i; j >= 0 && sum > 0; j--)
                {
                    ll x = (1LL << j);

                    ll y = sum / x;

                    sum -= min(y,pw[j]) * x;
                    pw[j] -= min(y,pw[j]);
                }

                if(sum == 0) continue;

//                bug;

                for(j = i + 1; j < 40; j++)
                {
                    if(pw[j])
                    {
                       while(j > i)
                       {
                           pw[j]--;
                           pw[j - 1] += 2;
                           j--;
                           ans++;
                       }

                       pw[j]--;
                       sum = 0;

                       break;
                    }
                }

//                cout <<"Last sum: " << sum << endl;

                if(sum != 0)
                {
                    ans = -1;
                    break;
                }
            }
        }

        cout << ans << endl;
    }


}



