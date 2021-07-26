#include <bits/stdc++.h>


#define scand(value) scanf("%d", &value)
#define printd(value) printf("%d", value)

#define scanlld(longvalue) scanf("%lld", &longvalue)
#define printlld(longvalue) printf("%lld", longvalue)

#define scanc(letter) scanf("%c", &letter)
#define printc(letter) printf("%c", letter)

#define scans(name) scanf("%s", name)
#define prints(name) printf("%s", name)

#define printnewline printf("\n")

#define ll long long

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)




using namespace std;

int main()
{
    ll i, j, k, m, n, o, p;
    ll testcase;
    ll input;

    scanlld(testcase);

    ll l, r, x, d;
    vector < long long int > A;
    ll size;
    ll Q;
    ll c;
    ll sum;
    ll mod = 1000000007;
    ll temp;
    ll flag;

    for(i = 1; i <= testcase; i++)
    {
        A.clear();
        scanlld(size);
        scanlld(Q);

        for(j = 0; j < size; j++)
        {
            scanlld(input);
            A.push_back(input);
        }
        printf("Case %lld:\n", i);
        for(j = 0; j < Q; j++)
        {
            scanlld(c);
            scanlld(l);
            scanlld(r);
            scanlld(d);
            l--;
            r--;

            o = 0;
            sum = A[l] % mod;

            while(l < r)
            {
                l++;
                o++;

                flag = 1 + (o * d);
                temp = (((flag % mod) * (A[l] % mod)) % mod);
                sum = ((sum % mod) + (temp % mod)) % mod;
                //printf("here flag is %lld, temp = %lld, sum = %lld\n", flag, temp, sum);
            }
            printlld(sum);
            printnewline;

            //printf("here j is %lld\n", j);
        }
    }


}


