#include <bits/stdc++.h>`

#define scanlld(longvalue) scanf("%lld", &longvalue)
#define printlld(longvalue) printf("%lld\n", longvalue)

#define scanc(letter) scanf("%c", &letter)
#define printc(letter) printf("%c", letter)

#define scanlf(longvalue) scanf("%lf", &longvalue)
#define printlf(longvalue) printf("%lf\n", longvalue)

#define scans(name) scanf("%s", name)
#define prints(name) printf("%s", name)

#define printnewline printf("\n")

#define ll long long

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

using namespace std;

double calc(double len, double ratio_ab)
{
    double width;
    double round, angle, radius, c;

    width = len / ratio_ab;

    c = width / 2;
    radius = sqrt((len * len) + (width * width)) / 2;

    angle = asin(c/radius);

    round = 2 * angle * radius;

    //printf("length is %lf, width = %lf, radius = %lf, angle = %lf, c = %lf, round = %lf\n", len, width, radius, angle, c, round);

    return round;
}

double binary(double ratio_ab)
{
    double high, low, mid;
    double round;
    double sum;

    low = 0;
    high = 500;

    ll i = 1;

    while(low <= high && i <= 100)
    {
        mid = (high + low) / 2;

        round = calc(mid, ratio_ab);

        sum = round + mid;

        if(sum == 200)
        {
            return mid;
        }
        else if(sum < 200)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
        i++;
    }

    return mid;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;

    double rad, ang, c, width, length, round, sum;

    double a, b, ratio_ab;

    scanlld(testcase);

    for(i = 1; i <= testcase; i++)
    {
        scanf("%lf : %lf", &a, &b);

        ratio_ab = a / b;

        length = binary(ratio_ab);

        width = length / ratio_ab;

        printf("Case %lld: %lf %lf\n", i, length, width);

    }


}

