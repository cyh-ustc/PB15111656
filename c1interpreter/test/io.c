#include <stdio.h>
int input_var = 0, output_var = 0;
void input();
void output();

void input()
{
	scanf("%d", &input_var);
}
void output()
{
	printf("%d\n", output_var);
}
