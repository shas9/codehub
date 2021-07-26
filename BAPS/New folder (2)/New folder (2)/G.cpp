#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    ll hh, mm;
    cin >> hh>> mm;
    ll h, d, c, n;
    cin >> h >> d >> c >> n;

    if(hh < 20) {
        ll need1 = h / n;
        if(h % n != 0)
            need1++;

        double tot1 = (need1 * 1.0) * c;

        ll dif = (20 - hh - 1) * 60;
        dif += (60 - mm);

        ll nowh = h + (dif * d);
        ll need2 = nowh / n;
        if(nowh % n != 0)
            need2++;

        double rc = c * 0.8;
        double tot =  need2 * rc;
        tot = min(tot, tot1);
        printf("%0.4f\n", tot);


    }

    else {
        double rc = c * 0.8;
        ll need = h / n;
        if(h % n != 0)
            need++;

        double tot = need * rc;
        printf("%0.4f\n", tot);
    }

    return 0;
}
