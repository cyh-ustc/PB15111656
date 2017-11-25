
int stack[200];
int esp=0;
int ebp=0;
int eax;

int to_push;
void push() {
	esp=esp+1;
	stack[esp]=to_push;
}

int to_pop;
void pop() {
	to_pop=stack[esp];
	esp=esp-1;
}

void prefunc() {
	to_push=ebp;
	push();
	ebp=esp;
}
void leavefunc() {
	esp=ebp;
	pop();
	ebp=to_pop;
}

/*
#include<stdio.h>
int input_var;
int output_var;
void input() {
	scanf("%d",&input_var);}
void output() {
	printf("%d ",output_var);}
*/



int arr[100],n;

void _partition() {
	prefunc();

	int beg=stack[ebp-1];
	int end=stack[ebp-2];

	int flag1=0;
	if(end-beg==1) {
		flag1=1;
	}
	if(end==beg) {
		flag1=1;
	}
	if(flag1==1) {

	} else if(end-beg==2) { // to speed up
		if(arr[beg]>arr[beg+1]) {
			int temp=arr[beg];
			arr[beg]=arr[beg+1];
			arr[beg+1]=temp;
		}
	} else {
	
		int pivot=end-1,apart=beg; // pick the last one as pivot
		int pp=arr[pivot];
		int temp;
		int i=beg;

		while(i<pivot) {
			if( arr[i]<pp ) {
				temp=arr[apart];
				arr[apart]=arr[i];
				arr[i]=temp; //swap data
				apart=apart+1;
			}
			i=i+1;
		}
		temp=arr[apart];
		arr[apart]=pp;
		arr[pivot]=temp;

		to_push=apart;
		push();
		to_push=beg;
		push();
		_partition();
		pop();pop();
		to_push=end;push();
		to_push=apart+1;push();
		_partition();
		pop();pop();
	}
	leavefunc();
}
void quick_sort() {
	to_push=n;
	push();
	to_push=0;
	push();
	_partition();
	pop();
	pop();
}

void main() {
	input();
	n=input_var;
	int i=0;
	while(i<n) {
		input();
		arr[i]=input_var;
		i=i+1;
	}
	quick_sort();
	i=0;
	while(i<n) {
		output_var=arr[i];
		output();
		i=i+1;
	}
}
