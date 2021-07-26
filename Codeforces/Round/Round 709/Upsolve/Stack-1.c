#include <stdio.h>

int main()
{
    int arr[] = {1,2,4,8,6,10,15,17,19,14,13,16};
    int ans[12];
    int stack[20];
    int i;
    int pos = 0;
    stack[0] = -1;

    for(i = 0; i < 12; i++)
    {
        while(pos >= 1)
        {
            int top = stack[pos];
            if(arr[top] > arr[i])
            {
                pos--;
            }
            else break;
        }

        ans[i] = stack[pos];
        pos++;
        stack[pos] = i;
    }

    for(i = 0; i < 12; i++)
    {
        if(ans[i] == -1) printf("%d : No immediate value found\n", arr[i]);
        else printf("%d : %d\n", arr[i], arr[ans[i]]);
    }
}
