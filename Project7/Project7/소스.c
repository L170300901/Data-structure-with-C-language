#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

//C��� �Ҽ�
//N��° �Ҽ� ���
main()
{
	int input_count;	//����ڰ� �Է��� ���ڸ� ������ ����
	int i;				//for���� ���� ���� �ʿ��� ����_1
	int j;				//for���� ���� ���� �ʿ��� ����_2
	int count = 0;		//����� ������ ī������ ����
	int prime_count = 0;//ã�� �Ҽ��� ������ ī����

	printf("���° �Ҽ��� ����ұ��? : ");
	scanf("%d", &input_count);			//����ڰ� �Է��� ���ڸ� input_count������ ����

	for (i = 1; i <= 9999999999; i++)		//for��_1����, 
	{
		if (input_count == prime_count)		//����ڰ� �Է��� ī��Ʈ�� ���� �ҽ��� ã�� ī��Ʈ�� ��ġ�ϸ� for��_1�� ��������
		{
			break;
		}

		for (j = 1; j <= i; j++)				//for��_2 ����
		{
			if (count > 2)
			{
				break;							//�Ҽ� �ƴϸ� for��_2 Ż��
			}
			if (i % j == 0)
			{
				count += 1;                     //ī��Ʈ +1 ����
			}
		}										//for��_2 ��

		if (count == 2)                          //����� 2�� ���̸� �Ҽ���� �Ǵ�!
		{
			prime_count += 1;												//�Ҽ� ī��Ʈ ���� ��Ŵ
			printf("%d��° �Ҽ� : %d\n", prime_count, i);                   //���
		}
		count = 0;						  //��� ī��Ʈ�� 0���� �ʱ�ȭ
	}

	printf("\n");


}
