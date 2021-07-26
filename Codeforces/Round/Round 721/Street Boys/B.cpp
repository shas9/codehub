#include <bits/stdc++.h>

using namespace std;

int main()
{
    int testcase;

    cin >> testcase;

    for(int i = 1; i <= testcase; i++)
    {
        int n;

        cin >> n;

        // 6 -> 0, 6

        if(n <= 10) cout << n << " 0\n";
        else cout << n - 10 << " 10\n";
    }
}

