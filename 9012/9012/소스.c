#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main()
{
	char str[50];
	int i,n,j;
	int top = -1;
	int check=0;
	scanf("%d", &n);
	int len = 0;
	for (i = 0; i < n; i++)
	{
		
		top = -1;
		scanf(" %s", str);
		len = strlen(str);
		check = 0;
		for (j = 0; j < len; j++)
		{
			if (str[j] == '(')
				top++;
			else {
				if (top <= -1) {
					printf("NO\n");
					check = 1;
					break;
				}
				top--;
			}
		}
		if (top == -1 && check == 0)
			printf("YES\n");
		else if(top!= -1 && check == 0)
			printf("NO\n");
	}
	
	return 0;
		
}
