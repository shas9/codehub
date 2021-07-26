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

    ll flag, tag, cnt, cnt1, cnt2;

    ll p, q;

    ll temp_p, temp_q;

    ll cntp, cntq;

    ll diff;

    while(1)
    {
        scanlld(p);
        scanlld(q);

        if(p < 0 && q < 0)
        {
            return 0;
        }

        cnt = 0;
        cnt1 = 0;
        cnt2 = 0;
        cntp = 0;
        cntq = 0;

        while(q != 0)
        {
            cnt1 = 0;
            cnt2 = 0;
            cntp = 0;
            cntq = 0;

            m = (p / 10);

            n = (q / 10);

            temp_p = (p - (m * 10));
            temp_q = (q - (n * 10));

            if(temp_p == 0)
            {
                cntp = 0;
            }
            else
            {
                for(i = temp_p; i <= 9; i++)
                {
                    cntp += i;
                }
            }

            if(temp_q == 0)
            {
                cntq = 0;
            }
            else
            {
                for(i = 1; i <= temp_q; i++)
                {
                    cntq += i;
                }
            }

            diff = n - m;

            if(temp_p != 0)
            {
                diff--;
            }

            cnt2 = (diff * 45) + cntp + cntq;

            cnt += cnt2;

            p = p / 10;
            q = q / 10;

            if(p == q)
            {
                break;
            }


        }

        //cnt = cnt + ((q * (q + 1)) / 2) - ((p * (p - 1)) / 2);

        printlld(cnt);
    }
}


