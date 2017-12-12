#include <stdio.h>
void f(m) long m[2];
{
	printf("%d, %d\n", m[0], m[1]);
}
main()
{
	long m[2];
	m[0] = 0;
	m[1] = 1;
	f(m);
}
