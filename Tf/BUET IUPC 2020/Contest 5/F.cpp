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

map < string, ll > mp1, mp2;

string str, strr;

ll arr[500005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    mp1.clear();
    mp2.clear();
    memset(arr,0,sizeof arr);

    ll cnt = 0;

    while(1)
    {
        cnt++;

        for(i = 1; i <= 4; i++)
        {
            cin >> str;

            if(str[0] == '-') break;

            if(i == 2)
            {
                mp1[str] = cnt;
            }

            if(i == 4)
            {
                mp2[str] = cnt;
            }
        }

        if(str[0] == '-') break;
    }

    ans = 0;

    while(1)
    {
        cin >> str;

        if(str[0] == 'E') break;

        if(str[0] == '+')
        {
            cin >> strr;
            cin >> str;

            if(strr[0] == 't')
            {
                arr[mp2[str]]++;
                ans++;
            }
            else
            {
                arr[mp1[str]]++;
                ans++;
            }
        }
        else if(str[0] == 'U')
        {
            cout << ans << endl;
        }
        else if(str[0] == '-')
        {
            cin >> strr;
            cin >> str;

            if(strr[0] == 't')
            {
                arr[mp2[str]]--;
                ans--;
            }
            else
            {
                arr[mp1[str]]--;
                ans--;
            }
        }
        else if(str[0] == 'F')
        {
            cin >> strr;
            cin >> str;

            if(strr[0] == 't')
            {
                if(arr[mp2[str]])
                {
                    cout << "FOUND" << endl;
                }
                else
                {
                    cout << "404" << endl;
                }
            }
            else
            {
                if(arr[mp1[str]])
                {
                    cout << "FOUND" << endl;
                }
                else
                {
                    cout << "404" << endl;
                }
            }
        }
    }


}


