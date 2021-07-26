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

vector < ll > heights;

ll binary(ll n)
{
    ll high = heights.size();
    ll low = 0;
    ll mid;
    ll ans = -99;
    while(low <= high)
    {
        mid = (high + low) / 2;

        if(heights[mid] == n)
        {
            ans = mid;
            low = mid + 1;
        }
        else if(heights[mid] > n)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;
    ll children;

    scanlld(testcase);

    for(ll test = 1; test <= testcase; test++)
    {
        scanlld(children);

        ll aladeen;

        scanlld(aladeen);

        heights.clear();

        for(i = 1; i <= children; i++)
        {
            scanlld(input);

            heights.pb(input);
        }

        flag = heights[aladeen - 1];

        ll temp;

        sort(heights.begin(), heights.end());

        for(i = 0; i < children; i++)
        {
            cout << heights[i] << " ";
        }
        cout << endl;

        tag = binary(flag);

        for(i = aladeen - 1; i >= tag + 1; i--)
        {
            temp = heights[i];
            heights[i] = heights[i - 1];
            heights[i - 1] = temp;
        }

        heights[aladeen - 1] = flag;

        for(i = 0; i < children; i++)
        {
            cout << heights[i] << " ";
        }

        cout << endl;

    }


}

/*

1
12 7
1 5 9 44 11 39 45 99 14 36 10 22


*/


