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

vector < ll > ans[1000];

bool rem(ll ind)
{
    ll last = -1;
    ll br = -1;

    bool on = 0;

    ll i = 0;
    ll j = str.size() - 1;

//    cout << i << " " << j << " " << str << endl;

    while(i <= j)
    {
        if(str[i] == '(')
        {
            while(str[j] != ')' && i <= j)
            {
//                cout << str[j] << endl;
                j--;
            }

//            cout << i << " " << j << endl;

            if(i > j) break;

            str[i] = '*';
            str[j] = '*';

            ans[ind].push_back(i + 1);
            ans[ind].push_back(j + 1);
            on = 1;
        }
        i++;
    }

    sort(ans[ind].begin(),ans[ind].end());

    return on;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    ll ind = 0;

    string tmp;
    while(cin >> str)
    {
        ind = 0;
        while(rem(++ind))
        {
            tmp = "";

            bool on = 0;

            for(i = 0; i < str.size(); i++)
            {
                if(str[i] == '*')continue;

                on = 1;

                tmp += str[i];
            }

            if(on == 0)
            {
                ind++;
                break;
            }

            str = tmp;
        }

        ind--;

        cout << ind << endl;

        for(i = 1; i <= ind; i++)
        {
            cout << ans[i].size() << endl;

            for(j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }

            cout << endl;
        }



        for(i = 1; i <= ind; i++)
            ans[i].clear();

    }


}


