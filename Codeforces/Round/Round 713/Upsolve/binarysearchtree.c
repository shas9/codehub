#include<stdio.h>

int left[100];
int right[100];

int arr[100];
int head;

int main()
{
    int n, i;

    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(i = 1; i < 100; i++)
    {
        left[i] = -1;
        right[i] = -1;
    }

    head = arr[1];

    for(i = 2; i <= n; i++)
    {
        int cursor = head;

        while(1)
        {
            if(cursor <= arr[i])
            {
                if(right[cursor] == -1)
                {
                    right[cursor] = arr[i];
                    break;
                }

                cursor = right[cursor];
            }
            else
            {
                if(left[cursor] == -1)
                {
                    left[cursor] = arr[i];
                    break;
                }

                cursor = left[cursor];
            }
        }
    }


//    for(i = 1; i <= n; i++)
//    {
//        printf("Value is: %d\n", arr[i]);
//        printf("left is: %d and right is %d\n", left[arr[i]], right[arr[i]]);
//    }

    printf("How many times will you ask?: ");
    int m;
    scanf("%d", &m);

    for(i = 1; i <= m; i++)
    {
        printf("Choose a option.\n");
        printf("Press 1 to insert\nPress 2 to search.\n");

        int option;
        scanf("%d", &option);

        printf("Enter the value: ");
        int value;
        scanf("%d", &value);

        if(option == 1)
        {
            int cursor = head;

            while(1)
            {
                if(cursor <= value)
                {
                    if(right[cursor] == -1)
                    {
                        right[cursor] = value;
                        break;
                    }

                    cursor = right[cursor];
                }
                else
                {
                    if(left[cursor] == -1)
                    {
                        left[cursor] = value;
                        break;
                    }

                    cursor = left[cursor];
                }
            }
        }
        else
        {
            int cursor = head;

            while(cursor != -1)
            {
                if(cursor == value) break;

                if(cursor < value)
                {
                    cursor = right[cursor];
                }
                else
                {
                    cursor = left[cursor];
                }
            }

            if(cursor == -1) printf("Sorry we didn't find the element.\n");
            else printf("Hoorah! We found the element!\n");
        }
    }
}
