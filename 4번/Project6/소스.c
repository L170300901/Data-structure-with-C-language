#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char str[200];
	char num[10][6];
	int i=0;
	int j;
	gets(str);
	int len = 0;
	len = strlen(str);
	if ('a' <= str[i] && str[i] <= 'z')
	{
		str[0] = str[0] - ('a' - 'A');
	}
	printf("%c", str[0]);
	
	for(i=1;i<len;i++)
	{
		if ('0' <= str[i] && str[i] <= '9')
		{
			switch (str[i])
			{

			    case '0':
					printf("zero");
					break;
				case '1':
					printf("one");
					break;
				case '2':
					printf("two");
					break;
				case '3':
					printf("three");
					break;
				case '4':
					printf("four");
					break;
				case '5':
					printf("five");
					break;
				case '6':
					printf("six");
					break;
				case '7':
					printf("seven");
					break;
				case '8':
					printf("eight");
					break;
				case '9':
					printf("nine");
					break;
			}
		}
		else if ('A' <= str[i] && str[i] <= 'Z')
		{
			printf("%c", str[i] + ('a' - 'A'));
		} 
		else
		{
			printf("%c", str[i]);
		}
			
	}
	return 0;

}