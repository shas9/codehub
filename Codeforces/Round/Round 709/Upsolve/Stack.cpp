#include <bits/stdc++.h>

using namespace std;

int main()
{
    stack < int > st; // Standard Template Library

    for(int i = 1; i <= 10; i++)
    {
        st.push(i);
    }

    while(!st.empty())
    {
        cout << st.top()  << "\n";
        st.pop();
    }
}

