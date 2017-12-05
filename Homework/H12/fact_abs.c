int fact()
{
	static int i = 5;
	if(i==0)
		return 1;
	else
	{
		i = i - 1;
		return ((i + abs(1)) * fact());
	}
}
main()
{
	printf("factor of 5=%d\n", fact());
}
