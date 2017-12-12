#include <stdio.h>
void f(m) long m[2];
{
	printf("%d,%d\n",m[0],m[1]);
}
typedef struct
{
	long n[2];
}stype;
main()
{
	stype k;
	k.n[0] = 0;
	k.n[1] = 1;
	f(k);
}
