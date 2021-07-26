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

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    string str;

    ll cnt[5];

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> str;

        memset(cnt, 0, sizeof cnt);

        for(i = 0; i < str.size(); i++)
        {
            if(str[i] == 'U') cnt[1]++;
            if(str[i] == 'D') cnt[2]++;
            if(str[i] == 'R') cnt[3]++;
            if(str[i] == 'L') cnt[4]++;
        }

        cnt[1] = min(cnt[1],cnt[2]);
        cnt[3] = min(cnt[3], cnt[4]);

        if(cnt[1] == 0 && cnt[3] == 0)
        {
            cout << 0 << endl << endl;
            continue;
        }
        else if(cnt[1] == 0)
        {
            cout << 2 << endl << "LR" << endl;
            continue;
        }
        else if(cnt[3] == 0)
        {
            cout << 2 << endl << "UD" << endl;
            continue;
        }
        cout << cnt[1] * 2 + cnt[3] * 2 << endl;

        for(i = 0; i < cnt[1]; i++)
        {
            cout << 'U';
        }

        for(i = 0; i < cnt[3]; i++)
        {
            cout << 'R';
        }

        for(i = 0; i < cnt[1]; i++)
        {
            cout << 'D';
        }

        for(i = 0; i < cnt[3]; i++)
        {
            cout << 'L';
        }

        cout << endl;
    }


}

