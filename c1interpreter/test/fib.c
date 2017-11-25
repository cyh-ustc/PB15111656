// this program use a stack(with esp and ebp) to store argument, use eax to store return value
// a simple fib program
int stack[200];
int esp=0;
int ebp=0;
int eax;

void fib() {
	int n;
	int accu;
	
	stack[esp]=ebp;
	ebp=esp;
	esp=esp+1;
	
	n=stack[ebp-1];
	
	if(n<=2) {
		eax=1;
		esp=ebp;
		ebp=stack[ebp];
	}
	else {
		stack[esp]=n-1;
		esp=esp+1;
		fib();
		accu=eax;
		stack[esp-1]=n-2;
		fib();
		accu=accu+eax;
		eax=accu;
		esp=ebp;
		ebp=stack[ebp];
	}
}

void main() {
	//push 10 as argument
	stack[0]=10;
	esp=1;
	fib();
	output_var = eax;
	output();
}
