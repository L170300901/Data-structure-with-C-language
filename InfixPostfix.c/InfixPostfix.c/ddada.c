#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str[100]; 
double stack[100];
int top = -1;

int main(void)
{
	scanf(" %s", str);//후위표기식 입력받을꺼
	int len = strlen(str);
	char tok;
	for (int i = 0; i < len; i++) {
		tok = str[i];
		if ('1' <= tok && tok <= '9')//isdigit(tok)
			stack[++top] = tok - '0';
		else {//연산자일때
			double num2 = stack[top--];
			double num1 = stack[top--];

			switch (tok) {
				case '+':
					stack[++top] = num1 + num2;
					break;
				case '-':
					stack[++top] = num1 - num2;
					break;
				case '*':
					stack[++top] = num1 * num2;
					break;
				case '/':
					stack[++top] = num1 / num2;
					break;
			}
		}
	}

	printf("%.1lf", stack[top]);
	return 0;
}