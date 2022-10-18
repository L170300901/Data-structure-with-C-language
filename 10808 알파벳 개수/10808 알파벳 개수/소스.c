#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char word[105];
int al[26];
int word2[105];
int main()
{
	int len;
	int cnt = 0;
	scanf(" %s", word);
	len = strlen(word);
	for (int i = 0; i < len; i++)
	{
		word2[i] = word[i] - 'a';
	}//문자열을 숫자로 바꾸기
	for (int i = 0; i < len; i++)
	{
		al[word2[i]]++;
	}
	for (int i = 0; i < 26; i++)
	{
		printf("%d ", al[i]);

	}
	

}