#include <bits/stdc++.h>`
using namespace std;
int main()
{
    string input;
    cin >> input;
    if(input[0] > 'Z')
    {
        input[0] -= 32;
    }
    cout << input << endl;
}


