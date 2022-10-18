#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char word[1000005];
char boom[50];
char stack[1000005];
int top = 0;
void booom()
{

}
int main()
{
	int chk = 0;
	scanf(" %s", word);
	scanf(" %s", boom);
	for (int i = 0; i < strlen(word); i++)
	{
		int cnt=0;
		//printf("%c", word[i]);
		if (word[i] == boom[cnt])
		{
			int count = 0;
			for (cnt = 0; cnt < strlen(boom); cnt++)
			{
				if (word[i + cnt] == boom[cnt])
				{
					count++;
				}
			}
			if (count == strlen(boom))
			{		
				i= i + count-1;
			}
			else
			{
				stack[top] = word[i];
				top++;
				chk++;

			}
		}
		else
		{
			stack[top] = word[i];
			top++;
		}
	}
	if (top == 0)
	{
		printf("FRULA");
	}
	else
	{
		for (int i = 0; i < top; i++)
		{
			printf("%c", stack[i]);
		}
	}
	
	return 0;
}