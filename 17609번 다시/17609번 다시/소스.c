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
		int left = 0;
		int right = strlen(word) - 1;
		int cnt = 0;
		//printf("left==%d right ==%d\n", left, right);
		while (left <= right)
		{
			//printf("@@@@@@@@@@@@@@@\n");
			//printf("left==%d right ==%d\n", left, right);
			if (word[left] == word[right])
			{
				left++;
				right--;
				//printf("left==%d right ==%d\n", left, right);

			}
			else //ȸ���� �ƴҶ�
			{
				cnt=1;
				//printf("#####\n");
				int start = left;
				int end = right;
				start++;
				//printf("start==%d end ==%d\n", start, end);
				while(start < end)
				{
					
					if (word[start] != word[end]) // �� Ʋ�� �κ��� ã���� 
					{
						//printf("@@@\n");
						cnt++;
						break;
					}
					start++;
					end--;
				}
				//printf("cnt==%d\n", cnt);
				if (cnt == 1)
				{
					printf("1\n");
					break;
				}
				cnt = 1;
				right--;
				//printf("left==%d right ==%d cnt==%d\n", left, right,cnt);
				while (left < right)
				{

					if (word[left] != word[right]) // �� Ʋ�� �κ��� ã���� 
					{
						cnt++;
						break;
					}
					right--;
					left++;
				}
				printf("%d\n", cnt);
				break;
			}
		}
		if (cnt == 0)
		{
			printf("%d\n", cnt);

		}
		
	}
}
