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

ll cnt[6][100005];
ll fff[6];

string str;
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
        cin >> str;

        ll sz = str.size();

        for(i = 0; i < sz; i++)
        {
            if(str[i] == 'U')
            {
                cnt[1][i] = 1;
                cnt[2][i] = 0;
                cnt[3][i] = 0;
                cnt[4][i] = 0;
            }
            else if(str[i] == 'D')
            {
                cnt[1][i] = 0;
                cnt[2][i] = 1;
                cnt[3][i] = 0;
                cnt[4][i] = 0;
            }
            else if(str[i] == 'L')
            {
                cnt[1][i] = 0;
                cnt[2][i] = 0;
                cnt[3][i] = 1;
                cnt[4][i] = 0;
            }
            else if(str[i] == 'R')
            {
                cnt[1][i] = 0;
                cnt[2][i] = 0;
                cnt[3][i] = 0;
                cnt[4][i] = 1;
            }
        }


        for(i = sz - 2; i >= 0; i--)
        {
            for(j = 1; j <= 4; j++)
            {
                cnt[j][i] += cnt[j][i + 1];
            }
        }


    }


}


