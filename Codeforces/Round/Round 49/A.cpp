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

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    string in;
    getline(cin,in);

    string vow = "aeiouy";

    ll sz= in.size();

    for(i = 0; i < sz; i++)
    {
        if(in[i] >= 'A' && in[i] <= 'Z')
        {
            in[i] += ('a' - 'A');
        }
    }

    bool on = 0;
    for(ll i = sz - 1; i >= 0; i--)
    {
        if(in[i] >= 'a' && in[i] <= 'z')
        {
            //cout << in[i] << endl;
            for(j = 0; j < vow.size(); j++)
            {
                //cout << vow[j] << endl;
                if(in[i] == vow[j])
                {
                    on = 1;
                    break;
                }
            }

            break;
        }
    }

    //cout << on << endl;

    if(on) cout << "YES" << endl;
    else cout << "NO" << endl;


}

