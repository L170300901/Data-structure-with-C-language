#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char name[21];
int oh_name[26];
int wo_name[26];
char ans[21];
int main()
{
	scanf("%s", name);
	for (int i = 0; i < strlen(name); i++)
	{
		oh_name[name[i] - 'A']++;
	}
	int n;
	scanf("%d", &n);
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		memset(wo_name, 0, sizeof(wo_name));
		memset(name, 0, sizeof(name));
		scanf("%s", name);
		for (int i = 0; i<strlen(name); i++)
		{
			wo_name[name[i] - 'A']++;
		}
		int L = (oh_name['L' - 'A'] + wo_name['L' - 'A']);
		int O = (oh_name['O' - 'A'] + wo_name['O' - 'A']);
		int V = (oh_name['V' - 'A'] + wo_name['V' - 'A']);
		int E = (oh_name['E' - 'A'] + wo_name['E' - 'A']);
		int temp = ((L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E)) % 100;
		if(i == 0)
		{
			strcpy(ans, name);
		}
		if (temp > max)
		{
			strcpy(ans, name);
			max = temp;
		}
		else if (temp == max && strcmp(ans, name) > 0)
		{
			strcpy(ans, name);
		}
	}
	printf("%s\n", ans);
	return 0;
}