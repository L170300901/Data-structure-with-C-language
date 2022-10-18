#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char word[1005];
char word2[1005];
int answer[3];
int cnt = 0;
char stack[100005];
int top = 0;
void Normal(int n)
{
	
	if (n == 1)
	{
		stack[top++] = 'I';
	}
	else if (n == 2)
	{
		stack[top++] = 'I';
		stack[top++] = 'I';
	}
	else if (n == 3)
	{
		stack[top++] = 'I';
		stack[top++] = 'I';
		stack[top++] = 'I';
	}
	else if (n == 4)
	{
		
		stack[top++] = 'V';
		stack[top++] = 'I';
	}
	else if (n == 5)
	{
		stack[top++] = 'V';
	}
	else if (n == 6)
	{
		
		stack[top++] = 'I';
		stack[top++] = 'V';
	}
	else if (n == 7)
	{
		
		stack[top++] = 'I';
		stack[top++] = 'I';
		stack[top++] = 'V';
	}
	else if (n == 8)
	{
		
		stack[top++] = 'I';
		stack[top++] = 'I';
		stack[top++] = 'I';
		stack[top++] = 'V';
	}
	else if (n == 9)
	{
		
		stack[top++] = 'X';
		stack[top++] = 'l';
	}
	else if (n == 10)
	{
		stack[top++] = 'X';
	}
	else if (n == 20)
	{
		stack[top++] = 'X';
		stack[top++] = 'X';
	}
	else if (n == 30)
	{
		stack[top++] = 'X';
		stack[top++] = 'X';
		stack[top++] = 'X';
	}
	else if (n == 40)
	{
		
		stack[top++] = 'L';
		stack[top++] = 'X';
	}
	else if (n == 50)
	{
		stack[top++] = 'L';
	}
	else if (n == 60)
	{
		
		stack[top++] = 'X';
		stack[top++] = 'L';
	}
	else if (n == 70)
	{
		
		stack[top++] = 'X';
		stack[top++] = 'X';
		stack[top++] = 'L';
	}
	else if (n == 80)
	{
		
		stack[top++] = 'X';
		stack[top++] = 'X';
		stack[top++] = 'X';
		stack[top++] = 'L';
	}
	else if (n == 90)
	{
		
		stack[top++] = 'C';
		stack[top++] = 'X';
	}
	else if (n == 100)
	{
		stack[top++] = 'C';
	}
	else if (n == 200)
	{
		stack[top++] = 'C';
		stack[top++] = 'C';
	}
	else if (n == 300)
	{
		stack[top++] = 'C';
		stack[top++] = 'C';
		stack[top++] = 'C';
	}
	else if (n == 400)
	{
		
		stack[top++] = 'D';
		stack[top++] = 'C';
	}
	else if (n == 500)
	{
		stack[top++] = 'D';
	}
	else if (n == 600)
	{
		
		stack[top++] = 'C';
		stack[top++] = 'D';
	}
	else if (n == 700)
	{
		
		stack[top++] = 'C';
		stack[top++] = 'C';
		stack[top++] = 'D';
	}
	else if (n == 800)
	{
		
		stack[top++] = 'C';
		stack[top++] = 'C';
		stack[top++] = 'C';
		stack[top++] = 'D';
	}
	else if (n == 900)
	{
	    stack[top++] = 'M';
		stack[top++] = 'C';
		
	}
	else if (n == 1000)
	{
		stack[top++] = 'M';
	}
	else if (n == 2000)
	{
		stack[top++] = 'M';
		stack[top++] = 'M';
	}
	else if (n == 3000)
	{
		stack[top++] = 'M';
		stack[top++] = 'M';
		stack[top++] = 'M';
	}
	else if (n == 4000)
	{
		stack[top++] = 'M';
		stack[top++] = 'M';
		stack[top++] = 'M';
		stack[top++] = 'M';
	}

}
void Roma(char arr[])
{
	//printf("#%s\n", arr);
	int a = 0;
	for (int i = 0; i < strlen(arr); i++)
	{
		if (arr[i] == 'I')
		{
			if (arr[i + 1] == 'V')
			{
				a = a + 4;
				i++;
			}
			else if (arr[i + 1] == 'X')
			{
				a = a + 9;
				i++;
			}
			else
			{
				a = a + 1;
			}
		}
		else if (arr[i] == 'V')
		{
			a = a + 5;

		}
		else if (arr[i] == 'X')
		{
			if (arr[i + 1] == 'L')
			{
				a = a + 40;
				i++;
			}
			else if (arr[i + 1] == 'C')
			{
				a = a + 90;
				i++;
			}
			else
			{
				a = a + 10;

			}
		}
		else if (arr[i] == 'L')
		{
			a = a + 50;

		}
		else if (arr[i] == 'C')
		{
			if (arr[i + 1] == 'D')
			{
				a = a + 400;
				i++;
			}
			else if (arr[i + 1] == 'M')
			{
				a = a + 900;
				i++;
			}
			else
			{
				a = a + 100;
			}
		}
		else if (arr[i] == 'D')
		{
			a = a + 500;
		}
		else if (arr[i] == 'M')
		{
			a = a + 1000;
		}
	}
	answer[cnt] = a;
	cnt++;
}
void Change(int num)
{
	int g = 1;
	int temp;
	while (num != 0)
	{
		temp = num % 10;
		Normal(temp * g);;
		//printf("temp==%d", temp*g);	
		g = g * 10;
		num = num / 10;
		//printf("num==%d\n", num);

	}
}
int main()
{
	scanf(" %s", word);
	Roma(word);

	scanf(" %s", word2);
	Roma(word2);
	int temp = 0;
	temp = answer[0] + answer[1];
	printf("%d\n", temp);
	//숫자 -> 문자열 
	Change(temp);
	for (int i = top-1; i >= 0; i--)
	{
		printf("%c", stack[i]);
	}
}