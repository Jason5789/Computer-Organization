// description: matrix muliply without for loop
#include<stdio.h>
int main()
{
	 int i=0;
	 int h[9]={0}, x[3]={0}, y[3]={0};
	 FILE *input = fopen("../input/4.txt","r");
	 
	 for(i = 0; i<9; i++) fscanf(input, "%d", &h[i]);
	 for(i = 0; i<3; i++) fscanf(input, "%d", &x[i]);
	 for(i = 0; i<3; i++) fscanf(input, "%d", &y[i]);
	 fclose(input);
	 
	 int *p_x = &x[0] ;
	 int *p_h = &h[0] ;
	 int *p_y = &y[0] ;
	 
	 asm volatile(
		"li x26,12\n\t"
		"li x27,4\n\t"
		"li x22,0\n\t"
		"li x23,3\n\t"
		"li x24,0\n\t"
		"li x25,0\n\t"
		"add x9,%[p_h],x22\n\t"
		"add x10,%[p_x],x22\n\t"
		"add x11,%[p_y],x22\n\t"
	"loop1:\n\t"
		"sub x25,x26,x26\n\t"
	"loop2:\n\t"
		"lw x6,0(x9)\n\t"
		"lw x5,0(x10)\n\t"
		"lw x7,0(x11)\n\t"
		"mul x20,x5,x6\n\t"
		"add x21,x20,x7\n\t"
		"sd x21,0(x11)\n\t"
		"addi x25,x25,1\n\t"
		"add x9,x9,x27\n\t"
		"add x10,x10,x27\n\t"
		"blt x25,x23,loop2\n\t"
		
		"addi x24,x24,1\n\t"
		"sub x10,x10,x26\n\t"
		"add x11,x11,x27\n\t"
		"blt x24,x23,loop1\n\t"
		:
		:[p_x] "r"(p_x),[p_y] "r"(p_y),[p_h] "r"(p_h)
	 );
	 
	 p_y = &y[0];
	 for(i = 0; i<3; i++)
	 printf("%d \n", *p_y++);
	 
	 return(0) ;

}
