#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll check(ll n)
{
    ll ret = 0;

    while(n)
   {
       if(n % 10 != 7) return 0;
       n /= 10;
       ret++;
   }

    return ret;
}
int main()
{
    ll num, sz = 0;
    ll gun = 0;

    cin >> num;

    ll lastd = num % 10;

    ///cout << lastd << endl;

    if(lastd % 2 == 0 || lastd == 5) cout << -1 << endl;
    else
    {

       /// cout << "Entered\n";

        while(check(gun) == 0)
        {
           sz++;
           if(sz >= 10000000)
           {
                sz = -1;
                break;
           }

           ll need = ((7 - (gun % 10)) + 10) % 10;

          ll gg = 10;
          for(ll i = 0; i <= 9; i++)
          {
              if((i * lastd) % 10 == need)
              {
                  gg = i;
                  break;
               }
          }

          if(gg == 10)
          {
              sz = -1;
              break;
          }

          gun += (num * gg);
        ///  cout << need <<' ' << gg << ' ' << gun << endl;

          gun /= 10;

          if(gun == 0) break;
        }

        sz += check(gun);

        cout << sz << endl;
    }
}
