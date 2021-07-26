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

pair < ll, ll > arr[30];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    ll cnt = 1;
    for(i = 2; i <= 6; i++)
    {
        for(j = 1; j <= 3; j++)
        {
            arr[cnt++] = make_pair(i,j);

        }
    }

        for(j = 1; j <= 4; j++)
        {
            arr[cnt++] = make_pair(7LL,j);

        }

        for(j = 1; j <= 3; j++)
        {
            arr[cnt++] = make_pair(8LL,j);

        }

        for(j = 1; j <= 4; j++)
        {
            arr[cnt++] = make_pair(9LL,j);
        }


    slld(n);

    string x;

    for(i = 0; i < n; i++)
    {
        cin >> x;

        ll sz = x.size();

        ans = 0;

        for(j = 0; j < sz; j++)
        {
            cnt = x[j] - 'a' + 1;

            ans += arr[cnt].second;
        }

        cout << ans << endl;

        flag = 0;
        for(j = 0; j < sz; j++)
        {
            cnt = x[j] - 'a' + 1;

            m = arr[cnt].second;

            for(k = 0; k < m; k++)
            {
                if(flag) printf(" ");
                else flag = 1;

                printf("%lld", arr[cnt].first);
            }
        }

        cout << endl;
    }


}



