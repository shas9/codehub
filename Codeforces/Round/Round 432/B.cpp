
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

int main()
{
    ll i, j, k, l, m, n, o, f;
    ll testcase;
    ll flat[2000];
    ll max_flat_floor[2000];
    ll quest;
    ll max_floor = 0;

    ll flat_floor;

    ll flag, tag;
    flag = -1;

    for(i = 0; i < 2000; i++)
    {
        flat[i] = -100;
        max_flat_floor[i] = -100;
    }

    scanlld(quest);
    scanlld(testcase);

    for(i = 1; i <= testcase; i++)
    {
        scanlld(k);
        scanlld(f);

        flat[k] = f;

        if(max_floor < f)
        {
            max_floor = f;
        }

        if(max_flat_floor[f] < k)
        {
            max_flat_floor[f] = k;
        }

        if(flat[k + 1] == (flat[k] + 1))
        {
            bug;
            flag = k;
            flat_floor = k / flat[k];
        }
        else if(flat[k] == (flat[k - 1] + 1))
        {
            bug;
            flag = k - 1;
            flat_floor = flag / flat[k - 1];
        }
    }

    ll ans;

    if(flag == -1)
    {
        for(i = 1; i < 1000; i++)
        {
            if(max_flat_floor[i] > quest)
            {
                i--;
                break;
            }
        }

        if(i == 1000)
        {
            i = max_floor;
        }

        tag = quest / max_flat_floor[1];

        //printf("tag = %lld, i = %lld\n", tag, i);

        if(tag < i)
        {
            ans = i;
        }
        else
        {
            ans = -1;
        }
    }
    else if(quest % flat_floor == 0)
    {
        ans = quest / flat_floor;
    }
    else
    {
        ans = quest / flat_floor;
        ans++;
    }

    printlld(ans);


}

