#include <bits/stdc++.h>

using namespace std;

stack < int > stk;
queue < int > qq;

vector < int > vec;



int main()
{
    int x;
    double y;

    /*

        3, 4

        vec[3].push_back(4);
        vec[4].push_back(3);
    */

    for(int i = 1; i <= 10; i++)
    {
        stk.push(i);
        qq.push(i);

        vec.push_back(i);
    }

    while(!stk.empty())
    {
        cout << stk.top() << "\n";
        stk.pop();
    }

    while(!qq.empty())
    {
        cout << qq.front() << "\n";
        qq.pop();
    }


    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }

    cout << vec.size() << "\n";

    vec.clear();

    cout << vec.size() << "\n";


}
