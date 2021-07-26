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
    ll input, flag, tag;

    ll len;

    vector < ll > ans;

    slld(n);
    slld(len);

    ans.clear();



    flag = n;

    ll temp, cnt, num;

    i = 1;

    if(n * 2 == len)
    {
        for(i = 1; i <= len; i++)
        {
            ans.pb(-1);
        }
    }
    else
    {
        if(n % 2 == 1)
        {
            n--;
            len--;

            ans.pb(0);
        }

        if(len == 1)
        {
            for(i = 1; i <= len; i++)
            {
                if(pow(2,i) == n)
                {
                    ans.pb(i);
                }

                if(pow(2,i) > n)
                {
                    n = 0;
                    break;
                }
            }
        }

        flag = n;
        while(flag > 0)
        {

            for(i = 1; i <= 62; i++)
            {
                temp = pow(2,i);

                if(temp * len == flag)
                {
                    flag = 0;
                }

                if(flag == 0)
                {
                    for(j = 1; j <= len; j++)
                    {
                        ans.pb(i);
                    }

                    break;
                }

                if(temp * len > flag)
                {
                    flag = 0;
                    break;
                }
            }

            break;
        }

    }

    sort(ans.begin(), ans.end());


    if(ans.size() < len)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;

        for(i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i];

            if(i != 0)
            {
                cout << " ";
            }
        }

        cout << endl;
    }

    return 0;
}


