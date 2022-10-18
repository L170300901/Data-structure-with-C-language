#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char word[1000005];
int al[26];
int word2[1000005];
int main()
{
	int len;
	int cnt = 0;
	scanf(" %s", word);
	len = strlen(word);
	for (int i = 0; i < len; i++)
	{
		if ((word[i] >= 'A') && (word[i] <= 'Z'))
		{
			word[i] += ('a'-'A');
		}
	}//배열 word의 대문자를 소문자로 바꾸기 완료 
	for (int i = 0; i < len; i++)
	{
		word2[i] = word[i] - 'a';
	}//문자열을 숫자로 바꾸기
	for (int i = 0; i < len; i++)
	{
		al[word2[i]]++;
	}
	
	int max = al[0],max_idx=0;
	for (int i = 0; i < 26; i++)
	{
		if (max < al[i]) 
		{
			max = al[i];
			max_idx = i;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (cnt == 2)
		{
			printf("?");
			return 0;
		}
		if (max == al[i])
		{
			cnt++;
		}
	}	
	char worrd;
	worrd =  max_idx+ 'A';
	printf("%c", worrd);
}