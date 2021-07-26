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

ll n;
ll K;
ll campsite[1010];
ll sums[1010];

bool check(ll expected_max)
{
    ll sum = 0;
    ll part = 0;

    for(ll i = 1; i <= n; i++)
    {
        sum += campsite[i];

        if(expected_max < sum)
        {
            part++;
            sum = campsite[i];
        }
    }

    //cout << "Expected: " << expected_max << "Part: " << part << endl;

    if(part <= K)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void get_ans(ll ans)
{
    ll now = 1;
    ll remain = n - K - 1;


    while(now <= n)
    {
        ll pos = now - 1;
        ll tmp = sums[now] - sums[now-1];
        now++;
        if(remain > 0)
        {
            for(; now <= n; now++)
            {
                if(sums[now] - sums[pos] <= ans)
                {
                    tmp = sums[now] - sums[pos];
                    remain--;
                }
                else
                {
                    printlld(tmp);
                    break;
                }
                if(remain == 0)
                {
                    printlld(tmp);
                    now++;
                    break;
                }
            }
        }
        else
        {
            printlld(tmp);
        }
    }
}

int main()
{
    ll i, j, k, l, m, o;
    ll testcase;
    ll input, flag, tag;

    scanlld(testcase);

    for(i = 1; i <= testcase; i++)
    {
        scanlld(n);
        scanlld(K);
        ll maxinput = -999;
        n++;
        memset(sums,0,sizeof(sums));
        memset(campsite,0,sizeof(campsite));
        ll total = 0;

        sums[0] = 0;
        for(j = 1; j <= n; j++)
        {
            scanlld(input);

            campsite[j] = input;
            sums[j] = sums[j-1] + input;
            total += input;
            maxinput = max(maxinput,input);
        }

        ll low = maxinput;
        ll high = total;
        ll mid;
        ll ans;

        while(low <= high)
        {
            mid = (high + low) / 2;

            if(check(mid) == true)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        printf("Case %lld: %lld\n", i, ans);
        get_ans(ans);

    }


}


