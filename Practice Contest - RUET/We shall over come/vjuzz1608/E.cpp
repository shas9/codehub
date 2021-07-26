#include <bits/stdc++.h>

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

    scanlld(testcase);

    vector < ll > arr;

    ll input, maxsum, sum, arrsize;
    ll start, startp, endp;
    ll tag, flag;

    for(l = 1; l <= testcase; l++)
    {

        scanlld(arrsize);
        arr.clear();
        tag = 0;
        flag = 0;

        for(i = 1; i < arrsize; i++)
        {
            scanlld(input);

            arr.push_back(input);
        }

        maxsum = -77777;

        sum = 0;

        start = 0;

        for(i = 0; i < arrsize - 1; i++)
        {
            sum += arr[i];

            if(sum < 0)
            {
                tag++;
                sum = 0;
                start = i + 1;
            }

            if(maxsum <= sum)
            {
                //cout << "I is: " << i << endl;

                if(maxsum == sum)
                {
                    if(tag == flag)
                    {
                        maxsum = sum;
                        startp = start;
                        endp = i + 1;
                    }
                    else if((i + 1 - start) > (endp - startp))
                    {
                        maxsum = sum;
                        startp = start;
                        endp = i + 1;
                    }
                }
                else
                {
                    flag = tag;
                    maxsum = sum;
                    startp = start;
                    endp = i + 1;
                }
            }
        }

        if(maxsum > 0)
        {
            printf("The nicest part of route %lld is between stops %lld and %lld\n", l, startp + 1, endp + 1);
        }
        else
        {
            printf("Route %lld has no nice parts\n", l);
        }
    }


}


