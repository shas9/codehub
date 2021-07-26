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

        aladeen--;

        heights.clear();

        for(i = 1; i <= children; i++)
        {
            scanlld(input);

            heights.pb(input);
        }

        flag = heights[aladeen];

        ll temp;

        sort(heights.begin(), heights.end());

        /*for(i = 0; i < children; i++)
        {
            cout << heights[i] << " ";
        }
        cout << endl;*/

        tag = binary(flag);

        //cout << " " << tag << " " << aladeen << endl;

        /*if(tag + 1 == aladeen)
        {
            heights[tag] = heights[aladeen];
            heights[aladeen] = flag;
        }
        else */if(tag < aladeen)
        {
            for(i = tag; i <= aladeen; i++)
            {
                heights[i] = heights[i + 1];
            }
        }
        else
        {
            for(i = tag; i >= aladeen; i--)
            {
                heights[i] = heights[i - 1];
            }
        }

        heights[aladeen] = flag;

        for(i = 0; i < children; i++)
        {
            cout << heights[i];

            if(i != children - 1)
            {
                cout << " ";
            }
        }

        cout << endl;
    }
}

/*

4
3 2
2 1 3
5 2
1 2 3 4 5
4 2
5 2 6 3
12 7
1 5 9 44 11 39 45 99 14 36 10 22


*/

