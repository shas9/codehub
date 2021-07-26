
// C++ Program to find the diagonal
// of a regular polygon with given side length
#include <bits/stdc++.h>
using namespace std;

// Function to find the diagonal
// of a regular polygon
float polydiagonal(float n, float a)
{

    // Side and side length cannot be negative
    if (a < 0 && n < 0)
        return -1;

    // diagonal
    // degree converted to radians
    return 2 * a * sin((((n - 2) * 180) / (2 * n)) * 3.14159 / 180);
}

// Driver code
int main()
{
    float a = 1, n = 10;


    while(cin >> n)
    {
		cout << polydiagonal(n, a) << endl;
    }

    return 0;
}
