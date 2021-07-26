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

vector < ll > stall;
ll cow;

bool check(ll mid)
{
    //cout << "Mid: " << mid << endl;
    ll lastcow = stall[0];
    ll totalcow = 1;

    for(ll i = 1; i < stall.size(); i++)
    {
        //cout << "Now: " << stall[i] << " Last: " << lastcow << endl;
        if((stall[i] - lastcow) >= mid)
        {
            //bug;
            totalcow++;
            lastcow = stall[i];

            if(totalcow == cow)
            {
                return true;
            }
        }
    }

    return false;
}

ll binary(ll high)
{
    ll mid;
    ll low = 0;
    ll ans;

    while(low <= high)
    {
        mid = (high + low) / 2;

        if(check(mid) == true)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}


int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    scanlld(testcase);

    for(i = 1; i <= testcase; i++)
    {
        scanlld(n);
        scanlld(cow);

        stall.clear();

        for(j = 0; j < n; j++)
        {
            scanlld(input);
            stall.pb(input);
        }

        sort(stall.begin(),stall.end());

        flag = stall[n-1] - stall[0] + 1;

        ll ans = binary(flag);

        cout << ans << endl;
    }


}


