#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main()
{
	int N;
	scanf("%d", &N);
	
	for (int ii = 0; ii < N; ii++) 
	{
		char word[100005];
		scanf(" %s", word);
		int last,right;
		int cnt = 0;

		for (int i = 0; i < strlen(word) / 2; i++)
		{
			
			last = (strlen(word) - i - 1);

			printf("--------\n");
			printf("i==%d last==%d cnt==%d\n", i, last,cnt);
			if (word[i] != word[last])//회문 아닐때
			{
				if (word[i + 1] == word[last])
				{
					i++;
					cnt++;

				}
				else if (word[i] == word[last - 1])
				{

					printf("###\n");
					last--;
					cnt++;
					printf("@@@@@i==%d last==%d cnt==%d\n", i, last, cnt);
				}
				else
				{
					cnt=cnt+2;
				}

			}
		
		}
		if (cnt > 1)//2개 이상 차이가 나면 
		{
			printf("2\n");
		}
		else if (cnt == 1)
		{
			printf("1\n");
		}
		else if (cnt == 0)
		{
			printf("0\n");
		}
		
	}
}
