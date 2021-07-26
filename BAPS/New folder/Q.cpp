#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

char str[1000005];
ll id[300];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    while(1)
    {
        slld(n);

        if(n == 0) break;

        memset(id,0,sizeof id);

        getchar();

        scanf("%[^\n]s", str);

        ans = -1;

        //cout << "==>" << str << "<==" << endl; //FUCK YOU. -_-

        ll len = strlen(str);

        ll lo = 0;
        ll hi = 0;

        ll sol = 0, diff = 0;

        while(hi < len)
        {
            id[str[hi]]++;

            if(id[str[hi]] == 1) diff++;

            hi++;

            while(diff > n)
            {
                id[str[lo]]--;

                if(id[str[lo]] == 0) diff--;
                lo++;
            }

            ans = max(ans, hi - lo);
        }

//        for(i = 0; i <= hi; i++)
//        {
//            id[str[i]] = 1;
//        }
//
//
//
//        while(1)
//        {
//            ans = max(ans, hi - lo + 1);
//
//            if(hi == len - 1) break;
//
//
////            cout << ans << endl;
////            cout << lo << " - " << hi << " : " << str[hi] << " : " << str[hi + 1] << " : " << id[str[hi + 1]] << endl;
//
//            if(id[str[hi + 1]] > 0)
//            {
//                id[str[hi + 1]]++;
//                hi++;
//            }
//            else
//            {
//                id[str[lo]]--;
//                id[str[hi + 1]]++;
//
//                if(id[str[lo]])
//                {
//                    id[str[hi + 1]]--;
//                    hi--;
//                }
//
//                lo++;
//                hi++;
//            }
//        }

        plld(ans);
    }




}

