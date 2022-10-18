#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char  arr[105];//문자 받는 배열 
char alphabet[26];
int position[26];
int main()
{
	scanf("%s", arr);
	for (int i = 0; i < 26; i++)
	{
		alphabet[i] = 'a' + i;
		position[i] = -1;
	}
	int j;
	for (int i = 0; i < 26; i++)
	{
		j = 0;
		while (1)
		{
			if (alphabet[i]==arr[j])
			{
				position[i] = j;
				break;

			}
			if (arr[j] == '\0')
			{
				break;
			}
			j++;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		printf("%d ", position[i]);
	}
	return 0;
}