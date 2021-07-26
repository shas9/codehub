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

string str[5];
ll mis[5];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);


    for(i = 1; i <= 3; i++) cin >> str[i];

    ll sz = str[1].size();

    ans = 0;

        for(i = 0; i < sz; i++)
        {
            if(str[1][i] == str[2][i] && str[2][i] == str[3][i]) ans++;
        }

        ll temp = sz - ans;

        if(temp <= 1)
        {
            for(i = 0; i < sz; i++)
            {
                cout << str[1][i];
            }
            cout << endl;
            return 0;
        }

    for(i = 0; i < sz; i++)
    {
        flag = 0;
        for(j = 1; j <= 3; j++)
        {
            for(k = j + 1; k <= 3; k++)
            {
                if(str[j][i] == str[k][i])
                {
                    flag++;
                }
            }
        }

        if(flag > 1) ans++;
    }

    temp = sz - ans;

    if(temp == 1)
    {
        cout << "Ambiguous" << endl;
        return 0;
    }

    if(temp > 1)
    {
        cout << "Impossible" << endl;
        return 0;
    }

//    bug;

    for(i = 0; i < sz; i++)
    {
        if(str[1][i] == str[2][i] || str[1][i] == str[3][i])
        {
            cout << str[1][i];
        }
        else
        {
            cout << str[2][i];
        }
    }

    cout << endl;


}


