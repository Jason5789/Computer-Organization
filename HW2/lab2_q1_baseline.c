//TODO :

"li x23,16\n\t"
"addi %[lw_cnt], %[lw_cnt], 1\n\t"

"li x25,0\n\t"
"addi %[lw_cnt], %[lw_cnt], 1\n\t"

"loop1:\n\t"
	"lh x5,0(%[h])\n\t"
	"addi %[lw_cnt], %[lw_cnt], 1\n\t"
	
	"lh x6,0(%[x])\n\t"
	"addi %[lw_cnt], %[lw_cnt], 1\n\t"
	
	"add x21,x5,x6\n\t"
	"addi %[arith_cnt], %[arith_cnt], 1\n\t"

	"sh x21,0(x11)\n\t"
	"addi %[sw_cnt], %[sw_cnt], 1\n\t"
	
	"addi x25,x25,1\n\t"
	"addi %[arith_cnt], %[arith_cnt], 1\n\t"
	
	"add %[h],%[h],2\n\t"
	"addi %[arith_cnt], %[arith_cnt], 1\n\t"

	"add %[x],%[x],2\n\t"
	"addi %[arith_cnt], %[arith_cnt], 1\n\t"

	"add %[y],%[y],2\n\t"
	"addi %[arith_cnt], %[arith_cnt], 1\n\t"

	"addi %[others_cnt], %[others_cnt], 1\n\t"
	"blt x25,x23,loop1\n\t"

