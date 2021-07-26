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

string str[2000];

int main()
{
    ll i, j, k, l, m, n, o, r, q, kk;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    while(cin >> n >> kk)
    {
        for(i = 1; i <= n; i++)
        {
            cin >> str[i];
        }

        ans = 0;
        for(i = 1; i <= n; i++)
        {
            for(j = i + 1; j <= n; j++)
            {
                for(k = j + 1; k <= n; k++)
                {
                    ll diff = 0;

                    for(l = 0; l < kk; l++)
                    {
                        if(str[i][l] != str[j][l] && str[k][l] != str[j][l] && str[i][l] != str[k][l]) diff++;
                        else if(str[i][l] == str[j][l] && str[i][l] == str[k][l]);
                        else break;
                    }


                    if(l != kk) continue;

//                    bug;
                    ans++;
                }
            }
        }

        cout << ans << endl;
    }


}


