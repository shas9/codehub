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
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    while(cin >> n >> k >> m)
    {
        flag = n - 1;
        flag *= k;

        if(flag < m || k > m)
        {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;

        flag = m / k;

        if(m % k)
        {
            flag++;
        }

        ans = 0;

        for(i = 1; i < k; i++)
        {
            if(i % 2) cout << flag + 1 << " ";
            else cout << 1 << " ";
        }

        ans = (k - 1) * flag;
        ans = m - ans;

        //cout << ans << " " << flag <<endl;
        if(k % 2) cout << 1 + ans << endl;
        else cout << 2 << endl;





    }


}

