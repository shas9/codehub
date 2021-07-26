#include<bits/stdc++.h>

using namespace std;

int main()
{
    int testcase;

    cin >> testcase;

    for(int i = 1; i <= testcase; i++)
    {
        long long n;
        cin >> n;

        long long ans = 0;
        int j = 0;

        while(n >= 0) // Complexity: T * N -> T * log(N)
        {
            j++;
            n -= j;
        }

        cout << j - 1 << "\n";
    }
}

