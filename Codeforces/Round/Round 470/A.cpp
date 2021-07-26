#include <iostream>

using namespace std;

int main()
{
    int siz;
    int m, i, j, k, l, r;

    char str[1000];

    char c, d;

    cin >> siz >> m >> str;

    for(i = 0; i < m; i++)
    {
        cin >> l >> r >> c >> d;
        l--;
        r--;
        for(j = l; j <= r; j++)
        {
            if(str[j] == c)
            {
                str[j] = d;
            }
        }
    }

    cout << str << endl;
}
