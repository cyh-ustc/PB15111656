#include <stdio.h>

int main()
{
	FILE *f = fopen("1.c","r");
	FILE *k;
	fclose(k);
	FILE *g = fopen("2.c","r");
	fclose(f);
	f = g + 1;
	fclose(f);
}
