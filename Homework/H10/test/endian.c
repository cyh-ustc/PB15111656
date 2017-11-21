#include <stdio.h>
int main()
{
	int i = 0xaabbccdd;
	char *a = (char *)&i;
	printf("%s Endian\n",*a==0xaa?"Big":"Little");
	return 0;
}
