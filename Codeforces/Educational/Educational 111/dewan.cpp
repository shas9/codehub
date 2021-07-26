#include <bits/stdc++.h>
using namespace std ;
int main()
{
    int i, j, k, t;
    cin >> t ;
    for(k=1; k<=t; k++)
    {
        long long n, flag=0, sum=0, counter=0;
        cin >> n ;
        int div = n/2050;
        if(div>0)
        {
            string str = to_string(div);
            for(i=0; i<str.length(); i++) sum+= int(str[i])-'0';
            cout << sum << endl ;
        }
        else cout << -1 << endl ;
    }
}
