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

void rem(ll get)
{
    for(ll i = 0; i < str.size(); i++)
    {
        if((str[i] - 'a') != get) continue;

        ll j = i - 1;

        while(j >= 0)
        {
            if(str[j] == '*')
            {
                j--;
                continue;
            }

            ll ch = str[j] - 'a';

            if(ch + 1 == get)
            {
                str[i] = '*';
            }

            j--;

            break;
        }

        if(str[i] == '*') continue;

        j = i + 1;

        while(j < str.size())
        {
            if(str[j] == '*')
            {
                j++;
                continue;
            }

            ll ch = str[j] - 'a';

            if(ch + 1 == get)
            {
                str[i] = '*';
            }
            j++;
            break;
        }
    }

    for(ll i = str.size() - 1; i >= 0; i--)
    {
        if((str[i] - 'a') != get) continue;

        ll j = i - 1;

        while(j >= 0)
        {
            if(str[j] == '*')
            {
                j--;
                continue;
            }

            ll ch = str[j] - 'a';

            if(ch + 1 == get)
            {
                str[i] = '*';
            }

            j--;

            break;
        }

        if(str[i] == '*') continue;

        j = i + 1;

        while(j < str.size())
        {
            if(str[j] == '*')
            {
                j++;
                continue;
            }

            ll ch = str[j] - 'a';

            if(ch + 1 == get)
            {
                str[i] = '*';
            }
            j++;
            break;
        }
    }
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        cin >> str;

        n = str.size();

        for(i = 25; i > 0; i--)
        {
            rem(i);

            string tmp = "";

            for(j = 0; j < str.size(); j++)
            {
                if(str[j] == '*') continue;

                tmp += str[j];
            }

            str = tmp;
        }



//        cout << str << endl;

        cout << n - str.size() << endl;
    }


}


