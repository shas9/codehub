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

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;
    ll ans;

    vector < ll > arr;
    ll store[100005];

    memset(store,0,sizeof(store));

    arr.clear();

    scanlld(testcase);
    scanlld(k);
    scanlld(m);

    ll maxinput = -99;

    for(i = 1; i <= testcase; i++)
    {
        scanlld(input);

        arr.pb(input);

        flag = input % m;

        store[flag]++;

        if(maxinput < input)
        {
            maxinput = input;
        }
    }

    ans = -1;

    for(i = 0; i <= maxinput; i++)
    {
        if(store[i] >= k)
        {
            ans = i;
            break;
        }
    }

    tag = 0;

    if(ans == -1 || ans >= 100005)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
        for(i = 0; i < testcase; i++)
        {
            if(arr[i] % m == ans)
            {
                tag++;

                    cout << arr[i];
                    cout << " ";
                if(tag == k)
                {
                    //cout << endl;
                    break;
                }
            }
        }
    }


}


