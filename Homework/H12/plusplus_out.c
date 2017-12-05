long i;
int main()
{
	i = 0;
	printf("%ld\n", ++i+(++i)+(++i));
	i = 0;
	printf("%ld\n", ++i+((++i)+(++i)));
}
