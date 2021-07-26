
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

#define printcase(indexing) printf("Case %lld: ", indexing)

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

    char str[20];

    slld(testcase);


    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n >> str;
        ans = 0;

        for(i = 2; i <= n; i++)
        {
            flag = 1;
            for(j = 2; j < i; j++)
            {
                if(i % j == 0)
                {
                    flag = 0;
                    break;
                }
            }

            ll sum = 0;

            if(flag)
            {
                //cout << " " << i << endl;
                for(k = 1; k <= i; k++)
                {
                    sum += k;
                }

                if(str[0] == 'e')
                {
                    if(sum % 2 == 0)
                    {
                        //cout << 1 << " " << sum << " " << i << endl;
                        ans = max(ans,i);
                    }
                }
                else
                {
                    if(sum % 2 == 1)
                    {
                        //cout << 2 << " " << sum << " " << i << endl;
                       ans = max(ans,i);
                    }
                }
            }
        }

        if(ans == 0)
        {
            printcase(cs);
            cout << "Faizlami Naki?" << endl;
            continue;
        }
        printcase(cs);
        plld(ans);
    }


}

