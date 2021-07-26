#include<stdio.h>

int arr[1000000];


int now = 1;

void insert(int val)
{
    arr[now] = val;

    int cursor = now;

    now++;

    while(cursor != 1)
    {
        int par = cursor / 2;

        if(arr[par] < arr[cursor])
        {
            int temp = arr[par];
            arr[par] = arr[cursor];
            arr[cursor] = temp;
            cursor = par;
        }
        else break;
    }
}


int main()
{

}
