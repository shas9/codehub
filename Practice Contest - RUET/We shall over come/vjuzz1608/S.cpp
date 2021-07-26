#include <bits/stdc++.h>`

#define scanlld(longvalue) scanf("%lld", &longvalue)
#define printlld(longvalue) printf("%lld\n", longvalue)

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

ll high_bound = 500000000;

ll high, low, mid;

ll calc(ll mid)
{
    ll i, j;

    ll ans = 0;
    i = 1;
    j = 5;

    while((mid / j) != 0)
    {
        ans += (mid / pow(5,i));
        i++;
        j *= 5;
    }

    return ans;
}

ll binary(ll input)
{
    low = 1;
    high = high_bound;
    ll ans = 0;

    while(low <= high)
    {
        mid = (high + low) / 2;

        if(calc(mid) == input)
        {
            ans = mid;
            high = mid - 1;
        }
        else if(calc(mid) > input)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if(ans != 0)
    {
        return ans;
    }

    return - 1;

}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input;


    map < ll, ll > saved;

    scanlld(testcase);

    saved.clear();

    for(i = 1; i <= testcase; i++)
    {
        scanlld(input);

        if(saved[input] != 0)
        {
            if(saved[input] == -1)
            {
                printf("Case %lld: impossible\n", i);
            }
            else
            {
                printf("Case %lld: %lld\n", i, saved[input]);
            }
        }
        else
        {
            ll ans = binary(input);

            saved[input] = ans;

            if(ans == -1)
            {
                printf("Case %lld: impossible\n", i);
            }
            else
            {
                printf("Case %lld: %lld\n", i, ans);
            }
        }
    }


}


