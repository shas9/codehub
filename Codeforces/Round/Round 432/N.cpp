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
    ll i, j, k, l, m, n, o;
    ll testcase;

    ll p, q, cnt, cnt1, cnt2, cnt_p, cnt_q;
    ll ex_p, ex_q;
    ll tag;

    while(1)
    {
        cnt = 0;
        cnt1 = 0;
        cnt2 = 0;
        cnt_p = 0;
        cnt_q = 0;
        tag = 1;

        scanlld(p);
        scanlld(q);

        if(p < 0 && q < 0)
        {
            return 0;
        }

        while(p > 0 || q > 0)
        {
            tag = 1;

            m = p / 10;
            n = q / 10;

            ex_p = (p - (m * 10));
            ex_q = (q - (n * 10));

            i = n - m;

            if(p % 10 != 0)
            {
                i--;
            }

            cnt_p = 45 - ((ex_p * (ex_p - 1)) / 2);
            cnt_q = ((ex_q * (ex_q + 1)) / 2);

            if(p % 10 == 0)
            {
                cnt_p = 0;
            }

            cnt2 = (i * 45) + cnt_p + cnt_q;

            printf("cntp = %lld, cntq = %lld, cnt2 = %lld\n", cnt_p, cnt_q, cnt2);

            cnt += cnt2;

            p /= 10;
            q /= 10;
            if(p == q)
            {
                break;
            }

            printf("Here m = %lld, n = %lld, exp = %lld, exq = %lld, i = %lld, cnt2 = %lld, cnt = %lld, p = %lld, q = %lld\n", m, n, ex_p, ex_q, i, cnt2, cnt, p, q);

            printf("COUNT = %lld\n", cnt);
        }

        if(q == 1)
        {
            cnt++;
        }

        printlld(cnt);
    }


}


