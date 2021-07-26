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

#define mxlld 99999999999999999
#define mnlld -99999999999999999

#define mxd 99999999
#define mnd 99999999

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    string in;

    slld(m);

    cin >> in;

    char check[] = "aeiouy";

    for(i = 0; i < in.size(); i++)
    {
        for(j = 0; j < 6; j++)
        {
            if(check[j] == in[i])
            {
                if(flag == 1)
                {
                    in[i] = '_';
                    break;
                }
                flag = 1;
                break;
            }
        }

        if(j == 6)
        {
            flag  = 0;
        }
    }

    for(i = 0; i < in.size(); i++)
    {
        if(in[i] != '_')
        {
            cout << in[i];
        }
    }


}


