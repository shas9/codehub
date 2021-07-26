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

        bool tagg = 0;

        for(i = 1; i < sz - 1; i++)
        {
            if(str[i] == '?')
            {
                if(str[i - 1] != 'c' && str[i + 1] != 'c')
                {
                    str[i] = 'c';
                }
                else if(str[i - 1] != 'a' && str[i + 1] != 'a')
                {
                    str[i] = 'a';
                }
                else if(str[i - 1] != 'b' && str[i + 1] != 'b')
                {
                    str[i] = 'b';
                }
            }
            else if(str[i - 1] == str[i] || str[i] == str[i + 1])
            {
                cout << -1 << endl;
                tagg = 1;
                break;
            }
        }

        if(tagg) continue;

        if(str.size() == 1)
        {
            if(str[0] == '?') cout << 'a' << endl;
            else cout << str << endl;

            continue;
        }
        if(str.size() == 2)
        {
            if(str[0] == str[1])
            {
                cout << -1 << endl;
                continue;
            }
        }

        if(str[sz - 1] == '?')
        {
            if(str[sz - 2] == 'a') str[sz - 1] = 'b';
            else str[sz - 1] = 'a';
        }

        if(str[0] == '?')
        {
            if(str[1] == 'a') str[0] = 'b';
            else str[0] = 'a';
        }

        cout << str << endl;
    }


}


