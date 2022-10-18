#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
    float M=0, V=0, R=0;
	float r = 0;
	scanf("%f%f%f", &M ,& V, & R);
	r = M / V;

	if (R > r)
	{
		printf("%.2lf UP",r);
	}
	else if  (R == r)
	{
		printf("%.2lf STOP", r);
	}
	else if  (R <r)
	{
		printf("%.2lf DOWN", r);
	}
	return 0;


}