#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

//C언어 소수
//N번째 소수 출력
main()
{
	int input_count;	//사용자가 입력한 숫자를 저장할 변수
	int i;				//for문을 돌기 위해 필요한 변수_1
	int j;				//for문을 돌기 위해 필요한 변수_2
	int count = 0;		//약수의 개수를 카운팅할 변수
	int prime_count = 0;//찾은 소수의 개수를 카운팅

	printf("몇번째 소수를 출력할까요? : ");
	scanf("%d", &input_count);			//사용자가 입력한 숫자를 input_count변수에 저장

	for (i = 1; i <= 9999999999; i++)		//for문_1시작, 
	{
		if (input_count == prime_count)		//사용자가 입력한 카운트와 실제 소스를 찾는 카운트가 일치하면 for문_1을 빠져나감
		{
			break;
		}

		for (j = 1; j <= i; j++)				//for문_2 시작
		{
			if (count > 2)
			{
				break;							//소수 아니면 for문_2 탈출
			}
			if (i % j == 0)
			{
				count += 1;                     //카운트 +1 증가
			}
		}										//for문_2 끝

		if (count == 2)                          //약수가 2개 뿐이면 소수라고 판단!
		{
			prime_count += 1;												//소수 카운트 증가 시킴
			printf("%d번째 소수 : %d\n", prime_count, i);                   //출력
		}
		count = 0;						  //약수 카운트를 0으로 초기화
	}

	printf("\n");


}
