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
	int arr[30],id=0;
	int i=2;
	while(i<=100) {
		to_test=i;
		test_prime();
		if(is_prime==1) {
			arr[id]=i;
			id=id+1;
		}
		i=i+1;
	}
	i=0;
	while(i<id) {
		output_var=arr[i];
		output();
		i=i+1;
	}
}
