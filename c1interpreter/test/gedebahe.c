int to_test;
int is_prime;

void test_prime() {
	int i=2;
	is_prime=1;
	while( i<to_test) {
		if( to_test%i == 0) {
			is_prime=0;
		}
		i=i+1;
	}
}
void main() {
	int i=6,flag;
	while( i<=100 ) {
		int j=3;
		flag=0;
		while( j<= i/2 ) {
			to_test=j;
			test_prime();
			int first=is_prime;
			to_test=i-j;
			test_prime();
			is_prime=is_prime*first;
			if(is_prime==1) {
				if(flag==0) {
					output_var=j;
					output();
					output_var=i-j;
					output();
					flag=1;
				}
			}
			j=j+2;
		}
		i=i+2;
	}	
}
