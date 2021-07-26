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
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    while(cin >> str[1] >> str[2] >> str[3])
    {
        ll sz = str[1].size();
        ll two = 0;
        ll three = 0;

        str[4] = "";

        flag = 0;
        for(i = 0; i < sz; i++)
        {
            for(j = 1; j <= 3; j++)
            {
                if(str[j][i] )
            }
        }

        if((str[1] == str[2] || str[2] == str[3] || str[1] == str[3]) && str[3].size() <= 3)
        {
            cout << "Ambiguous" << endl;
            continue;
        }

        for(i = 0; i < sz; i++)
        {
            if(str[1][i] == str[2][i] || str[1][i] == str[3][i])
            {
                str[4] += str[1][i];
            }
            else if(str[2][i] == str[3][i])
            {
                str[4] += str[2][i];
            }
        }

        if(str[4].size() == str[3].size())
        {
            cout << str[4] << endl;
            continue;
        }

        for(i = 0; i < sz; i++)
        {
            if(str[1][i] == str[2][i] && str[2][i] == str[3][i] && str[1][i] == str[3][i])
            {
                three++;
            }
        }

        ll temp = sz - three;

        if(temp <= 1)
        {
            cout << "Ambiguous" << endl;
            continue;
        }

        ll null = 0;
        ll pos = 0;
        for(i = 0; i < sz; i++)
        {
            if(str[1][i] != str[2][i] && str[2][i] != str[3][i] && str[1][i] != str[3][i])
            {
                null++;
            }

            flag = 0;

            for(j = 1; j <= 3; j++)
            {
                for(k = j + 1; k <= 3; k++)
                {
                    if(str[j][i] == str[k][i]) flag++;
                }
            }

            if(flag == 1)
            {
                if(str[1][i] == str[2][i]) pos = 3;
                else if(str[3][i] == str[2][i]) pos = 1;
                else pos = 2;

                two++;
            }
        }

//        cout << two << " " << null << endl;

        if(null == 1 && two == 1)
        {
            for(i = 0; i < sz; i++)
            {
                if(str[1][i] == str[2][i] || str[1][i] == str[3][i])
                {
                    cout << str[1][i];
                }
                else if(str[2][i] == str[3][i])
                {
                    cout << str[2][i];
                }
                else cout << str[pos][i];
            }

            cout << endl;
            continue;
        }

        cout << "Impossible" << endl;
    }


}



