#include <bits/stdc++.h>

using namespace std;

/*
aba aba
samin nimas
1551 1551
58 85
1000000000

s = 21
t = s;
t = 21 -> 12

samin
nimas

s = 68549

temp = 0
last = 5
t = 90 + 4 = 94586

5699111115

*/

int main()
{
    int testcase;

    cin >> testcase;

    for(int i = 1; i <= testcase; i++)
    {
        int s, t = 0;

        cin >> s;

        int temp = s;

        while(temp > 0)
        {
            int last = temp % 10;
            temp /= 10;

            t = (t * 10) + last;
        }

        if(t == s) cout << "Case " << i << ": Yes\n";
        else cout << "Case " << i << ": No\n";
    }
}

