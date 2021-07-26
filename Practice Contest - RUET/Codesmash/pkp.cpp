#include <bits/stdc++.h>
#include <vector>

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

    vector < ll > arr;
    vector < ll > subnumber;


ll bound(ll num, ll size)
{
    ll high;
    ll low;
    ll mid;

    high = size - 1;
    low = 0;

    ll ans = -1;

    while(low <= high)
    {
        mid = (high + low) / 2;
        if(subnumber[mid] == num)
        {
            ans = mid;
            low = mid + 1;
        }
        else if(subnumber[mid] > num)
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
        return high;
    }
    else
    {
        return ans;
    }
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;


    ll size;
    ll input;
    ll query;


    scanlld(testcase);

    for(k = 1; k <= testcase; k++)
    {
        scanlld(size);
        scanlld(query);

        ll sum;

        arr.clear();
        subnumber.clear();

        for(i = 0; i < size; i++)
        {
            scanlld(input);

            arr.push_back(input);
        }

        ll limit = pow(2,size) - 1;

        for(i = 1; i <= limit; i++)
        {
            sum = 0;
            for(j = 0; j < size; j++)
            {
                if((i & (1 << j)) != 0)
                {
                    sum = sum + arr[j];
                }
            }
            subnumber.push_back(sum);
        }

        sort(subnumber.begin(), subnumber.end());

        /*for(i = 0; i < limit; i++)
        {
            cout << "Subnum = " << subnumber[i] << endl;
        }*/

        ll pending = 0;

        for(j = 1; j <= query; j++)
        {
            ll type;
            ll value;

            scanlld(type);
            scanlld(value);


            if(type == 1)
            {
                pending += value;
                //cout << "pending = " << pending << endl;
            }
            else
            {
                value -= pending;
                //cout << "Value: " << value << endl;
                ll pos = bound(value, subnumber.size());
                pos++;
                printlld(pos);
            }
        }
    }

    return 0;
}
