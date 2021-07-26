#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num;
    int pos;
    double ans;

    int i, j, k, l;
    int count;
    string round;
    string x;

    int flag;

    while(cin >> num)
    {
        cin >> pos;
        ans = sqrt( num );

        count = ans;
        round.clear();

        while(count != 0)
        {
           flag = count % 10;
           count = count / 10;
           x = flag + 48;
           round = round + x;
        }

        cout << round;
    }
}
