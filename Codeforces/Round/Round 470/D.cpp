#include <iostream>

using namespace std;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    vector < int > store;

    scanlld(testcase);

    ll eggs, maxeggs, maxw;

    ll sum;

    for(i = 1; i <= testcase; i++)
    {
        scanlld(eggs);
        scanlld(maxeggs);
        scanlld(maxw);

        store.clear();
        sum = 0;
        tag = 0;
        for(j = 1; j <= eggs; j++)
        {
            scanlld(input);

            store.pb(input);

            sum += input;

            if(sum <= maxw)
            {
                tag++;
            }
        }

        if(tag > maxeggs)
        {
            tag = maxeggs;
        }

        printcase(i,tag);


    }


}
