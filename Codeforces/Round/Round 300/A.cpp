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

void no()
{
    cout << "NO" << endl;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    string x = "CODEFORCES";
    string inn;

    while(cin >> inn)
    {
        if(inn.size() < 10)
        {
            no();
            continue;
        }

        ll cnt = 0;

        j = 0;

        for(i = 0; i < 10; i++)
        {
            if(inn[i] == x[i]) cnt++;
            else break;
        }

        j = 9;
        for(i = inn.size() - 1; i >= 0; i--)
        {
            if(inn[i] == x[j]) cnt++, j--;
            else break;

            if(j == 10) break;
        }

        if(cnt > 9) cout << "YES" << endl;
        else cout << "NO" << endl;


    }


}


