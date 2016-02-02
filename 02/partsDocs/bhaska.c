#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void bhaska(){
	char pedeTempo;
	float a,b,c,rd;
	system("clear");
	//
	printf("F(x) = a*x^2 + b*x + c\n");
	//
	printf("de-me a o valor de 'a':\n");
	scanf(" %f",&a);
	//
	printf("de-me a o valor de 'b':\n");
	scanf(" %f",&b);
	//
	printf("de-me a o valor de 'c':\n");
	scanf(" %f",&c);
	//
	rd = pow(b,2.0) -4.0*a*c;
	//
	if(rd >= 0){
		rd = sqrt(rd);
		printf("x1 é %f\n", (-b+rd)/2.0/a);
		printf("x2 é %f\n", (-b-rd)/2.0/a);
	}else{
		rd = sqrt(-rd);
		printf("x1 é %f + i * %f\n",-b/2/a,rd/2/a );
		printf("x2 é %f - i * %f\n",-b/2/a,rd/2/a );
	}
	printf("\nq para sain\n");
	scanf(" %c",&pedeTempo);
}
