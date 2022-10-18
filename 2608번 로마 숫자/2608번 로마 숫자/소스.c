#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char word[1005];
char word2[1005];
int answer[3];
int cnt = 0;
char stack[100005];
int top = -1;
void Normal(int n)
{
	if (n == 0)
	{
		stack[top++] = "";
	}
	else if (n == 1) 
	{
		stack[top++] = "I";
	}
	else if (n == 2) 
	{
		stack[top++] = "II";
	}
	else if (n == 3) 
	{
		stack[top++] = "III";
	}
	else if (n == 4)
	{
		stack[top++] = "IV";
	}
	else if (n == 5) 
	{
		stack[top++] = "V";
	}
	else if (n == 6) 
	{
		stack[top++] = "VI";
	}
	else if (n == 7)
	{
		stack[top++] = "VII";
	}
	else if (n == 8) 
	{
		stack[top++] = "VIII";
	}
	else if (n == 9) 
	{
		stack[top++] = "lX";
	}
	else if (n == 10) 
	{
		stack[top++] = "X";
	}
	else if (n == 20) 
	{
		stack[top++] = "XX";
	}
	else if (n == 30) 
	{
		stack[top++] = "XXX";
	}
	else if (n == 40) 
	{
		stack[top++] = "XL";
	}
	else if (n == 50) 
	{
		stack[top++] = "L";
	}
	else if (n == 60) 
	{
		stack[top++] = "LX";
	}
	else if (n == 70) 
	{
		stack[top++] = "LXX";
	}
	else if (n == 80) 
	{
		stack[top++] = "LXXX";
	}
	else if (n == 90) 
	{
		stack[top++] = "XC";
	}
	else if (n == 100) 
	{
		stack[top++] = "C";
	}
	else if (n == 200) 
	{
		stack[top++] = "CC";
	}
	else if (n == 300) 
	{
		stack[top++] = "CCC";
	}
	else if (n == 400) 
	{
		stack[top++] = "CD";
	}
	else if (n == 500)
	{
		stack[top++] = "D";
	}
	else if (n == 600) 
	{
		stack[top++] = "DC";
	}
	else if (n == 700)
	{
		stack[top++] = "DCC";
	}
	else if (n == 800) 
	{
		stack[top++] = "DCCC";
	}
	else if (n == 900)
	{
		stack[top++] = "CM";
	}
	else if (n == 1000)
	{
		stack[top++] = "M";
	}
	else if (n == 2000)
	{
		stack[top++] = "MM";
	}
	else if (n == 3000)
	{
		stack[top++] = "MMM";
	}
	else if (n == 4000)
	{
		stack[top++] = "MMMM";
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
			a= a + 500;
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
		Normal(temp * g);
		printf("%c", stack[1]);
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
	for (int i =0 ; i <= top; i++)
	{
		printf("%c", stack[i]);
	}
	
	

}