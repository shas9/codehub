#include <bits/stdc++.h>

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

bool nums[10003310];
vector < ll > prime;

ll bound(ll num)
{
    ll high = prime.size() - 1;
    ll low = 0;
    ll mid;

    ll ans = -1;

    while(low <= high)
    {
        mid = (high + low) / 2;
        if(prime[mid] == num)
        {
            ans = mid;
            break;
        }
        else if(prime[mid] > num)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if(ans == -1)
    {
        return low;
    }
    else
    {
        return ans;
    }
}

void sieve()
{
    ll i, j, k, l;

    ll flag = 10003310;

    for(i = 4; i < flag; i = i + 2)
    {
        nums[i] = true;
    }

    for(i = 3; i*i <= flag; i = i + 2)
    {
        if(nums[i] == false)
        {
            for(j = i * i; j <= flag; j = j + i)
            {
                nums[j] = true;
            }
        }
    }

    prime.clear();
    for(i = 2; i < 10003310; i++)
    {
        if(nums[i] == false)
        {
            prime.push_back(i);
        }
    }
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;

    scanlld(testcase);

    ll high, low;

    ll ans;

    sieve();

    ll lowpos;
    ll check;
    for(i = 1; i <= testcase; i++)
    {
        scanlld(low);
        scanlld(high);

        scanlld(k);

        if(high < low)
        {
            ll temp = low;
            low = high;
            high = temp;
        }

        //cout << low << " " << high << endl;

        ans = 0;

        lowpos = bound(low);

        for(j = lowpos; prime[j + 1] <= high; j++)
        {
            check = prime[j] + k;
            //cout << j << " " << prime[j] << endl;
            if(check <= high)
            {
                if(nums[check] == false )
                {
                    ans++;
                }
            }
        }

        printlld(ans);
    }


}


