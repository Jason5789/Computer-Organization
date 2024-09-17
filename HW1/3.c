// description: matrix muliply with two-level for loop
#include<stdio.h>
int main()
{
	 int f,i=0;
	 int h[9]={0}, x[3]={0}, y[3]={0};
	 FILE *input = fopen("../input/3.txt","r");
	 for(i = 0; i<9; i++) fscanf(input, "%d", &h[i]);
	 for(i = 0; i<3; i++) fscanf(input, "%d", &x[i]);
	 for(i = 0; i<3; i++) fscanf(input, "%d", &y[i]);
	 fclose(input);
	 int *p_x = &x[0] ;
	 int *p_h = &h[0] ;
	 int *p_y = &y[0] ;

	 for (i = 0 ; i < 3; i++)
	 {
		 p_x = &x[0] ;
		 for (f = 0 ; f < 3; f++)
			asm volatile(
				"li x26,12\n\t"
				"li x27,4\n\t"
				"mul x28,%[f],x27\n\t"
				"mul x29,%[i],x27\n\t"
				"mul x30,%[i],x26\n\t"
				"add x31,x28,x30\n\t"
				"add x9,%[p_h],x31\n\t"
				"add x10,%[p_x],x28\n\t"
				"add x11,%[p_y],x29\n\t"
				"lw x6,0(x9)\n\t"
	 			"lw x5,0(x10)\n\t"
	 			"lw x7,0(x11)\n\t"
	 			"mul x20,x5,x6\n\t"
	 			"add x21,x20,x7\n\t"
				"sd x21,0(x11)\n\t"
				:
				:[x] "r"(x),[h] "r"(h),[y] "r"(y),[i] "r"(i),[p_x] "r"(p_x),[p_y] "r"(p_y),[p_h] "r"(p_h),[f] "r"(f)
			);
	 }
	 p_y = &y[0];
	 for(i = 0; i<3; i++)
	 printf("%d \n", *p_y++);
	 return(0) ;

}
