#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

struct student
{
	int num;
	double grade;
};
int main(void)
{
	struct student s1;

	s1.num = 2;
	s1.grade = 2.7;
	printf("%d\n", s1.num);
	printf("%.1lf\n", s1.grade);
}