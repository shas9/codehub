#include <bits/stdc++.h>

using namespace std;

int space, c;
stack <int> train;
void marshal()
{
    while(1)
    {
        while(train.size() > 0)
        {
             train.pop();
        }
        int j = 0;
        for(int i = 0; i < space; i++)
        {
            scanf("%d", &c);
            if(c == 0)
            {
                 return;
            }
            cout << "this is c: " << c << endl;

            while(j < space && j != c)
            {
                cout << "j == " << j << " space == " << space << endl;
                if(train.size() > 0 && train.top() == c)
                {
                    cout << "train.size() > 0 && train.top() == c" << endl;
                    break;
                }
                j++;
                train.push(j);
            }
            if(train.top() == c)
            {
                cout << "popped" << endl;
                train.pop();
            }
        }
        if(train.size() == 0)
        {
             printf("Yes\n");
        }
        else
        {
             printf("No\n");
        }
    }
}

int main()
{
    while(1)
    {
        //int space;
        cin >> space;
        if(space == 0)
        {
            break;
        }

        marshal();
        printf("\n");
    }
}
