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

using namespace std;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    slld(testcase);

    ll month, w;
    string day;

    ll weeks[10];



    for(ll cs = 1; cs <= testcase; cs++)
    {
        memset(weeks,0,sizeof(weeks));

        cin >> month >> day;

        if(day == "mon")
        {
            w = 1;
        }
        else if(day == "tues")
        {
            w = 2;
        }
        else if(day == "wed")
        {
            w = 3;
        }
        else if(day == "thurs")
        {
            w = 4;
        }
        else if(day == "fri")
        {
            w = 5;
        }
        else if(day == "sat")
        {
            w = 6;
        }
        else if(day == "sun")
        {
            w = 7;
        }

        for(i = 1; i <= 7; i++)
        {
            flag = i;
            for(j = 1; j <= 10; j++)
            {
                if(flag > month)
                {
                    break;
                }
                else
                {
                    ll temp = (w + i - 1) % 7;

                    if(temp == 0)
                    {
                        temp = 7;
                    }

                    weeks[temp]++;

                    flag += 7;
                }
            }
        }

        for(i = 1; i <= 7; i++)
        {
            printf("%lld", weeks[i]);

            if(i != 7)
            {
                printf(" ");
            }
        }

        printf("\n");
    }


}


