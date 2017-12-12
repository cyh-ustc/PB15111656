#include <stdio.h>
typedef struct
{
	long n[2];
} stype;
extern stype k;
main()
{
	printf("%d, %d",k.n[0],k.n[1]);
}
