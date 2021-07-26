#include <stdio.h>

int main()
{
	int i, j, k, l, m, n;

	int len;

	int testcase;

	char input[200];

	scanf("%d", &testcase);

	for(i = 0; i < testcase; i++)
	{
		scanf("%c", &input[0]);
		input[0] = 0;
		scanf("%[^\n]s", input);

		for(len = 0; input[len] != '\0'; len++);

		if(len == 0)
		{
			printf("Yes\n");
		}
		else
		{
			for(j = len - 1; j >= 0; j--)
			{
				if(input[j] == ')')
				{
					for
				}
			}
		}
	}
}