#include <stdio.h>

int main()
{
	int testcase;

	scanf("%d", &testcase);

	int i, j, k, l;

	char input[200];

	int ln;

	for(i = 1; i <= testcase; i++)
	{
		scanf("%c", &input[0]);
		input[0] = 0;
		scanf("%[^\n]s", input);
		//printf("input was %s\n", input);

		for(ln = 0; input[ln] != '\0'; ln++);

		if(ln == 0)
		{
			printf("Yes\n");
		}

		else
		{
			for(j = ln - 1; j >= 0; j--)
			{
				if(input[j] == ')')
				{
					/*for(k = 0; k < j; k++)
					{
						if(input[k] == '(')
						{
							input[k] = ' ';
							input[j] = ' ';

							break;
						}
					}*/
					k = j;
					while(1)
					{
						k--;
						if(k < 0)
						{
							break;
						}
						if(input[k] == '(')
						{
							input[k] = ' ';
							input[j] = ' ';

							break;
						}
					}
				}
				else if(input[j] == ']')
				{
					/*for(k = 0; k < ln; k++)
					{
						if(input[k] == '[')
						{
							input[k] = ' ';
							input[j] = ' ';

							break;
						}
					}*/
					k = j;
					while(1)
					{
						k--;
						if(k < 0)
						{
							break;
						}
						if(input[k] == '[')
						{
							input[k] = ' ';
							input[j] = ' ';

							break;
						}
					}
				}
			}

			/*for(l = 0; l < ln; l++)
			{
				printf("%c ", input[l]);
			}*/

			for(l = 0; l < ln; l++)
			{
				if(input[l] != ' ')
				{
					break;
				}
			}

			if(l == ln)
			{
				printf("Yes\n");
			}
			else
			{
				printf("No\n");
			}

			input[0] = '\0';
			}
	}

	return 0;
}