#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
void Hanoi(int num, char from, char by, char to);
int main()
{
	Hanoi(3, 'A', 'B', 'C');
	return 0;
}
void Hanoi(int num, char from, char by, char to)
{
	if (num == 1)
	{
		printf("원판1을 %c에서 %c로 이동\n", from, to);
	}
	else
	{
		Hanoi(num - 1, from, to, by);
		printf("원판%d을 %c에서 %c로 이동\n", num, from, to);
		Hanoi(num - 1, by, from, to);

	}


}