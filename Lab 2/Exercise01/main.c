#include<stdio.h>
#include"math_operations.h"

int main(int argc, char *argv[]){
	if(argc<3 || argc>3){
		printf("%s\n","Invalid arguments!");
		return 0;
	}
	int num1 = atoi(argv[argc-2]);
	int num2 = atoi(argv[argc-1]);
	// printf("%d",num1);
	int a = addTwoNumbers(num1,num2);
	// printf("%s\n","I was here!");
	printf("%d\n",a);
	return 0;
}
