#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int al[26];
char word[105];
int sum = 0;
int check;
int main()
{
	int N,len=0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		check = 0;
		for (int i = 0; i < 26; i++)
		{
			al[i] = 0;
		}
		scanf("%s", word);
		len = strlen(word);
		for (int j = 0; j < len; j++)
		{
			if (j == 0)
			{
				al[word[j] - 'a'] = 1;
			}
			else
			{
				if (word[j - 1] != word[j])//다른 문자가 나왔을때 
				{
					if (al[word[j] - 'a'] == 1)
					{
						check = 1;
						break;
					}
					else
					{
						al[word[j] - 'a'] = 1;
					}
				}
			}
		}
		if (check == 0)
		{
			sum++;
		}
	
	}
	printf("%d", sum);
	return 0;
}