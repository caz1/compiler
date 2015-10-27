#include<string.h>
#include<stdio.h>

int main()
{
	int i = 0;
	size_t len = 0;
	FILE *fp = fopen("Makefile", "r");
	char c, *str;
getline(&str, &len, fp);
	puts(str);
	return 1;
}

