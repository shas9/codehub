#include <bits/stdc++.h>`

#define scanlld(longvalue) scanf("%lld", &longvalue)
#define printlld(longvalue) printf("%lld\n", longvalue)

#define scanlf(longvalue) scanf("%lf", &longvalue)
#define printlf(longvalue) printf("%lf\n", longvalue)
#define scanc(letter) scanf("%c", &letter)
#define printc(letter) printf("%c", letter)

#define scans(name) scanf("%s", name)
#define prints(name) printf("%s", name)

#define printnewline printf("\n")

#define ll long long

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")


using namespace std;

    vector < ll > value;
    vector < ll > eq1;
    vector < ll > eq2;

ll low(ll ans)
{
    ll high = eq2.size() - 1;
    ll low = 0;
    ll mid;

    ll res = 0;

    while(low <= high)
    {
        mid = (high + low) / 2;

        if(eq2[mid] == ans)
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }


    return res;
}

ll high(ll ans)
{
    ll high = eq2.size() - 1;
    ll low = 0;
    ll mid;

    ll res = 0;

    while(low <= high)
    {
        mid = (high + low) / 2;

        if(eq2[mid] == ans)
        {
            res = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return res;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

       clock_t begin, end;
       double time_spent;
    begin = clock();

    {
        value.clear();
        eq1.clear();
        eq2.clear();

        scanlld(n);

        for(j = 0; j < n; j++)
        {
            scanlld(input);

            value.push_back(input);
        }

        for(j = 0; j < n; j++)
        {
            for(k = 0; k < n; k++)
            {
                for(l = 0; l < n; l++)
                {
                    input = (value[j] * value[k]) + value[l];
                    eq1.push_back(input);
                }
            }
        }

        for(j = 0; j < n; j++)
        {
            for(k = 0; k < n; k++)
            {
                for(l = 0; l < n; l++)
                {
                    if(value[l] != 0)
                    {
                        input = (value[j] + value[k]) * value[l];
                        eq2.push_back(input);
                    }

                }
            }
        }

        sort(eq1.begin(),eq1.end());
        sort(eq2.begin(),eq2.end());

        ll ans = 0;

        for(j = 0; j < eq1.size(); j++)
        {
            ll x = lower_bound(eq2.begin(),eq2.end(),eq1[j]) - eq2.begin();
            ll y = upper_bound(eq2.begin(),eq2.end(),eq1[j]) - eq2.begin();

            ans += (y - x);
        }

        printlld(ans);

           end = clock();
           time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
           cerr<<"Time spent = "<<time_spent<<endl;
    }

    return 0;

}


